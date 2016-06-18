#include <bits/stdc++.h>

using namespace std;

struct Board{
    int body[5][5];
    int level;
    Board(Board const& input){
        level=input.level;
        for(int row=0;row<5;row++)
        for(int col=0;col<5;col++)
            body[row][col]=input.body[row][col];
    }
    Board(int body[5][5], int level=0){
        this->assign(body,level);
    }
    void assign(int body[5][5], int level=0){
        this->level=level;
        for(int row=0;row<5;row++)
        for(int col=0;col<5;col++)
            this->body[row][col]=body[row][col];
    }
    friend bool operator==(Board l, Board r){
        for(int row=0;row<5;row++)
        for(int col=0;col<5;col++)
            if(l.body[row][col]!=r.body[row][col])
                return false;
        return true;
    }
    Board move(int direction){
        Board output(*this);
        output.level++;
        int row=0,col=0;
        for(int r=0;r<5;r++)
        for(int c=0;c<5;c++)
            if(body[r][c]==' ')
                row=r,col=c;
        switch(direction){
        case 0:
            if(row>=2&&col<=3)
                swap(output.body[row][col],output.body[row-2][col+1]);
            break;
        case 1:
            if(row>=1&&col<=2)
                swap(output.body[row][col],output.body[row-1][col+2]);
            break;
        case 2:
            if(row<=3&&col<=2)
                swap(output.body[row][col],output.body[row+1][col+2]);
            break;
        case 3:
            if(row<=2&&col<=3)
                swap(output.body[row][col],output.body[row+2][col+1]);
            break;
        case 4:
            if(row<=2&&col>=1)
                swap(output.body[row][col],output.body[row+2][col-1]);
            break;
        case 5:
            if(row<=3&&col>=2)
                swap(output.body[row][col],output.body[row+1][col-2]);
            break;
        case 6:
            if(row>=1&&col>=2)
                swap(output.body[row][col],output.body[row-1][col-2]);
            break;
        case 7:
            if(row>=2&&col>=1)
                swap(output.body[row][col],output.body[row-2][col-1]);
            break;
        }
        return output;
    }
    bool operator<(Board const &r)const {
        for(int row=0;row<5;row++)
        for(int col=0;col<5;col++)
            if(body[row][col]<r.body[row][col])
                return true;
            else if(body[row][col]>r.body[row][col])
                return false;
        return false;
    }
};

int main(){
    int N;
    scanf("%d",&N);
    int tarBody[5][5]={
        {'1','1','1','1','1'},
        {'0','1','1','1','1'},
        {'0','0',' ','1','1'},
        {'0','0','0','0','1'},
        {'0','0','0','0','0'}};
    Board const tar(tarBody,0);
    while(N--){
        int boardBody[5][5];
        for(int row=0;row<5;row++){
            for(int col=0;col<5;col++){
                int temp=getchar();
                if(temp=='0'||temp=='1'||temp==' ')
                    boardBody[row][col]=temp;
                else
                    col--;
            }
        }
        queue<Board> bfs;
        Board iniBoard(boardBody,0);
        bfs.push(iniBoard);
        set<Board> traced;
        traced.insert(iniBoard);
        int level=0;
        while(1){
            Board cur=bfs.front();
            if(cur==tar||cur.level>=11){
                level=cur.level;
                break;
            }
            for(int dir=0;dir<8;dir++){
                Board temp=cur.move(dir);
                if(!traced.count(temp)){
                    bfs.push(temp);
                    traced.insert(temp);
                }
            }
            bfs.pop();
        }
        if(level>=11) printf("Unsolvable in less than 11 move(s).\n");
        else printf("Solvable in %d move(s).\n",level);
    }
    return 0;
}
