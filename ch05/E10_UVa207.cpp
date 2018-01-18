#include <cstdlib>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int N;
float price, percentage[70];
int playerNum;

struct Player {
    string name;
    bool amateur = false;
    int score[4] = {-1, -1, -1, -1};
    int quitRound = 5;
    int score36, score72;

    void setScore(string &line) {
        for (int i = 0; i < 4; i++) {
            int base = 20 + i * 3;
            setonescore(line.substr(base, base + 3), i);
            if (quitRound != 5) break;
        }
        if (quitRound > 1) score36 = score[0] + score[1];
        else if (quitRound > 3) score72 = score36 + score[2] + score[3];
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


int main() {
    cin >> N;
    while (N--) {
        string buf;
        getline(cin, buf);
        cin >> price;
        for (float &i : percentage) cin >> i;
        cin >> playerNum;
        getline(cin, buf);
        Player player[150];
        for (int i = 0; i < playerNum; i++) cin >> player[i];
        sort(begin(player), end(player), cutCompare);
        cout << endl;
    }
}