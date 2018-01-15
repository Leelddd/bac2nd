#include<cstdio>
#include<cstring>
char s[80];
int length = 0;
int pos = 0;

bool match(int base){
    for(int i = base; i < length; i+=base){
        for(int j = 0; j< base;j++){
            if(s[j] != s[i+j]) return false;
        }
    }
    return true;
}

int main(){
    int total = 0;
    scanf("%d", &total);
    char line[1];
    // gets(line);
    for(int i = 0; i < total; i++){
        // gets(line);
        scanf("%s", &s);
        length = strlen(s);
        int len = length / 2+1;
        bool one = true;
        for(int i = 1; i < len; i++){
            if(length%i==0 && match(i)){
                one = false;
                printf("%d\n", i);
                break;
            }
        }
        if(one) printf("%d\n", length);
        if(i<total-1)printf("\n");
    }
}