#include <cstdlib>
#include <cstdio>
#include <map>
#include <iostream>
#include <set>

using namespace std;

int main(){
    map<int, int> printer;
    while(1){
        int temp;
        scanf("%d",&temp);
        if(temp>0){
            if(printer.count(temp)==0){
                printer.insert(pair<int, int>(temp,1));
            }
            else{
                printer[temp]++;
            }
        }
        else if(temp==-1){
            if(printer.empty())
                continue;
            int maxi;
            maxi=printer.begin()->first;
            if(printer[maxi]>=2)
                printer[maxi]--;
            else if(printer[maxi]==1)
                printer.erase(maxi);
            printf("%d ",maxi);
        }
        else if(temp==-2){
            if(printer.empty())
                continue;
            int mini;
            mini=printer.rbegin()->first;

            if(printer[mini]>=2)
                printer[mini]--;
            else if(printer[mini]==1)
                printer.erase(mini);
            printf("%d ",mini);

        }
        else if(temp==0)
            break;
    }
    return 0;
}
