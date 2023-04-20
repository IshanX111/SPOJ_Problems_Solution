#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define pii pair<ll,ll>
ll dx[]={-1,1,2,2,1,-1,-2,-2};
ll dy[]={2,2,1,-1,-2,-2,-1,1};
ll grid[1005][1005];
ll level[1005][1005];
ll vis[1005][1005];
void bfs(ll sx,ll sy){
    memset(vis,0,sizeof(vis));
    memset(level,0,sizeof(level));
    vis[sx][sy]=1;
    queue<pii>q;
    q.push(pii(sx,sy));

    while(!q.empty()){
        pii top=q.front();
        q.pop();
        ll x=top.first;
        ll y=top.second;
        for(ll k=0;k<8;k++){
            ll tx=x+dx[k];
            ll ty=y+dy[k];
            if(tx>=1 && tx<=1000 && ty>=1 && ty<=1000 && vis[tx][ty]==0){
                vis[tx][ty]=1;
                level[tx][ty]=level[x][y]+1;
                q.push(pii(tx,ty));
            }
        }

    }

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>>t;
    bfs(1,1);
    while(t--){
        ll sx,sy;
        cin>>sx>>sy;
        ll res=level[sx][sy];
        cout<<res<<endl;

    }
}

