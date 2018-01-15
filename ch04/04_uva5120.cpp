#include<cstdio>
#include<cstring>
#include<vector>
using std::vector;
int r, c;
int rnow, cnow;
bool exist = true;
int count = 1;

struct Oper {
    vector<int> indexs;
    int r1, c1, r2, c2;    
    char type[2];
};
vector<Oper> opers;

void exchange(Oper &o){
    if(o.r1 == rnow && o.c1 == cnow){rnow = o.r2; cnow = o.c2;}
    else if(o.r2 == rnow && o.c2 == cnow){rnow = o.r1; cnow = o.c1;}
}

void del(Oper &o){
    if(o.type[1] == 'R'){
        int plus = 0;
        for(auto i: o.indexs){
            if(i == rnow){exist = false; return;}
            else if(i < rnow) plus++;
        }
        rnow -= plus; 
    }
    if(o.type[1] == 'C'){
        int plus = 0;
        for(auto i: o.indexs){
            if(i == cnow){exist = false;return;}
            else if(i < cnow) plus++;
        }
        cnow-=plus;
    }
}

void insert(Oper &o){
    if(o.type[1] == 'R'){
        int plus = 0;
        for(auto i: o.indexs){
            if(i <= rnow)   plus++;
        }
        rnow += plus;
    }
    if(o.type[1] == 'C'){
        int plus = 0;
        for(auto i: o.indexs){
            if(i <= cnow)   plus++;
        }
        cnow += plus;
    }
}

int main(){
    for(;;){
        int len;
        scanf("%d%d%d", &r, &c, &len);
        if(r == 0)  break;
        if(count > 1) printf("\n");
        printf("Spreadsheet #%d\n", count++);
        
        // read all operations
        opers.clear();
        for(int i = 0; i < len; i++){
            Oper o;
            scanf("%s", &o.type);
            if(o.type[0] == 'E'){
                scanf("%d%d%d%d", &o.r1, &o.c1, &o.r2, &o.c2);
            }else{
                int l;
                scanf("%d", &l);
                for(int j = 0; j < l; j++){
                    int tmp;
                    scanf("%d", &tmp);
                    o.indexs.push_back(tmp);
                }
            }
            opers.push_back(o);
        } 

        // simulate movement
        scanf("%d", &len);
        for(int i = 0; i < len; i++){
            scanf("%d%d", &rnow, &cnow);
            int rbegin = rnow, cbegin = cnow;
            exist = true;
            for(auto o: opers){
                if(o.type[0] == 'E')    exchange(o);
                else if(o.type[0] == 'D')   del(o);
                else    insert(o);
                if(!exist)  break;
            }
            if(exist){
                printf("Cell data in (%d,%d) moved to (%d,%d)", rbegin, cbegin, rnow, cnow);
            }else{
                printf("Cell data in (%d,%d) GONE", rbegin, cbegin);
            }
            printf("\n");
        }
    }
}