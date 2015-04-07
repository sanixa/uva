#include<cstdio>
#include<cstring>
using namespace std;

int main(){
    int year[100]={},a,b;
    while(scanf("%d",&a)==1 && a){
        for(int i=0;i<a;i++){
            scanf("%d",&b);
            year[b-1]++;
        }
        int counter=0;
        for(int i=0;i<100;i++){
            while(year[i]!=0){
                counter++;
                if(counter!=a)
                    printf("%d ",i+1);
                else
                    printf("%d",i+1);
                year[i]--;
            }
        }
    }

}
