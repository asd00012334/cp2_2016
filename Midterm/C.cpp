#include <bits/stdc++.h>

using namespace std;


int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,m;
        scanf("%d%d",&n,&m);
        int mapp[n+1][m+1];
        for(int y=m;y>=0;y--)
        for(int x=0;x<=n;x++){
            if(!x||!y){
                mapp[x][y]=0;
                continue;
            }
            int temp=0;
            temp=getchar();
            if(temp=='\n'){
                x--;
                continue;
            }
            else
                mapp[x][y]=temp;
        }


        int DP[n+1][m+1];
        for(int y=0;y<=m;y++)
        for(int x=0;x<=n;x++){
            if(!x||!y) DP[x][y]=100;
            else if(x==1&&y==1) DP[x][y]=0;
            else{
                int tempLeft,tempDown;
                switch(mapp[x-1][y]){
                case 'E':
                    tempLeft=0; break;
                case 'W':
                    tempLeft=2; break;
                case 'N':case 'S':case 'O':
                    tempLeft=1; break;
                default:
                    tempLeft=200;
                }
                switch(mapp[x][y-1]){
                case 'E':case 'W':case 'O':
                    tempDown=1; break;
                case 'N':
                    tempDown=0; break;
                case 'S':
                    tempDown=2; break;
                default:
                    tempDown=200;
                }
                DP[x][y]=min(DP[x-1][y]+tempLeft,DP[x][y-1]+tempDown);
            }
        }



        printf("%d\n",DP[n][m]);
    }
    return 0;
}
