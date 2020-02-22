#include<bits/stdc++.h>
using namespace std;
int rev(int a);
int rev(int a)
{
    int b,d;
    b=a;
    int res=0;
    while(b>0)
    {
        d=b%10;
        res=res*10+d;
        b=b/10;
    }
    return res;
}
int main()
{

    int t,a,b,x,y,z,w;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        x=rev(a);
        y=rev(b);
        z=x+y;
        w=rev(z);
        printf("%d\n",w);
    }


}
