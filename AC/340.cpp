#include<iostream>
using namespace std;

int main(){
    int arr1[1000],arr2[1000],m,stock1[10],stock2[10],a,b,counter=0,countable[1000];
    while(cin>>m,m!=0){
        counter++;
        cout<<"Game "<<counter<<":"<<endl;
        for(int i=0;i<m;i++){ //input origin
            cin>>arr1[i];
        }
        for(int i=0;i<10;i++)
            stock1[i]=0;
        for(int i=0;i<m;i++){   //store amount of origin number
            stock1[arr1[i]-1]++;
        }
        while(cin>>arr2[0],arr2[0]!=0){
            a=b=0;
            for(int i=0;i<10;i++){
                stock2[i]=stock1[i];
            }
            for(int i=1;i<m;i++){  //input guess
                cin>>arr2[i];
            }
            for(int i=0;i<m;i++){  //one to one
                countable[i]=1;
            }
            for(int i=0;i<m;i++){   //check A
                if(arr1[i]==arr2[i]){
                    stock2[arr2[i]-1]--;
                    a++;
                    countable[i]--;
                }
            }
            for(int i=0;i<m;i++){ //check B
               if(stock2[arr2[i]-1]>0 && countable[i]>0){
                    stock2[arr2[i]-1]--;
                    b++;
                }
            }
            cout<<"    ("<<a<<","<<b<<")"<<endl;
        }
        for(int i=1;i<m;i++){
                cin>>arr2[i];
        }
    }
}
