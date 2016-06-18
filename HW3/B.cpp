#include <cstdio>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
#include <queue>

using namespace std;

void dfs(int *x, bool* remain, int n, int t,
         int order,int sum, vector<int> terms);

queue<string> ans;
set<string> used;

int main(){
    while(1){
        int t,n;
        scanf("%d%d",&t,&n);
        if(t==0)
        if(n==0)
            break;
        printf("Sums of %d:\n",t);
        int x[n];
        bool remain[n];
        for(int cnt=0;cnt<n;cnt++){
            scanf("%d",x+cnt);
        }
        sort(x,x+n);
        for(int cnt=0;cnt<n;cnt++){
            remain[cnt]=true;
        }
        vector<int> terms;
        dfs(x,remain,n,t,n-1,0,terms);
        if(ans.empty())
            printf("NONE\n");
        while(!ans.empty()){
            printf("%s\n",ans.front().c_str());
            ans.pop();
        }
        while(!ans.empty())
            ans.pop();
        used.clear();
    }
    return 0;
}

void dfs(int *x, bool* remain, int n, int t,
         int order, int sum, vector<int> terms){
    if(sum==t){
        int siz=terms.size();
        char temp[100]={0};
        string temp2;
        for(int cnt=0;cnt<siz;cnt++){
            if(cnt==0){
                sprintf(temp,"%d",terms[cnt]);
                temp2=temp;
            }
            else{
                sprintf(temp,"+%d",terms[cnt]);
                temp2+=temp;
            }
        }
///        printf("%s\n",temp2.c_str());
        if(used.count(temp2)==0){
            ans.push(temp2);
            used.insert(temp2);
        }

        return;
    }
    else if(sum>t)
        return;
    for(int cnt=order;cnt>=0;cnt--){
        if(remain[cnt]==true){
            remain[cnt]=false;
            terms.push_back(x[cnt]);
            dfs(x,remain,n,t,cnt,sum+x[cnt],terms);
            remain[cnt]=true;
            terms.pop_back();
        }
    }
    return;
}
