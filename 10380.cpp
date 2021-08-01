#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<ll> adj[100005];
ll vis[100005];
void dfs(ll x)
{

    vis[x] = 1;
    for (ll i = 0; i < adj[x].size(); i++)
    {
        if (!vis[adj[x][i]])
        {
            dfs(adj[x][i]);
        }
    }
}
int main()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t, n, c;
    cin >> t;
    while (t--)
    {
        ll n;
        cin>>n;
        ll e;
        cin>>e;
        memset(vis,0,sizeof(vis));  
        for(ll i=0;i<e;i++){
            ll x,y;
            cin>>x>>y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        c = 0;
        for (ll i = 0; i < n; i++)
        {
           
            if (!vis[i])
            {
               
                c++;
                dfs(i);
                 
            }
        }
        cout << c << endl;
        for(ll i=0;i<=100005;i++){
            adj[i].clear();
        }
        
    }
}