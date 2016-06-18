#include <bits/stdc++.h>

using namespace std;

bool operator<(pair<int,int> l, pair<int,int> r){
    if(l.first<r.first)
        return true;
    else if(l.first==r.first&&l.second<r.second){
        return true;
    }
    else
        return false;
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int end;
        scanf("%d",&end);
        vector<pair<int, int> > input;
        while(1){
            int a,b;
            scanf("%d%d",&a,&b);
            if(a==0&&b==0)
                break;
            input.push_back(pair<int, int>(a,b));
        }
        sort(input.begin(),input.end());
        int start=0;
        int siz=input.size();
        int seg=0;
        bool succ=true;
        vector<pair<int, int> > ans;
        int cnt=0;
        while(1){
            bool inLoop=false;
            int maxi=start;
            int rightMost=0;
            int maxX=0;
            for(;input[cnt].first<=start&&cnt<siz;cnt++){
                if(input[cnt].second>maxi){
                    inLoop=true;
                    maxi=input[cnt].second;
                    maxX=input[cnt].first;
                }
            }
            if(inLoop){
                start=maxi;
                seg++;
                ans.push_back(pair<int,int>(maxX,maxi));
            }

            if(start>=end){
                succ=true;
                break;
            }
            else if(cnt==siz){
                succ=false;
                break;
            }
            else if(input[cnt].first>start){
                succ=false;
                break;
            }
        }
        if(succ){
            printf("%d\n",seg);
            for(int cnt=0;cnt<seg;cnt++)
                printf("%d %d\n",ans[cnt].first,ans[cnt].second);
        }
        else{
            printf("0\n");
        }
        printf("\n");
    }
    return 0;
}
