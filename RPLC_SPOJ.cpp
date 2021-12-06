#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

bool fun(ll a[],ll x,ll n){

    for(ll i=0;i<n;i++){

        x+=a[i];
        if(x<=0){
            return false;
        }

    }
    return true;

}




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>>t;
    ll kase=1;
    while(t--){
        ll n;
        cin>>n;
        ll a[n];
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
        ll left=1;
        ll right=1e14;
        ll ans;

        ll mid;

        while(left<=right){

            mid=(left+right)>>1;

            if(fun(a,mid,n)==true){

                ans=mid;
                right=mid-1;

            }
            else{

                left=mid+1;

            }
        }
        printf("Scenario #%lld",kase++);
        printf(": %lld\n",ans);

    }

}
