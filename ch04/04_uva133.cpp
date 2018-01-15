#include<cstdio>
int n, k, m;
int count;
int arr[20];

int position(int pos){
    return (pos%n)>=0?pos%n:(pos%n)+n;
}

int select(int pos, int step, int vector){
    while(step != 0){
        if(arr[position(pos)]==1)   step--;
        pos+=vector;
    }
    return position(pos-vector);
}

void format(int num){
    if((num+1) / 10 > 0) printf(" ");
    else printf("  ");
    printf("%d", num+1);
    count++;
    arr[num]=0;
}

int main(){
    while(scanf("%d%d%d", &n, &k, &m) == 3 && n){
        // read and setup
        for(int i = 0; i < 20; i++)arr[i] = 1;

        count = 0;
        int a = 0, b = n-1;
        while(count < n){
            a = select(a, k, 1);
            b = select(b, m, -1);
            format(a);
            if(a != b){ format(b); }
            if(count < n)   printf(",");
        }
        printf("\n");
    }
}