#include<cstdio>
#include<vector>
#include<string>
#include<iostream>
#include<algorithm>

using namespace std;

int n, from, to;
string command1, command2;
vector<int> stacks[30];
int pf, pt;
int position[30];
vector<int>::iterator spf, spt;

void restore(vector<int> &stack, vector<int>::iterator &pos) {
    for (auto i = pos + 1; i != stack.end(); i++) {
        stacks[*i].push_back(*i);
        position[*i] = *i;
    }
    stack.erase(pos + 1, stack.end());
}

void put_one(vector<int> &sf, vector<int> &st) {
    sf.pop_back();
    st.push_back(from);
    position[from] = pt;
}

void put_all(vector<int> &sf, vector<int> &st) {
    for (auto i = spf; i != sf.end(); i++) position[*i] = pt;
    st.insert(st.end(), spf, sf.end());
    sf.erase(spf, sf.end());
}

vector<int>::iterator find_pos(int pos, int index) {
    return find(stacks[pos].begin(), stacks[pos].end(), index);
}

int main() {

    cin >> n;
    for (int i = 0; i < n; i++) {
        stacks[i].push_back(i);
        position[i] = i;
    }

    while (cin >> command1 >> from >> command2 >> to) {
        if (command1 == "quit")break;

        if (position[from] == position[to]) continue;
        pf = position[from], pt = position[to];
        vector<int> &sf = stacks[pf];
        vector<int> &st = stacks[pt];
        spf = find_pos(pf, from);
        spt = find_pos(pt, to);

        if (command1 == "move") restore(sf, spf);
        if (command2 == "onto") restore(st, spt);

        if(command1 == "move")  put_one(sf, st);
        if(command1 == "pile")  put_all(sf, st);
    }

    for (int i = 0; i < n; i++) {
        cout << i << ":";
        for (auto &in: stacks[i]) {
            cout << " " << in;
        }
        cout << endl;
    }

}