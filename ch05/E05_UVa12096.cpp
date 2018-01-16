#include<cstdio>
#include<cstdlib>
#include<string>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<set>
#include<map>

using namespace std;

stack<set<int>> s;
int id = 0;
set<int> emptyset;
set<int> t1, t2;
map<set<int>, int> set2id;

void top2pop() {
    t1 = s.top();
    s.pop();
    t2 = s.top();
    s.pop();
}

void pushAndFind(set<int> set1) {
    if (!set2id.count(set1)) set2id[set1] = id++;
    s.push(set1);
}

void push() {
    pushAndFind(set<int>());
}

void dup() {
    s.push(s.top());
}

void _union() {
    t1.insert(t2.begin(), t2.end());
    pushAndFind(t1);
}

void intersect() {
    set<int> set1;
    set_intersection(t1.begin(), t1.end(), t2.begin(), t2.end(), inserter(set1, set1.begin()));
    pushAndFind(set1);
}

void add() {
    t2.insert(set2id[t1]);
    pushAndFind(t2);
}

int main() {
    int N, test;
    string oper;
    cin >> N;
    while (N--) {
        cin >> test;
        while (test--) {
            cin >> oper;
            if (oper == "PUSH") push();
            else if (oper == "DUP") dup();
            else {
                top2pop();
                if (oper == "UNION") _union();
                else if (oper == "INTERSECT") intersect();
                else if (oper == "ADD") add();
            }
            cout << s.top().size() << "\n";
        }
        cout << "***" << "\n";
    }
}