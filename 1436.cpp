#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<ll>adj[100000];
ll visited[100000];
void add_edge(ll x,ll y)
{
    adj[x].push_back(y);
    adj[y].push_back(x);
}
void dfs(ll x)
{

    visited[x]=1;
    //cout<<x<<"-->";
    ll si=adj[x].size();
    for(ll i=0; i<si; i++)
    {
        if(!visited[adj[x][i]])
        {
            dfs(adj[x][i]);
        }
    }

}
int main()
{

    ll n,e;
    cin>>n>>e;
    for(ll i=1; i<=e; i++)
    {
        ll x,y;
        cin>>x>>y;
        add_edge(x,y);
    }
    if(n-1!=e)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    else
    {

        ll c=0;
        for(ll i=1; i<=n; i++)
        {
            if(visited[i]==0)
            {
                dfs(i);
                c++;
            }
        }
        if(c==1)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
}

