#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

int main(){
    while(1){
        int N;
        scanf("%d",&N);
        if(N==0)
            break;
        while(1){
            stack<int> station;
            queue<int> to,from;
            bool output=true;
            bool terminate=false;
            for(int cnt=0;cnt<N;cnt++){
                int temp;
                scanf("%d",&temp);
                if(temp==0){
                    terminate=true;
                    break;
                }
                to.push(temp);
                from.push(cnt+1);
            }
            if(terminate){
                printf("\n");
                break;
            }
            int cur_to,cur_from;
            cur_to=0;
            cur_from=0;

            while(1){
                // if station and from-side
                // both be empty, end.
                if(station.empty()&&from.empty())
                    break;
                else if(station.empty()){
                    station.push(from.front());
                    from.pop();
                }

                // if the station's outest
                // coach has number less than the one of
                // CEL coach send one coach in to the station
                if(station.top()<to.front()){
                    station.push(from.front());
                    from.pop();
                }

                // else if the station's outest coach
                // has number equal to the one of the CEL
                // send one coach out of the station
                else if(station.top()==to.front()){
                    to.pop();
                    station.pop();
                }

                // else if the station's outest coach
                // has number more than the one of the CEL
                // the instance fail and end.
                else if(station.top()>to.front()){
                    output=false;
                    break;
                }
            }
            if(output)
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
    return 0;
}
