#include<iostream>
using namespace std;
long long rev(long long a)
{
    long long b=0;
    while(a>0)
    {
        b*=10;
        b+=a%10;
        a/=10;
    }
    return b;
}
int main()
{
    int c;
    cin>>c;
    for(int i=0;i<c;i++)
    {
        long long d;
        cin>>d;
        int con=0;
        do
        {
            d+=rev(d);
            con++;
        }while(d!=rev(d));
        cout<<con<<" "<<d<<endl;
    }
}
