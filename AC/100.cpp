#include<iostream>
using namespace std;

int length=0;
int fa(long long int a){
    length++;
    if(a==1)
        return length;
    if(a%2==0)
        return fa(a/2);
    return fa(a*3+1);
}
int main(){
    long long int a,b,maxlength;
    while(cin>>a>>b){
        cout<<a<<" "<<b<<" ";
        if(a>b){
            int c=a;
            a=b;
            b=c;
        }
        maxlength=0;
        for(int i=a;i<=b;i++){
            length=0;
            length=fa(i);
            if(length>maxlength)
                maxlength=length;
        }
        cout<<maxlength<<endl;
    }
}
