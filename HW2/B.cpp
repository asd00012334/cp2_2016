#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    while(1){
        int n;
        scanf("%d",&n);
        if(n==0)
            break;
        int radius[n+1];
        int output=0;
        radius[0]=0;
        for(int cnt=1;cnt<=n;cnt++){
            int temp;
            scanf("%d",&temp);
            radius[cnt]=temp;
        }
        sort(radius+1,radius+n+1);
        long long int partialSum[n+1];
        partialSum[0]=0;
        for(int cnt=1;cnt<=n;cnt++){
            partialSum[cnt]=partialSum[cnt-1]+radius[cnt];
        }
        for(int cnt=n;cnt>=2;cnt--){
            if(partialSum[cnt-1]>=radius[cnt]){
                output=cnt;
                break;
            }
        }
        printf("%d\n",output);
    }
    return 0;
}
