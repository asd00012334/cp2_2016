#include <bits/stdc++.h>

using namespace std;

long long int gcd(long long int a, long long int b){
    return (b==0)?a:gcd(b,a%b);
}

long long int lcm(long long int a, long long int b){
    return a*b/gcd(a,b);
}

void gcdEx(long long int a, long long int b,\
           long long int& x, long long int& y){
    long long ll,lr,rl,rr;
    ll=rr=1;
    lr=rl=0;
    while(a){
        if(a<b){
            rl-=(b/a*ll);
            rr-=(b/a*lr);
            b%=a;
        }
        else{
            swap(a,b);
            swap(ll,rl);
            swap(lr,rr);
        }
    }
    x=rl;
    y=rr;
}

int main(){

    long long int n=0,m=0;
    long long int x=0,y=0;
    scanf("%I64d%I64d",&n,&m);
    if(n==1||m==1)
        if(n*m==1)
            printf("1\n");
        else
            printf("2\n");
    else if(gcd(n,m)!=1){
        printf("%I64d\n",lcm(n,m));
        return 0;
    }
    else{
        gcdEx(n,m,x,y);
        printf("%I64d\n",max(abs(n*x),abs(m*y)));
    }
    return 0;
}
