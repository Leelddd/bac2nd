#include<cstdio>
#include<cstring>
#include<algorithm>
using std::sort;

char a[100];
char b[100];
int lena = 0;
int lenb = 0;
int counta[26] = {0};
int countb[26] = {0};
int ana[26] = {0};
int anb[26] = {0};

void count(char *arr, int len, int *carr){
    for(int i = 0;i < len;i++){ carr[arr[i]-'A']++; }
}

void analyze(int *count){
    sort(count, count + 26);
}

int main(){
    while(scanf("%s%s", &a, &b) != EOF){
        lena = strlen(a);
        lenb = strlen(b);
        count(a, lena, counta);
        count(b, lenb, countb);
        analyze(counta);
        analyze(countb);
        int i = 0;
        for(; i < 26 && ana[i] == anb[i]; i++);
        if (i < 26) printf("NO\n");
        else printf("YES\n");
    }
}