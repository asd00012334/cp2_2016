#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int main(){
    int N;
    cin >> N;
    for(;N;N--){
        int input;
        cin >> input;
        int a,b,c;
        bool existence=false;
        for(a=0;a<=300&&!existence;a++)
        for(b=a;b<=300&&!existence;b++)
        for(c=b;c<=300&&!existence;c++){
            int temp=a*a+b*b+c*c;
            if(input==temp){
                existence=true;
                cout<<a<<" "<<b<<" "<<c<<endl;
            }
            else if(temp>input){
                break;
            }
        }

        if(!existence){
            cout<<"-1"<<endl;
        }
    }
    return 0;
}
