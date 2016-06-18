#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <set>

using namespace std;

bool inside(int row,int col){
    if(0<=row&&row<10&&0<=col&&col<10)
        return true;
    else
        return false;
}

void push(char room[10][10],int row, int col){
    if(inside(row,col))
        if(room[row][col]=='O')
            room[row][col]='#';
        else
            room[row][col]='O';

    if(inside(row+1,col))
        if(room[row+1][col]=='O')
            room[row+1][col]='#';
        else
            room[row+1][col]='O';

    if(inside(row,col+1))
        if(room[row][col+1]=='O')
            room[row][col+1]='#';
        else
            room[row][col+1]='O';

    if(inside(row-1,col))
        if(room[row-1][col]=='O')
            room[row-1][col]='#';
        else
            room[row-1][col]='O';

    if(inside(row,col-1))
        if(room[row][col-1]=='O')
            room[row][col-1]='#';
        else
            room[row][col-1]='O';

    return;
}

int main(){
    while(1){
        string roomName;
        set<int> moves;
        cin>>roomName;
        if(roomName=="end")
            break;
        char room[10][10];
        for(int cnt=0;cnt<100;){
            char temp=getchar();
            if(temp!='\n')
                *(&room[0][0]+cnt)=temp,cnt++;
        }
        for(int cnt=0;cnt<1024;cnt++){
            int curMove=0;
            char roomTemp[10][10];
            memcpy(roomTemp,room,sizeof(room));
            for(int col=0;col<10;col++){
                if(cnt&(1<<col))
                    push(roomTemp,0,col),curMove++;
            }
            for(int row=1;row<10;row++){
                for(int col=0;col<10;col++){
                    if(roomTemp[row-1][col]=='O')
                        push(roomTemp,row,col),curMove++;
                }
            }
            bool allDark=true;

            for(int col=0;col<10;col++)
                if(roomTemp[9][col]!='#')
                    allDark=false;
            if(allDark){
                moves.insert(curMove);
            }
        }

        printf("%s ",roomName.c_str());
        if(moves.size()>0&&(*moves.begin())<=100)
            printf("%d\n",*moves.begin());
        else
            printf("-1\n");
    }
    return 0;
}
