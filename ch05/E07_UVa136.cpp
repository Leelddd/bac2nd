#include<cstdio>
#include<cstdlib>
#include<string>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include <set>

#define ll long long
using namespace std;

int main() {

    set<long long> uglynum = {1};
    priority_queue<ll, vector<ll>, greater<ll>> q;
    int multi[3] = {2, 3, 5};
    q.push(1);

    for (int i = 1;; i++) {
        ll base = q.top();
        q.pop();
        if (i == 1500) {
            cout << "The 1500'th ugly number is " << base << "." << endl;
            return 0;
        }
        for (int &i: multi) {
            ll num = base * i;

            if (!uglynum.count(num)) {
                q.push(num);
                uglynum.insert(num);
            }
        }
    }
}