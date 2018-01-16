#include<cstdio>
#include<cstdlib>
#include<string>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

string stdString(string result) {
    for (char &i : result) {
        i = tolower(i);
    }
    sort(result.begin(), result.end());
    return result;
}

int main() {
    string s;
    map<string, int> cntMap;
    vector<string> words;
    while (cin >> s) {
        if (s == "#") break;
        words.push_back(s);
        string rs = stdString(s);
        if (cntMap.count(rs) == 0) cntMap[rs] = 0;
        cntMap[rs]++;
    }

    vector<string> out;
    for (auto &w: words) {
        if (cntMap[stdString(w)] == 1) out.push_back(w);
    }
    sort(out.begin(), out.end());
    for (string &s: out) {
        cout << s << "\n";
    }
    return 0;
}