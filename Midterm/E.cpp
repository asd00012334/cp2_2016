#include <bits/stdc++.h>

using namespace std;

int n,m,k;

bool check(vector<pair<int,int> > const& pipe, int const& choose){
    int flowBits, risk;
    flowBits=risk=0;
    for(int cnt=0;cnt<n;cnt++){
        if(choose&(1<<cnt)){
            flowBits+=pipe[cnt].first;
            risk+=pipe[cnt].second;
        }
    }
    if(flowBits>=m&&risk<=k) return true;
    return false;
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        n=m=k=0;
        scanf("%d%d%d",&n,&m,&k);
        vector<pair<int,int> > pipe;
        for(int cnt=1;cnt<=n;cnt++){
            int temp1,temp2;
            scanf("%d%d",&temp1,&temp2);
            pipe.push_back(pair<int,int>(temp1,temp2));
        }
        int div=(1<<n)-1;
        int ans=0;
        for(int choose=0;choose<=div;choose++){
            if(check(pipe,choose)) ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
