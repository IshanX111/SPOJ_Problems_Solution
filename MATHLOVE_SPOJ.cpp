#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll fun(ll y)
{

    return (y*(y+1))/2;

}
int main()
{


    ll t;
    cin>>t;
    while(t--)
    {

        ll y;
        cin>>y;

        ll left=1;
        ll right=1e5;
        ll c=0;
        while(left<=right)
        {

            ll mid=(left+right)>>1;
            if(fun(mid)==y)
            {
                c=1;
                cout<<mid<<endl;
                break;
            }
            else if(fun(mid)>y){
                right=mid-1;
            }
            else{
                left=mid+1;
            }

        }
        if(c==0){
            cout<<"NAI"<<endl;
        }
    }
}
