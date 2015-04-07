#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

int main(){
    int a,b,c,arr[100000];
    scanf("%d",&a);
    while(a--){
        scanf("%d",&b);
        for(int i=0;i<b;i++){
            scanf("%d",&arr[i]);
        }
        int ans=arr[0]-arr[1];
        int maxint=arr[0];
        for(int i=1;i<b;i++){
            ans=max(ans,maxint-arr[i]);
            maxint=max(maxint,arr[i]);
        }
        printf("%d\n",ans);
    }
}
