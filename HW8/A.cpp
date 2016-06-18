#include <bits/stdc++.h>

using namespace std;

void DFS(int *adj,int const& n, int const& start, int const& ini,
         set<int>& traversed){
    for(int to=1;to<=n;to++){
        if(adj[start*(n+1)+to]==1)
        if(!traversed.count(to)){
            adj[ini*(n+1)+to]=1;
            traversed.insert(to);
            DFS(adj,n,to,ini,traversed);
        }
    }

}


int main(){
///    FILE* redirect=freopen("text.txt","w",stdout);
    while(1){
        int n;
        scanf("%d",&n);
        if(n==0) break;
        int adj[n+1][n+1];
        memset(adj,0,sizeof(adj));
        while(1){
            int startV;
            scanf("%d",&startV);
            if(startV==0) break;
            while(1){
                int toV;
                scanf("%d",&toV);
                if(toV==0) break;
                adj[startV][toV]=1;
            }
        }
        int query;
        scanf("%d",&query);
        while(query--){
            vector<int> ans;
            int startV;
            scanf("%d",&startV);
            set<int> traversed;
            DFS((int*)adj,n,startV,startV,traversed);
            for(int to=1;to<=n;to++)
                if(adj[startV][to]==0)
                    ans.push_back(to);
            printf("%d",ans.size());
            for(int cnt=0;cnt<ans.size();cnt++)
                printf(" %d",ans[cnt]);
            printf("\n");
        }
    }
 ///   fclose(redirect);
    return 0;
}
