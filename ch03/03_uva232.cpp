#include<cstdio>

#define max 10

char arr[max][max];
int index[max][max];
int row = 0, column = 0;
int count = 1;
char empty = ' ';

int main(){
    for(int i = 0; i < max; i++)
        for(int j = 0; j < max; j++)
            index[i][j] = 0;
    for(;;){
        scanf("%d", &row);
        if(row == 0)    break;
        scanf("%d", &column);
        char ss[10];
        gets(ss);
        for(int i = 0; i < row; i++){
            gets(arr[i]);
        }
        int ind = 1;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < column; j++){
                if(arr[i][j] == '*') continue;
                if(i == 0 || j == 0){
                    index[i][j] = ind++;
                } else if (arr[i-1][j] == '*' || arr[i][j-1] == '*'){
                    index[i][j] = ind++;
                }
            }
        }
        if(count > 1)printf("\n");
        printf("puzzle #%d:\nAcross", count++);
        for(int i = 0; i < row; i++){
            for(int j = 0; j < column; j++){
                if (arr[i][j] == '*')   continue;
                if (j == 0 || arr[i][j-1] == '*'){
                    if(index[i][j] /10 > 0)printf("\n ");
                    else printf("\n  ");
                    printf("%d.", index[i][j]);
                }
                printf("%c", arr[i][j]);
            }
        }
        printf("\nDown");
        for(int i = 0; i < row; i++){
            for(int j = 0; j < column; j++){
                if (arr[i][j] == '*')   continue;
                if (i == 0 || arr[i-1][j] == '*'){ 
                    if(index[i][j] /10 > 0)printf("\n ");
                    else printf("\n  ");
                    printf("%d.", index[i][j]);
                    for(int k = i; k < row && arr[k][j] != '*'; k++)
                        printf("%c", arr[k][j]);
                }
            }
        }
        printf("\n");
        
    }
    
}