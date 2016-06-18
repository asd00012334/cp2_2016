#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
char* digit="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int main(){
    while(1){
        int a,b;
        long long int value=0;
        scanf("%d%d",&a,&b);
        getchar();
        if(a==0&&b==0)
            break;
        vector <char> input,output;
        int temp;
        for(int cnt=0;(temp=getchar())!='\n';cnt++){
            isdigit(temp)?temp=temp-'0':temp=temp-'A'+10;
            input.push_back(digit[temp]);
        }
        for(int cnt=0;cnt<input.size();cnt++){
            value=value*a+(isdigit(input[cnt])?input[cnt]-'0':input[cnt]-'A'+10);
        }
        if(value==0){
            output.push_back('0');
        }else
            while(value>0){
                output.push_back(digit[value%b]);
                value/=b;
            }
        for(int cnt=output.size()-1;cnt>=0;cnt--){
            printf("%c",output[cnt]);
        }
        printf("\n");
    }
    return 0;
}
