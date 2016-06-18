#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <math.h>

int main(){
    int t;
    scanf("%d",&t);
    for(;t;t--){
        int input;
        scanf("%d",&input);
        if(input<2){
            printf("no\n");
        }
        else if(input<=3){
            printf("yes\n");
        }
        else if(!(input%2)){
            printf("no\n");
        }
        else{
            bool prime=true;
            int root=sqrt(input);
            for(int cnt=3;cnt<=root;cnt+=2){
                if(input%cnt==0){
                    prime=false;
                    break;
                }
            }
            if(prime)
                printf("yes\n");
            else
                printf("no\n");
        }
    }
    return 0;
}
