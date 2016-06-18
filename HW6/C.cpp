#include <bits/stdc++.h>

using namespace std;

class Turtle{
public:
    int weight;
    int strength;
    int cap()const{
        return strength-weight;
    }
    bool operator<(Turtle const& r)const{
        return cap()>=r.cap();
    }
};

int main(){
    int a,b,siz=0;
    vector<Turtle> pile;
    while(scanf("%d%d",&a,&b)!=EOF){
        Turtle temp;
        temp.weight=a;
        temp.strength=b;
        pile.push_back(temp);
        siz++;
    }
    sort(pile.begin(),pile.end());
    int DP[siz+1][siz+1];
    for(int cnt=0;cnt<=siz;cnt++)
    for(int cnt2=0;cnt2<=siz;cnt2++)
        DP[cnt][cnt2]=-1;
    for(int total=0;total<=siz;total++){
        for(int height=0;height<=total;height++){
            if(height==0){
                DP[total][height]=0;
                continue;
            }
            if(DP[total-1][height-1]==-1&&
               DP[total-1][height]==-1)
               DP[total][height]=-1;
            else if(DP[total-1][height]==-1&&
                DP[total-1][height-1]>pile[siz-total].cap())
                DP[total][height]=-1;
            else if(DP[total-1][height]==-1)
                DP[total][height]=DP[total-1][height-1]+pile[siz-total].weight;
            else if(DP[total-1][height-1]==-1)
                DP[total][height]=DP[total-1][height];
            else{
                DP[total][height]=min(DP[total-1][height]
                    ,DP[total-1][height-1]+pile[siz-total].weight);
            }
        }
    }
    /**
    for(int row=0;row<=siz;row++){
        for(int col=0;col<=siz;col++)
            printf("%5d",DP[row][col]);
        printf("\n");
    }
    printf("\n");
    */

    for(int cnt=siz;cnt>=0;cnt--){
        if(DP[siz][cnt]!=-1){
            printf("%d\n",cnt);
            break;
        }
    }
    return 0;
}
