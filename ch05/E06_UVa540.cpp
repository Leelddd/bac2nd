#include<cstdio>
#include<cstdlib>
#include<string>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include <deque>


using namespace std;

int teamID = 0;
map<int, int> person2team;
deque<int> q, team2queue[1010];

bool team(int &a, int &b) {
    return person2team[a] == person2team[b];
}

void enqueue() {
    int in;
    cin >> in;
    int teamId = person2team[in];
    if (team2queue[teamId].empty()) {
        q.push_back(in);
    }
    team2queue[teamId].push_back(in);
}

void dequeue() {
    int id = person2team[q.front()];
    cout << team2queue[id].front() << endl;
    team2queue[id].pop_front();
    if (team2queue[id].empty()) q.pop_front();
}


int main() {
    int TEAM, NUM, member, count = 1;
    string oper;
    while (cin >> TEAM) {
        if (TEAM == 0) break;
        cout << "Scenario #" << count++ << endl;

        while (TEAM--) {
            cin >> NUM;
            teamID++;
            while (NUM--) {
                cin >> member;
                person2team.insert(make_pair(member, teamID));
            }
        }

        while (cin >> oper) {
            if (oper[0] == 'E') enqueue();
            else if (oper[0] == 'D') dequeue();
            else if (oper[0] == 'S') break;
        }

        person2team.clear();
        q.clear();
        for (deque<int> &d: team2queue) {
            d.clear();
        }
        teamID = 0;
        cout << endl;
    }
}