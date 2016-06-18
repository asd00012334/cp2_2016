#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

long long int inversion;

int temp[100000];

int a[100000];
int atop=-1;

void mergeSort(int ll, int rr);

int main(){
//    freopen("text.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--){
        inversion=0;
        int n;
        scanf("%d",&n);
        for(int cnt=0;cnt<n;cnt++){
            int temp;
            scanf("%d",&temp);
            a[++atop]=temp;
        }
        mergeSort(0,n-1);
        printf("%lld\n",inversion);
        atop=-1;
    }
}

void mergeSort(int ll, int rr){
    int lower, upper;
    int lr,rl;
    lower=ll;
    upper=rr;
    lr=(ll+rr)/2;
    rl=lr+1;
    if(ll<rr){
        mergeSort(ll,lr);
        mergeSort(rl,rr);
    }
    int tempTop=-1;
    while(1){
        if(ll<=lr&&rl<=rr){
            if(a[ll]<=a[rl])
                temp[++tempTop]=a[ll++];
            else{
                inversion+=lr-ll+1;
                temp[++tempTop]=a[rl++];
            }
        }
        else if(ll>lr&&rl<=rr){
            for(;rl<=rr;)
                temp[++tempTop]=a[rl++];
        }
        else if(ll<=lr&&rl>rr){
            for(;ll<=lr;)
                temp[++tempTop]=a[ll++];
        }
        else
            break;
    }
    for(int cnt=lower;cnt<=upper;cnt++)
        a[cnt]=temp[cnt-lower];
    return;
}
