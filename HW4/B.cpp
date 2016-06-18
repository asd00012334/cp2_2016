#include <cstdio>
#include <cstdlib>
#include <cstring>

int max(int left,int right) {
    return left>right?left:right;
}

int min(int left, int right) {
    return left<right?left:right;
}

using namespace std;

int n,leftmost=0;

void flatten(int *road, int start, int len, int depth);
bool check(int *road, int w, int m, int budget);

int main(){
    int T;
//    freopen("text.txt","r",stdin);
    scanf("%d",&T);
    while(T--){
        int maxi=0;
        int w,m;
        scanf("%d%d%d",&n,&w,&m);
        int road[n];
        for(int cnt=0;cnt<n;cnt++){
            int temp;
            scanf("%d",&temp);
            if(temp>maxi)
                maxi=temp;
            road[cnt]=temp;
        }

        if(!check(road,w,m,maxi)){
            puts("-1");
            continue;
        }
        else{
            int form,latt,midd;
            form=0;latt=maxi;midd=(form+latt)>>1;
            int cou=0;
            while(1){
                cou++;
                if(check(road,w,m,midd)){
                    if(midd==0){
                        if(check(road,w,m,0)){
                            puts("0");
                            break;
                        }
                        else{
                            puts("1");
                            break;
                        }
                    }
                    else if(!check(road,w,m,midd-1)){
                        printf("%d\n",midd);
                        break;
                    }
                    else{
                        latt=midd;
                        midd=(form+latt)>>1;
                    }
                }
                else{
                    if(check(road,w,m,midd+1)){
                        printf("%d\n",midd+1);
                        break;
                    }
                    else{
                        form=midd;
                        midd=(form+latt)>>1;
                    }
                }
            }
//            printf("%d,\n",cou);
        }
    }

    return 0;
}

void flatten(int *road, int start, int len, int depth){
    int roadSiz=n;
    for(int cnt=start;cnt<start+len;cnt++){
        if(cnt<roadSiz)
            road[cnt]-=depth;
    }
    return;
}

bool check(int *road, int w, int m, int budget){
    int roadTemp[n+1];
    memcpy(roadTemp,road,sizeof(int)*n);
    int roadSiz=n;
    int leftmost=0;
    for(int cnt=1;cnt<=m;/**cnt++*/){
        if(leftmost==roadSiz)
            break;
        if(roadTemp[leftmost]%budget==0){
            int temp=roadTemp[leftmost]/budget;
            temp=min(cnt+temp,m+1)-cnt;
            flatten(roadTemp,leftmost,w,budget*temp);
            cnt+=temp;
        }
        else{
            int temp=roadTemp[leftmost]/budget+1;
            temp=min(cnt+temp,m+1)-cnt;
            flatten(roadTemp,leftmost,w,budget*temp);
            cnt+=temp;
        }
        for(;leftmost<roadSiz&&roadTemp[leftmost]<=0;leftmost++);
    }
    if(leftmost==roadSiz)
        return true;
    else
        return false;
}
