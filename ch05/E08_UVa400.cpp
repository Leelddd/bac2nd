#include<cstdio>
#include<cstdlib>
#include<string>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

void print(const string &s, const int &max) {
    cout << s;
    for (int i = s.length(); i < max; i++) {
        cout << ' ';
    }
}

int main() {
    int N;

    while (cin >> N) {
        string name;
        vector<string> names;
        int maxlength = 0;
        while (N--) {
            cin >> name;
            names.push_back(name);
            if (name.length() > maxlength) maxlength = name.length();
        }
        sort(names.begin(), names.end());

        int column = 62 / (maxlength + 2);
        int len = names.size() % column ? names.size() / column + 1 : names.size() / column;
        cout << "------------------------------------------------------------" << endl;
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < column; j++) {
                int pos = j * len + i;
                if (pos >= names.size())continue;
                else if ((j + 1) * len + i >= names.size())
                    print(names[pos], maxlength);
                else
                    print(names[pos], maxlength + 2);
            }
            cout << endl;
        }
    }
}