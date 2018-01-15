#include<cstdio>
#include<cstring>

char map[10][1000];
char str[100];

int b2i(char *b, int pos, int len){
    int result = 0;
    for(int i = 0; i < len; i++){
        result += (b[pos+i] - '0' << (len-1-i));
    }
    return result;
}

bool end(char *arr, int l){
    for(int i = 0;i < l; i++){
        if(arr[i] == '0')   return false;
    }
    return true;
}

char readchar(){
    char c = getchar();
    while(c == '\n' || c == '\r'){ c = getchar(); }
    return c;
}

char* readstr(int len){
    for(int i = 0; i < len; i++){
        str[i] = readchar();
    }
    return str;
}

int main(){
    for(;;){
        int len = 1, value = 0;
        char c = getchar();
        if(c == EOF){return 0;}
        while(c != '\n' && c != '\r'){
            map[len][value++] = c;
            if(value>=(1<<len)-1){ len++; value=0;}
            c = getchar();
        }
        for(;;){
            int l = b2i(readstr(3), 0, 3);
            if(l == 0)  break;
            for(;;){
                char *carr = readstr(l);
                if(end(carr, l)){break;}
                printf("%c", map[l][b2i(carr, 0, l)]);
            }
        } 
        getchar();
        printf("\n");
    }
}