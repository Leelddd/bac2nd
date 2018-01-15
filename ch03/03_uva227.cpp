#include<cstdio>
#include<cstring>


char puzzle[5][5];
int row = 0, column = 0;
int count = 1;
int main(){
    for(;;){
        for(int i = 0; i < 5;i++){
            gets(puzzle[i]);
            if(puzzle[i][0] == 'Z') break;
            for(int j = 0; j < 5; j++){
                if(puzzle[i][j]==(char)0 || puzzle[i][j] == ' '){
                    row = i; column = j;
                }
            }
        }
        if(puzzle[0][0] == 'Z') break;
        
        if(count > 1)printf("\n");
        bool hasAnswer = true;
        char move = ' ';
        while((scanf("%c", &move) && move != '0')){
            if(!hasAnswer)  continue;
            switch (move){
                case 'A':
                    if(row == 0){
                        hasAnswer = false;
                    }else{
                        puzzle[row][column] = puzzle[row-1][column];
                        puzzle[row-1][column] = ' ';
                        row -= 1;
                    }
                    break;
                case 'B':
                    if(row == 4){
                        hasAnswer = false;
                    }else{
                        puzzle[row][column] = puzzle[row+1][column];
                        puzzle[row+1][column] = ' ';
                        row += 1;
                    }
                    break;
                case 'L':
                    if(column == 0){
                        hasAnswer = false;
                    }else{
                        puzzle[row][column] = puzzle[row][column - 1];
                        puzzle[row][column - 1] = ' ';
                        column -= 1;
                    }
                    break;
                case 'R':
                    if(column == 4){
                        hasAnswer = false;
                    }else{
                        puzzle[row][column] = puzzle[row][column + 1];
                        puzzle[row][column + 1] = ' ';
                        column += 1;
                    }
                    break;
                case '\n':
                    break;
                default:
                    hasAnswer = false;
                    break;
            }
        }
        printf("Puzzle #%d:\n", count++);
        if(hasAnswer){
            for(int i = 0; i < 5; i++){
                for(int j = 0; j < 5; j++){
                    printf("%c", puzzle[i][j]);
                    if(j < 4) printf(" ");
                }
                printf("\n");
            }
        }else{
            printf("This puzzle has no final configuration.\n");
        }
        gets(puzzle[0]);
    }
}