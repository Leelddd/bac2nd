#include<cstdio>
#include<cstdlib>
#include<cstring>
char buf[100];
char num[15];
char exp[10];
int len = 0;
char binexp[30];

int main(){
    while((scanf("%s", num))!=EOF){
        len = strlen(num);
        int i = 0;
        for(i = 0; i < 15; i++) num[i] = buf[i];
        for(i = 16; i < len; i++) exp[i-16] = buf[i];
        int dev = 1;
        int expnum = atoi(exp);
        int index = 0;
        for(i = 0; i < expnum; i++){
            for(dev = dev * 10; dev > 0; dev /= 2){
                binexp[index++] = dev % 2;
            }
        }
    }
}