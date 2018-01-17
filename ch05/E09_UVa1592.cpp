#include<cstdio>
#include<cstdlib>
#include<string>
#include<iostream>
#include<algorithm>
#include<vector>
#include <map>
#include <sstream>

using namespace std;

void find() {

}

int main() {
    int n, m, id = 0;
    int count = 0;
    while (cin >> n >> m) {
        bool find = true;
        map<string, int> strID;
        int rows[10001][11];
        string buf;
        getline(cin, buf);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (j < m - 1)getline(cin, buf, ',');
                else getline(cin, buf);
                if (!strID.count(buf)) strID[buf] = id++;
                rows[i][j] = strID[buf];
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < m; j++) {
                map<pair<int, int>, int> col2row;
                for (int k = 0; k < n; k++) {
                    pair<int, int> p = make_pair(rows[k][i], rows[k][j]);
                    if (col2row.count(p)) {
                        cout << "NO" << endl;
                        cout << col2row[p] + 1 << " " << k + 1 << endl;
                        cout << i + 1 << " " << j + 1 << endl;
                        find = false;
                        i = m, j = m;
                        break;
                    } else {
                        col2row[p] = k;
                    }
                }
            }
        }
        if (find)
            cout << "YES" << endl;
    }
}