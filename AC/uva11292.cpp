#include<cstdio>
#include<algorithm>
using namespace std;

int main(){
    int n,m,a[20005],b[20005];
    while(scanf("%d%d",&n,&m)!=EOF && m){
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(int i=0;i<m;i++)
            scanf("%d",&b[i]);
        sort(a,a+n);
        sort(b,b+m);
        int cur=0,cost=0;
        for(int i=0;i<m;i++){
            if(b[i]>=a[cur]){
                cost+=b[i];
                cur++;
                if(cur==n)
                    break;
            }
        }
        if(cur==n)
            printf("%d\n",cost);
        else
            printf("%s\n","Loowater is doomed!");
    }
}
