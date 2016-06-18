#include<bits/stdc++.h>

using namespace std;

int main(){
    int T;
    scanf("%d",&T);
    while(getchar()!='\n');
    while(T--){
        long long int temp, sum=0;
        while(1){
            int c=0;
            if(isdigit(c=getchar())){
                ungetc(c,stdin);
                scanf("%lld",&temp);
                sum+=temp;
            }
            else if(c=='\n')
                break;
        }
        printf("%08lld\n",sum);
    }
    return 0;
}
