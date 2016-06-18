#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        int total,m;
        total=0;
        scanf("%d",&m);
        int coin[m+1];
        coin[0]=0;
        for(int cnt=1;cnt<=m;cnt++){
            scanf("%d",coin+cnt);
            total+=coin[cnt];
        }
        int ans[total/2+1][m+1];
        for(int item=0;item<=m;item++){
            for(int capacity=0;capacity<=total/2;capacity++){
                if(capacity==0||item==0)
                    ans[capacity][item]=0;
                else if(capacity<coin[item])
                    ans[capacity][item]=ans[capacity][item-1];
                else
                    ans[capacity][item]=max(ans[capacity-coin[item]][item-1]+coin[item],ans[capacity][item-1]);
            }
        }
        printf("%d\n",total-2*ans[total/2][m]);
    }
    return 0;
}

