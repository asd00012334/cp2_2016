#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string.h>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    for(;t;t--){
        int x,y;
        scanf("%d%d",&x,&y);
        getchar();
        while(1){
            char cmd[70];
            int steps;
            gets(cmd);
            if(cmd[0]=='E')
                break;
            strtok(cmd," ");
            steps=atoi(strtok(NULL,"\0"));
            switch(cmd[0]){
            case 'U':
                y+=steps;
            break;
            case 'D':
                y-=steps;
            break;
            case 'L':
                x-=steps;
            break;
            case 'R':
                x+=steps;
            break;
            default:
            break;
            }
        }
        printf("%d %d\n",x,y);
    }
}
