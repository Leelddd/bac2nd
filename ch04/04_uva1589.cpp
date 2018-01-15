#include<cstdio>
int board[11][10] = {0};
bool left= false, right= false, up = false, down = false;
int count = 0;

struct Point {
    Point(){}
    Point(int r, int c):r(r), c(c){}
    char type = 'G';
    int r;
    int c;
};
Point bg, rg;
Point rs[7];

void checkbg(){
    if(bg.r > 1)up=true;
    if(bg.r< 3)down=true;
    if(bg.c>4)left=true;
    if(bg.c<6)right=true;
}

bool checkG(const Point &p, const int &j){
    if(p.c != rs[j].c)  return true;
    for(int i = p.r + 1; i < rs[j].r; i++){if(board[i][p.c])return true;}
    return false;
}

bool checkR(const Point &p, const int &j){
    if(p.c == rs[j].c){
        for(int i = p.r+1; i < rs[j].r; i++){if(board[i][p.c]) return true;}
		return false;
    } 
    if(p.r == rs[j].r){
        for(int i = p.c+1; i < rs[j].c; i++){if(board[p.r][i]) return true;}
		return false;
    } 
	return true;
}

bool checkC(const Point &p, const int &j){
    int c = 0;
    if(p.c == rs[j].c){
        for(int i = p.r+1; i < rs[j].r; i++){if(board[i][p.c]) count++;}
    } 
    if(p.r == rs[j].r){
        for(int i = p.c+1; i < rs[j].c; i++){if(board[p.r][i]) count++;}
    } 
    return c != 1;
}

bool checkH(const Point &p, const int &j){
    if((p.r - rs[j].r)*(p.r - rs[j].r) + (p.c - rs[j].c)*(p.c - rs[j].c) == 5){
        if((p.r - rs[j].r == 2 && !board[rs[j].r+1][rs[j].c])
         || (p.r - rs[j].r == -2 && !board[rs[j].r-1][rs[j].c]))   return false;
        if((p.c - rs[j].c == 2 && !board[rs[j].r][rs[j].c+1]) 
        || (p.c - rs[j].c == -2 && !board[rs[j].r][rs[j].c - 1]))   return false;
    }
    return true;
}

bool check(int r, int c){
    Point p(r, c);
	bool find = true;
    for(int i = 0; i< count;i++){
        switch (rs[i].type) {
            case 'G':
                find = checkG(p, i);
                break;
            case 'R':
                find = checkR(p, i);
                break;
            case 'C':
                find = checkC(p, i);
                break;
            case 'H':
                find = checkH(p, i);
                break;
            default: break;
        }
        if(!find) return false;
    }
	return true;
}

int main(){
	for (;;) {
		scanf("%d%d%d", &count, &bg.r, &bg.c);
		if (!count)break;
		board[bg.r][bg.c] = 1;
		for (int i = 0; i < count; i++) {
			getchar();
			scanf("%c%d%d", &rs[i].type, &rs[i].r, &rs[i].c);
			board[rs[i].r][rs[i].c] = 1;
		}
		checkbg();
		if ((left && !board[bg.r][bg.c - 1] && check(bg.r, bg.c - 1))
			|| (right && !board[bg.r][bg.c + 1] && check(bg.r, bg.c + 1))
			|| (up && !board[bg.r - 1][bg.c] && check(bg.r - 1, bg.c))
			|| (down && !board[bg.r + 1][bg.c] && check(bg.r + 1, bg.c)))
			printf("NO\n");
		else
			printf("YES\n");
		getchar();
	}
}