#include<cstdio>
#include<cstdlib>
#include<string>
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<sstream>

using namespace std;

int main() {
    set<string> dict;
    string s, buf;
    while (cin >> s) {
        for (int i = 0; i < s.length(); i++) {
            s[i] = isalpha(s[i]) ? tolower(s[i]) : ' ';
        }
        stringstream ss(s);
        while (ss >> buf) dict.insert(buf);
    }

    for (auto it: dict) {
        cout << it << "\n";
    }
    return 0;
}