#include<cstdio>
#define maxm 50
#define maxn 1000
char arr[maxm][maxn];
char best[maxn];
int bestCount = 0;
int count[maxn][4];
char seq[4] = {'A', 'C', 'G', 'T'};
int m = 0, n = 0;

void setCount(char val, int j){
    switch(val){
        case 'A':
            count[j][0]++;
            break;
        case 'C':
            count[j][1]++;
            break;
        case 'G':
            count[j][2]++;
            break;
        case 'T':
            count[j][3]++;
            break;
        default:
            break;
    }
}

char max(int j){
    int pos = 0;
    for(int i =1;i<4;i++){
        if(count[j][i] > count[j][pos])pos = i;
    }
    bestCount += (m - count[j][pos]);
    return seq[pos];
}

int main(){
    int T = 0;
    scanf("%d", &T);
    for(int i = 0; i < T; i++){
        scanf("%d%d", &m, &n);
        for(int i = 0; i < m; i++){
            scanf("%s", &arr[i]);
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 4; j++)
                count[i][j] = 0;
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                setCount(arr[i][j], j);
            }
        }
        bestCount = 0;
        for(int i = 0; i < n;i++){
            best[i] = max(i);
        }
        for(int i = 0; i < n; i++){
            printf("%c", best[i]);
        }
        printf("\n%d\n",bestCount);
    }
}
// 37min