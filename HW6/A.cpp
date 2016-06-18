#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    scanf("%d",&N);
    int subSum[N+1][N+1];
    for(int row=0;row<=N;row++)
    for(int col=0;col<=N;col++){
        int temp;
        if(!row||!col)
            subSum[row][col]=0;
        else{
            scanf("%d",&temp);
            subSum[row][col]=subSum[row-1][col]+subSum[row][col-1]\
            -subSum[row-1][col-1]+temp;
        }
    }
    int maxi=0;
    for(int r0=1;r0<=N;r0++)
    for(int r1=r0;r1<=N;r1++)
    for(int c0=1;c0<=N;c0++)
    for(int c1=c0;c1<=N;c1++){
        int sqSum=subSum[r1][c1]-subSum[r0-1][c1]-subSum[r1][c0-1]\
        +subSum[r0-1][c0-1];
        if(maxi<sqSum)
            maxi=sqSum;
    }
    printf("%d\n",maxi);
    return 0;
}
