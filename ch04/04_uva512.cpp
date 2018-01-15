#include<cstdio>
#include<cstring>
#define max 51
int sheets[max][max] = {0};
int r, c;
char type[2];
int exCount = 0;
int ex[100000];

void setUp(){
    for(int i = 1; i <= r; i++){ sheets[i][0] = i; }
    for(int i = 1; i <= c; i++){ sheets[0][i] = i; }
    exCount = 0;
}

void del(){
    int len;
    scanf("%d", &len);
    for(int i = 0; i < len; i++){
        int num;
        scanf("%d", &num);
        int j = 1;
        if(type[1] == 'R'){
            for(; j <= r && sheets[j][0] < num; j++);
            if(sheets[j][0] == num){ sheets[j][0] = 0; j++;}
            for(; j <= r; j++){ if(sheets[j][0] != 0) sheets[j][0]--; }
        } else if(type[1] == 'C'){
            for(; j <= c && sheets[0][j] < num; j++);
            if(sheets[0][j] == num){ sheets[0][j] = 0; j++;}
            for(; j <= c; j++){ if(sheets[0][j] != 0) sheets[0][j]--; }
        }
    }
}

void insert(){
    int len;
    scanf("%d", &len);
    for(int i = 0; i < len; i++){
        int num;
        scanf("%d", &num);
        int j = 1;
        if(type[1] == 'R'){
            for(; j <= r && sheets[j][0] < num; j++);
            for(; j <= r; j++){ if(sheets[j][0] != 0) sheets[j][0]++; }
        }else if(type[1] == 'C'){
            for(; j <= c && sheets[0][j] < num; j++);
            for(; j <= c; j++){ if(sheets[0][j] != 0) sheets[0][j]++; }
        }
    }
}

void exchange(){
    int c1, r1, c2, r2;
    scanf("%d%d%d%d", &c1, &r1, &c2, &r2);
    ex[exCount++] = (c1-1)*c + r1;
    ex[exCount++] = (c2-1)*c + r2;
}

int main(){
    for(;;){
        scanf("%d%d", &r, &c);
        if(r == 0 && c == 0)    break;

        setUp();

        int operNum;
        scanf("%d", &operNum);
        for(int i = 0; i < operNum; i++){
            scanf("%s", &type);
            if(type[0] == 'D'){ del(); }
            else if(type[0] == 'I'){ insert(); }
            else { exchange(); }
        }
        
        int trackNum;
        scanf("%d", &trackNum);
        for(int i = 0; i < trackNum; i++){
            int a, b;
            scanf("%d%d", &a, &b);
        }
    }
}