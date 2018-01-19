#include <cstdlib>
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <iomanip>
#include <fstream>

#define cout of
#define cin in

using namespace std;

int N;
double price, percentage[70];
int playerNum;
map<int, int> total2num;

struct Player {
    string name;
    bool amateur = false;
    int score[4] = {-1, -1, -1, -1};
    int quitRound = 5;
    int score36, score72;
    int tie = 0;

    void setScore(string &line) {
        for (int i = 0; i < 4; i++) {
            int base = 20 + i * 3;
            setonescore(line.substr(base, base + 3), i);
            if (quitRound != 5) break;
        }
        if (quitRound > 1) score36 = score[0] + score[1];
        if (quitRound > 3) score72 = score36 + score[2] + score[3];
        if (quitRound == 2) score72 = score36;
        else if (quitRound == 3) score72 = score36 + score[2];
    }

    void setonescore(string s, int i) {
        if (s[1] == 'D') {
            quitRound = i;
        } else {
            score[i] = atoi(s.c_str());
        }
    }

    friend istream &operator>>(istream &in, Player &player) {
        string line;
        getline(in, line);
        player.name = line.substr(0, 20);
        if (player.name[player.name.find_last_not_of(' ')] == '*') player.amateur = true;
        player.setScore(line);
    }
};

bool cutCompare(const Player &a, const Player &b) {
    if ((a.quitRound < 2) == (b.quitRound < 2))
        return a.score36 < b.score36;
    else return a.quitRound >= 2;
}

bool comp(const Player &a, const Player &b) {
    if (a.quitRound == 5 && b.quitRound == 5) {
        if (a.score72 == b.score72)return a.name < b.name;
        else return a.score72 < b.score72;
    } else if (a.quitRound == b.quitRound) {
        if (a.score72 == b.score72) return a.name < b.name;
        else return a.score72 < b.score72;
    } else {
        return a.quitRound > b.quitRound;
    }
}


int main() {
    ifstream in("in.txt");
    cin >> N;
    ofstream of("out.txt");
    while (N--) {
        string buf;
        getline(cin, buf);
        cin >> price;
        for (double &i : percentage) cin >> i;
        cin >> playerNum;
        getline(cin, buf);
        Player player[500];
        for (int i = 0; i < playerNum; i++) cin >> player[i];
        sort(begin(player), begin(player) + playerNum, cutCompare);

        cout << "Player Name          " << "Place     " << "RD1  "
             << "RD2  " << "RD3  " << "RD4  " << "TOTAL     " << "Money Won" << endl;
        cout << "-----------------------------------------------------------------------" << endl;

        int cutNum = 0;
        for (int i = 0; i < playerNum; i++) {
            if (player[i].quitRound < 2) {
                cutNum = i;
                break;
            }
            if (player[i].amateur || player[i].quitRound != 5) continue;
            if (total2num.count(player[i].score72)) total2num[player[i].score72]++;
            else total2num[player[i].score72] = 0;
        }

        sort(begin(player), begin(player) + cutNum, comp);
        for (int i = 0; i < cutNum; i++) {
            player[i].tie = total2num[player[i].score72];
        }

        int lastTie = 0;
        int index = 0, moneyIndex = 0, trueIndex = 0;
        string indexout;
        for (int i = 0; i < cutNum; i++) {
            cout << player[i].name << " ";

            if (player[i].quitRound < 4) {
                cout << "          ";
            } else {
                trueIndex++;
                if (player[i].tie) {
                    if (player[i].score72 != lastTie) {
                        index = trueIndex;
                        indexout = to_string(index) + "T";
                    } else {
                        indexout = to_string(index) + "T";
                    }
                } else {
                    if (i > 0 && player[i].score72 == player[i - 1].score72) { ;
                    } else {
                        index = trueIndex;
                    }
                    indexout = to_string(trueIndex) + "";
                }
                cout << left << setw(10) << indexout;
                lastTie = player[i].score72;
            }

            for (int &sc: player[i].score) {
                if (sc == -1) cout << "     ";
                else
                    cout << sc << "   ";
            }

            if (player[i].amateur || player[i].quitRound != 5) {
                if (player[i].quitRound < 4) {
                    cout << "DQ";
                } else {
                    cout << player[i].score72;
//                if (player[i].score72 / 100 == 0) cout << " ";
                }
            }


            if (!player[i].amateur && player[i].quitRound == 5) {
                if (player[i].quitRound < 4) {
                    cout << left << setw(10) << "DQ";
                } else {
                    cout << left << setw(10) << player[i].score72;
//                if (player[i].score72 / 100 == 0) cout << " ";
                }
                cout << "$";
                int count = player[i].tie + 1;
                double total = 0;
                for (int j = 0; j < count; j++) {
                    total += percentage[moneyIndex + j];
                }
                cout << right
                     << setiosflags(ios::fixed)
                     << setprecision(2) << std::setw(9)
                     << price * total / 100 / count;
                if (i < cutNum - 1 && player[i + 1].score72 != player[i].score72)
                    moneyIndex += count;
            }
            cout << endl;
        }
        cout << endl;
        total2num.clear();
    }
}