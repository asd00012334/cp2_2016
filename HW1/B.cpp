#include <cstdio>
#include <cstdlib>
#include <vector>

int main(){
    int T;
    scanf("%d",&T);
    for(;T;T--){
        int n,m;
        scanf("%d%d",&n,&m);
        long long int partialSum[n+1];
        for(int cnt=0;cnt<=n;cnt++){
            if(cnt==0)
                partialSum[cnt]=0;
            else{
                int input;
                scanf("%d",&input);
                partialSum[cnt]=partialSum[cnt-1]+input;
            }
        }
        for(;m;m--){
            int l,r;
            scanf("%d%d",&l,&r);
            printf("%lld\n",partialSum[r]-partialSum[l-1]);
        }
    }
    return 0;
}
