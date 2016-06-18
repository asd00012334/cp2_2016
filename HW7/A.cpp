#include <bits/stdc++.h>
using namespace std;

bool count(vector<pair<int,int> > vec,pair<int,int > tar){
    int siz=vec.size();
    for(int cnt=0;cnt<siz;cnt++)
        if(vec[cnt]==tar)
            return true;
    return false;
}

bool operator<(pair<int,int> l, pair<int,int> r){
    return l.first<r.first||
    (l.first==r.first&&l.second<r.second);
}

bool operator<(vector<pair<int,int> > l, vector<pair<int,int> > r){
    if(l.size()<r.size()) return true;
    else if(l.size()>r.size()) return false;
    else{
        int siz=l.size();
        for(int cnt=0;cnt<siz;cnt++)
            if(l.size()<r.size())
                return true;
        return false;
    }
}


bool legal(vector<pair<int,int> > const & dfs, pair<int,int> ins){
    int siz=dfs.size();
    if(!(0<=ins.first&&ins.first<8)) return false;
    if(!(0<=ins.second&&ins.second<8)) return false;
    for(int cnt=0;cnt<siz;cnt++){
        int r,c;
        r=dfs[cnt].first;
        c=dfs[cnt].second;
        if(r==ins.first||c==ins.second) return false;
        else if(abs(r-ins.first)==abs(c-ins.second)) return false;
    }
    return true;
}

int main(){
    int k;
    scanf("%d",&k);
    while(k--){
        vector<vector<int> > board;
        for(int row=0;row<8;row++){
            vector<int> line;
            for(int col=0;col<8;col++){
                int temp;
                scanf("%d",&temp);
                line.push_back(temp);
            }
            board.push_back(line);
        }
        vector<pair<int, int> > dfs;
        set<vector<pair<int,int> > > traveled;
        int row=0,col=0;
        int maxi=0;
        while(1){
            row=dfs.size();
            if(row==8){
                int sum=0;
                for(int cnt=0;cnt<8;cnt++)
                    sum+=board[dfs[cnt].first][dfs[cnt].second];
                maxi=max(maxi,sum);

            }
            bool canGo=false;
            for(col=0;col<8;col++){
                vector<pair<int,int> > temp=dfs;
                temp.push_back(pair<int,int>(row,col));
                if(!traveled.count(temp))
                if(legal(dfs,pair<int,int>(row,col))){
                    dfs.push_back(pair<int,int>(row,col));
                    traveled.insert(dfs);
                    canGo=true;
                    break;
                }
            }
            if(!canGo){
                if(dfs.empty()) break;
                dfs.pop_back();
            }
        }
        printf("%5d\n",maxi);
    }
    return 0;
}
