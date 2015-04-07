#include<iostream>
#include<cstdio>
using namespace std;

int main(){
    int a,arr[5000],k=1;
    arr[0]=0;
    while(k<5000){  //stairs
        arr[k]=arr[k-1]+k;
        k++;
    }
    int pos;
    while(cin>>a){
        for(int i=0;i<5000;i++){
            if(a<=arr[i] && a>arr[i-1])
                pos=i;
        }
        if(pos%2==0){
            printf("TERM %d IS %d/%d\n",a,(a-arr[pos-1]),(pos+1)-(a-arr[pos-1]));
        }else{
            printf("TERM %d IS %d/%d\n",a,(pos+1)-(a-arr[pos-1]),(a-arr[pos-1]));
        }
    }
}
