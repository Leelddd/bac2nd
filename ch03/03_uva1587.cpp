#include<cstdio>
int arr[6][2];
int count[6] = {0};

void swap(int &a, int &b){
    if(a >= b) return;
    int c = a; a = b; b = c;
}

bool equal(int line, int x, int y){
    return (arr[line][0] == x) && (arr[line][1] == y);
}

bool fix(int sec, int thi){
    return (arr[0][0] == arr[1][sec] && arr[0][1] == arr[2][thi] && arr[1][!sec] == arr[2][!thi])
    || (arr[0][0] == arr[2][thi] && arr[0][1] == arr[1][sec] && arr[1][!sec] == arr[2][!thi]);
}

int main(){
    int a = 0, b = 0;
    for(;;){
        for(int i = 0; i < 6;i++) count[i] = 0;
        int index = 0;
        for(int i =0;i<6;i++)
            for(int j = 0;j<2;j++)
                arr[i][j]=0;
        for(int i = 0; i < 6;i++){
            if(scanf("%d%d", &a, &b) == EOF)    return 0;
            swap(a, b);

            int j = 0;
            for(; j < i && !equal(j, a, b); j++);
            if(j < i){
                count[j] = !count[j];
                if(count[j]) continue;
            }
            arr[index][0] = a;
            arr[index++][1] = b;
        }
        if(index >3){printf("IMPOSSIBLE\n");continue;}
        if(fix(0, 0) || fix(0, 1) || fix(1, 0) || fix(1, 1))    printf("POSSIBLE\n");
        else printf("IMPOSSIBLE\n");
    }

}