#include<cstdio>
#include<algorithm>
using namespace std;

int marbles[100000];
int num = 0, qnum = 0, index = 0;

int main()
{
    while(scanf("%d%d", &num, &qnum) == 2 && num)
    {
        printf("CASE# %d:\n", ++index);
        for(int i = 0; i < num; i++)    scanf("%d", &marbles[i]);
        sort(marbles, marbles + num);
        while(qnum--)
        {
            int q = 0;
            scanf("%d", &q);
            int pos = lower_bound(marbles, marbles + num, q) - marbles;
            if(marbles[pos] == q)   printf("%d found at %d\n", q, pos + 1);
            else printf("%d not found\n", q);

        }
    }
    return 0;
}