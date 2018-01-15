#include<cstdio>
#include<cstring>
#define max 100000
char str[max];
char encry[max];

int main(){
    while((scanf("%s", &str)) != EOF){
        scanf("%s", &encry);
        int len = strlen(encry);
        if(len < strlen(str)){
            printf("No\n");
            continue;
        }
        int index = 0;
        for(int i = 0; i < len; i++){
            if(encry[i] == str[index]) index++;
        }
        if(index == strlen(str))    printf("Yes\n");
        else printf("No\n");
    }
}
// 5min