#include <bits/stdc++.h>
using namespace std;

long long int r;

class A{
public:
    long long int data;
    bool operator<(A const& ri)const{
        return abs(ri.data-data)>r&&data<ri.data;
    }

};



int main(){
    long long int T;
    scanf("%lld",&T);
    while(T--){
        long long int n=0L;
        long long int num=0L;
        scanf("%lld%lld",&n,&r);
        set<A> shield;
        for(long long int cnt=1L;cnt<=n;cnt++){
            long long int attack=0L;
            scanf("%lld",&attack);
            A temp;
            temp.data=attack;
            if(!shield.count(temp))
                shield.insert(temp);
        }
        printf("%d\n",shield.size());
    }
    return 0;
}
