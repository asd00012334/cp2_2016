#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>

bool end=false;

int main(){
    while(!end){
        int sum=0;
        while(1){
            char temp=getchar();
            if(temp!='\n'&&temp!=' '&&temp!=EOF){
                int partialNum;
                ungetc(temp,stdin);
                scanf("%d",&partialNum);
                sum+=partialNum;
            }
            else if(temp=='\n')
                break;
            else if(temp==EOF){
                end=true;
                break;
            }
        }
        if(!end)
            printf("%d\n",sum);
    }
    return 0;
}
