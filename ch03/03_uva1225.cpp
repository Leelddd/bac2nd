#include<cstdio>
#include<cstdlib>
#include<cstring>
int count[10];

void setCount(int num){
    char s[8];
    sprintf(s, "%d", num);
    int length = strlen(s);
    for(int i = 0; i < length; i++){
        count[s[i]-'0']++;
    }
}

int main(){
    int total = 0;
    scanf("%d", &total);
    for(int i = 0; i < total; i++){
        int num = 0;
        scanf("%d", &num);
        for(int i = 0; i < 10; i++) count[i]=0;
        for(int i = 0; i < num; i++) setCount(i+1);            
        for(int i = 0; i < 9; i++)
            printf("%d ",count[i]);
        printf("%d\n",count[9]);
    }
}