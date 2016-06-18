#include <bits/stdc++.h>

using namespace std;

long long int dfs(vector<vector<int> > const& adjList, vector<bool>& traversed,
        vector<int> const& pop, int const& tar){
    if(traversed[tar]) return 0;
    traversed[tar]=true;
    long long int output=pop[tar];
    int siz=adjList[tar].size();
    for(int cnt=0;cnt<siz;cnt++)
        output+=dfs(adjList, traversed, pop, adjList[tar][cnt]);
    return output;
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,m;
        scanf("%d%d",&n,&m);
        vector<int> pop(n);
        vector<vector<int> > adjList(n);
        for(int cnt=0;cnt<n;cnt++)
            scanf("%d",&pop[cnt]);
        for(int cnt=0;cnt<m;cnt++){
            int endA,endB;
            scanf("%d%d",&endA,&endB);
            endA--,endB--;
            adjList[endA].push_back(endB);
            adjList[endB].push_back(endA);
        }
        long long int maxi=0;
        vector<bool> traversed(n);
        for(int cnt=0;cnt<n;cnt++)
            traversed[cnt]=false;
        for(int cnt=0;cnt<n;cnt++)
            maxi=max(maxi,dfs(adjList, traversed, pop, cnt));
        printf("%lld\n",maxi);
    }
    return 0;
}
