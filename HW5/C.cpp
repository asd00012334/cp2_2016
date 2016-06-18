#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    scanf("%d",&N);
    while(N--){
        int n,parts;
        scanf("%d%d",&n,&parts);
        vector<int> input;
        long long int form,latt,midd;
        form=latt=midd=0;
        for(int cnt=0;cnt<n;cnt++){
            int temp;
            scanf("%d",&temp);
            if(form<temp)
                form=temp;
            latt+=temp;
            input.push_back(temp);
        }
        midd=(form+latt)/2;
        int siz=input.size();
        while(1){
            int partNum=1;
            long long int accum=0;
            for(int cnt=0;cnt<siz;cnt++){
                accum+=input[cnt];
                if(accum>=midd){
                    accum=input[cnt];
                    partNum++;
                }
            }
            if(form>=latt)
                break;
            if(partNum>parts){
                form=midd+1;
                midd=(form+latt)/2;
            }
            else if(partNum<=parts){
                latt=midd;
                midd=(form+latt)/2;
            }
        }
        long long int maxi=midd;

        long long int accum=0;
        int rightMost=siz-1;
        bool slash[siz];
        int curPart=parts;
        for(;rightMost>=0;rightMost--){
            accum+=input[rightMost];
            if(parts>rightMost + 1){
                for(;rightMost>=0;rightMost--)
                    slash[rightMost]=true;
                break;
            }
            if(accum>maxi){
                parts--;
                accum=input[rightMost];
                slash[rightMost]=true;
            }
            else
                slash[rightMost]=false;
        }
        printf("%d",input[0]);
        if(slash[0])
            printf(" /");
        for(int cnt=1;cnt<siz;cnt++){
            printf(" %d",input[cnt]);
            if(slash[cnt])
                printf(" /");
        }
        printf("\n");
    }
    return 0;
}
