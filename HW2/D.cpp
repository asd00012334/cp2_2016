#include <cstdio>
#include <cstdlib>
#include <set>
#include <iostream>
#include <string>

using namespace std;

string digit[10]={"0",
                  "1",
                  "2",
                  "3",
                  "4",
                  "5",
                  "6",
                  "7",
                  "8",
                  "9"};
int root(string input);

int main(){
    int N,R;
    scanf("%d%d",&N,&R);
    char input[50];
    set<string> codeSet;
    string incompleteCode;
    scanf("%s",input);
    incompleteCode=input;
    for(int wantDigit=0;wantDigit<10;wantDigit++){
        if(root(incompleteCode+digit[wantDigit])==R){
            for(int cnt=0;cnt<N;cnt++){
                string completeCode=incompleteCode;
                completeCode.insert(cnt,digit[wantDigit]);
                codeSet.insert(completeCode);
            }
        }
    }
    if(codeSet.size()<=2)
        return 0;
    string mini, maxi;
    mini=*codeSet.begin();
    maxi=*codeSet.rbegin();
    codeSet.erase(mini);
    codeSet.erase(maxi);
    while(!codeSet.empty()){
        string temp=*codeSet.begin();
        cout<<temp<<endl;
        codeSet.erase(temp);
    }
    return 0;
}

int root(string input){
    int output=0;
    for(int cnt=0;cnt<input.size();cnt++)
        output+=input[cnt]-'0';
    if(output<10)
        return output;
    else{
        while(1){
            long long int intInput=output;
            output=0;
            while(intInput!=0){
                output+=intInput%10;
                intInput/=10;
            }
            if(output<10)
                return output;
        }
    }
}
