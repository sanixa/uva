#include<iostream>
using namespace std;

int main(){
    int a,b,k,arr[50];
    while(cin>>a){
        cin>>b;
        if(a<2 || b<2 || b>a){
            cout<<"Boring!"<<endl;
            continue;
        }
        arr[0]=a;
        k=1;
        while(a!=1){
            if(a%b==0){
                arr[k]=a/b;
                a/=b;
                k++;
            }else{
                break;
            }
        }
        if(a==1){
            for(int i=0;i<k;i++){
                cout<<arr[i]<<(i!=k-1 ? " " : "\n");
            }
        }else{
            cout<<"Boring!"<<endl;
        }
    }
}
