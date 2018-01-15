#include <cstdio>
char arr[3000];
int left = 0;
int pos[3000] = {0};
int check[3000] = {0};
int begin = 0, end = 0;

bool find(int num, int max){
    if(check[num]){
        int i = 0;
        for(; i < max && pos[i] != num; i++);
        begin = i;
        end = max;
    }
    return check[num];
}

void empty(){
    for(int i = 0; i < 3000; i++){
        pos[i] = 0;
        check[i] = 0;
    }
}

int main(){
    char b = '0';
    int num = 0, de = 0;
    while((scanf("%d", &num)) != EOF){
        int numbuf = num;
        scanf("%d", &de);
        left = num / de;
        empty();
        for(int i = 0; i < 3000;i++){
            num = num % de;
            if(find(num, i))   break;            
            check[num] = 1;
            pos[i]=num;
            arr[i] = b + (num*10)/de;
            num = num * 10;
        }
        printf("%d/%d = %d.", numbuf, de, left);
        for(int i =0;i<begin;i++)printf("%c",arr[i]);
        printf("(");
        for(int i = begin; i< end && i < 50;i++)printf("%c", arr[i]);
        if(end > 50)printf("...");
        printf(")\n");
        printf("   %d = number of digits in repeating cycle\n\n", end-begin);
    }
}
//80 min