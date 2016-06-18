#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    vector<int> a;
    while(n--){
        int temp;
        scanf("%d",&temp);
        a.push_back(temp);
    }
    sort(a.begin(),a.end());
    int total=0;
    int siz=a.size();
    for(int cnt=0;cnt<siz;cnt++){
        if(a[cnt]<cnt+1)
            total=cnt+1;
    }
    printf("%d\n",total);
    return 0;
}
