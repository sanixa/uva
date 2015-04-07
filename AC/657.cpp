#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
using namespace std;
int mapx,mapy,dicecount,dicepoint[2500];
char arr[50][50];
char mark1[50][50],mark2[50][50];
int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

void dfs1(int a,int b,int c)
{
    if(a<0 || a>=mapx || b<0 || b>=mapy)  //檢察是否超出邊界
        return;
    if(mark1[a][b]!=0) //檢查是否走過
        return;
    if(c==1 ^ arr[a][b]=='.') //判斷背景或骰子
        return;
    mark1[a][b]=c;
    dfs1(a+1,b,c);
    dfs1(a-1,b,c);
    dfs1(a,b+1,c);
    dfs1(a,b-1,c);
}
void dfs2(int a,int b,int c)
{
    if(a<0 || a>=mapx || b<0 || b>=mapy)  //檢察是否超出邊界
        return;
    if(mark2[a][b]!=0)
        return;
    if(mark1[a][b]==1)
        return;
    //cout<<c<<" "<<arr[a][b]<<endl;
    if(c==1 ^ arr[a][b]=='*')
        return;
    //cout<<"123";
    mark2[a][b]=c;
    dfs2(a+1,b,c);
    dfs2(a-1,b,c);
    dfs2(a,b+1,c);
    dfs2(a,b-1,c);
}
void debug()
{
    for(int i=0;i<mapx;i++)
    {
        for(int j=0;j<mapy;j++)
        {
            cout<<(int)mark1[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
    for(int i=0;i<mapx;i++)
    {
        for(int j=0;j<mapy;j++)
        {
            cout<<(int)mark2[i][j];
        }
        cout<<endl;
    }
}
int main()
{
    int T=0;
    while(cin>>mapy>>mapx,mapx+mapy)
    {
        memset(mark1,0,sizeof(mark1));
        memset(mark2,0,sizeof(mark2));
        for(int i=0;i<2500;i++)
            dicepoint[i]=1;
        dicecount=1;
        for(int i=0;i<mapx;i++)
            for(int j=0;j<mapy;j++)
                cin>>arr[i][j];
        for(int i=0;i<mapx;i++)
            for(int j=0;j<mapy;j++)
            {
                if(mark1[i][j]==0)
                {
                    if(arr[i][j]=='.')
                        dfs1(i,j,1);
                    else
                        dfs1(i,j,++dicecount);
                }
                if(arr[i][j]!='.' && mark2[i][j]==0)
                {
                    if(arr[i][j]=='*')
                        dfs2(i,j,1);
                    else
                        dfs2(i,j,++dicepoint[mark1[i][j]]);
                }
            }
        qsort (dicepoint+2, dicecount-1 , sizeof(int), compare);
        cout<<"Throw "<<++T<<endl;
        for(int i=0;i<dicecount-1;i++)
            cout<<dicepoint[i+2]-1<<(i!=dicecount-2 ? " " : "\n");
    }
}
