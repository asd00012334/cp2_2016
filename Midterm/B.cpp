#include <bits/stdc++.h>

using namespace std;

void bomb(bool mapp[101][101], int row, int col, int len){
    for(int cnt=col;cnt<col+len;cnt++){
        if(cnt>100) break;
        mapp[row][cnt]=false;
    }
    return;
}

void view(bool mapp[101][101], int R, int C){
    for(int row=1;row<=R;row++){
        for(int col=1;col<=C;col++)
            if(mapp[row][col])
                printf("@");
            else
                printf("~");
        printf("\n");
    }
    printf("\n");
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,m;
        scanf("%d%d",&n,&m);
        int miniRow=200,miniCol=200;
        bool mapp[101][101]={{false}};
        for(int cnt=1;cnt<=n;cnt++){
            int row,col;
            scanf("%d%d",&col,&row);
            mapp[row][col]=true;
        }

        int ans=0;
        miniRow=1;
        miniCol=1;
        while(1){
            int row=0,col=0;
            for(int row=miniRow;row<=100;row++){
                bool breaker=false;
                for(col=1;col<=100;col++){
                    if(mapp[row][col]){
                        miniRow=row;
                        miniCol=col;
                        breaker=true;
                        break;
                    }
                }
                if(breaker)
                    break;
            }
            if(row>100||col>100) break;
            bomb(mapp, miniRow, miniCol, m);
        //    view(mapp,10,10);
            ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
