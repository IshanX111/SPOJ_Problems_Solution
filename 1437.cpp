#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<ll>adj[200000];
ll vis[200000];
ll level[200000];
void dfs(ll x){

    vis[x]=1;
    for(ll i=0;i<adj[x].size();i++){
        if(!vis[adj[x][i]]){
            level[adj[x][i]]=level[x]+1;
            dfs(adj[x][i]);
        }
    }

}
int main(){

    ll n;
    cin>>n;
    ll e=n-1;
    memset(vis,0,sizeof(vis));
    memset(level,0,sizeof(level));
    
    for(ll i=0;i<e;i++){
        ll x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    level[1]=0;
    dfs(1);

    /*for(ll i=1;i<=n;i++){
        cout<<level[i]<<" ";
    }
    cout<<endl;
    */
    ll res1=-9999999;
    ll store;
    for(ll i=1;i<=n;i++){
        if(level[i]>res1){
            res1=level[i];
            store=i;
        }
    }
    //cout<<res1<<endl;
    //cout<<store<<endl;
    memset(vis,0,sizeof(vis));
    memset(level,0,sizeof(level));
    dfs(store);
    ll res2=-9999999;
    for(ll i=1;i<=n;i++){
        if(level[i]>res2){
            res2=level[i];  
        }
    }
    cout<<res2<<endl;
    



}