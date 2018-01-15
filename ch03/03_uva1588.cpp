#include<cstdio>
#include<cstring>
#define max 100
char l[max], r[max];
char *a = 0, *b = 0;
int lena = 0, lenb = 0;
int count[max];
int co = 0;

void swap(int &a, int &b){
    int c = a;
    a = b; 
    b = c;
}

bool match(int start){
    int end = lena;
    bool m = true;
    for(int i = 0; i < co; i++){
        int pos = start + count[i];
        if(pos < 0 || pos >= lenb)  continue;
        if(b[pos] == '2')m = false;
    }
    return m;
}

int main(){
    for(;;){
        if(scanf("%s%s", &l, &r) == EOF) break;
        lena = strlen(l);
        lenb = strlen(r);
        a = l; b = r;
        if(lena > lenb){
            swap(lena, lenb);
            a = r; b = l;
        }

        for(int i = 0; i< max;i++)count[i] = 0;
        co = 0;
        for(int i = 0; i < lena; i++){
            if(a[i] == '2') count[co++]=i;
        }

        int len = lenb - lena + 1;
        int i = 0;
        for(i = 0; i< len && !match(i); i++);
        if(i < len){   printf("%d\n", lenb); continue;}
        for(i = 1; i < lena && !match(-i) && !match(len + i - 1); i++);
        printf("%d\n", lenb+i);
    }
}
