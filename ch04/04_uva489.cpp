#include<cstdio>
#include<cstring>
int inde = 0;
const int max = 100;
char word[max];
char guess[max];

int main(){
    for(;;){
        scanf("%d", &inde);
        if(inde == -1)break;
        scanf("%s%s", &word, &guess);
        int count[26] = {0};
        int wrong = 0;
        int right = 0;

        int len = strlen(word);
        for(int i = 0; i < len; i++){
            int ib = word[i] - 'a';
            if(count[ib] == 0){
                count[ib] = 1;
                right++;
            }
        }   

        int leng = strlen(guess);
        for(int i = 0; i < leng && wrong < 7 && right; i++){
            int ic = guess[i] - 'a';
            if(count[ic] == 0){ wrong++; count[ic] = -1;}
            else if(count[ic] == 1){count[ic] = 0; right--;}
        }

        printf("Round %d\n", inde);
        if(wrong > 6)printf("You lose.");
        else if(!right)printf("You win.");
        else printf("You chickened out.");
        printf("\n");
    }
    
}