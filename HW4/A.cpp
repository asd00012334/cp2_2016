#include <cstdio>
#include <cstdlib>
#include <iostream>

int pow(int base, int exponent);

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int N;
        scanf("%d",&N);
        printf("%d\n",pow(3,N)-1);
    }
    return 0;
}

int pow(int base, int exponent){
    if(exponent==0)
        return 1;
    else if(exponent==1)
        return base%100000007;
    else if(exponent%2==0){
        long long int temp=pow(base, exponent>>1);
        return temp*temp%100000007;
    }
    else{
        long long int temp=pow(base,exponent>>1);
        return temp*temp%100000007*base%100000007;
    }
}


