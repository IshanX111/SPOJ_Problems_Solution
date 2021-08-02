#include<bits/stdc++.h>
#define INF 1000000000;
typedef long long ll;
using namespace std;
ll seg[400004] , input[100001];

void build_seg(ll pos,ll low,ll high){

    if(low==high){
        seg[pos]=input[low];
        return ;
    }
    ll mid=(low+high)/2;

    build_seg(2*pos,low,mid);
    build_seg(2*pos+1,mid+1,high);
    seg[pos]=seg[2*pos]+seg[2*pos+1];
    
}
ll query(ll si , ll ss , ll se , ll qs , ll qe)
{
	if(qe < ss || qs> se)
		return 0;
 
	if(ss>=qs && se<=qe)
		return seg[si];

	ll mid = (ss + se)/2;
	ll l = query(2*si , ss , mid , qs , qe);
	ll r = query(2*si+1 , mid+1 , se , qs , qe);
	return  l+r;
}

int main()
{
	ll n , q , l , r;
 
	cin>>n;
	for (ll i = 1; i <= n; i++){
		cin>>input[i];
    }
 
	cin>>q;
	build_seg(1 , 1 , n);
	while(q--)
	{
		cin>>l>>r;
		cout<<query(1 , 1 , n , l+1 , r+1)<<endl;
	}
}