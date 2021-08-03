#include <bits/stdc++.h>
#define INF 1000000001
typedef long long ll;
using namespace std;
ll seg[800020], input[200005];

void build_seg(ll pos, ll low, ll high)
{

    if (low == high)
    {
        seg[pos] = input[low];
        return;
    }
    ll mid = (low + high) >> 1;

    build_seg(2 * pos, low, mid);
    build_seg(2 * pos + 1, mid + 1, high);
    seg[pos] = seg[2 * pos] + seg[2 * pos + 1];
}
ll query(ll si, ll ss, ll se, ll qs, ll qe)
{
    if (qe < ss || qs > se)
        return 0;

    if (ss >= qs && se <= qe)
        return seg[si];

    ll mid = (ss + se) >> 1;
    ll l = query(2 * si, ss, mid, qs, qe);
    ll r = query(2 * si + 1, mid + 1, se, qs, qe);
    return l + r;
}
void update(ll si, ll ss, ll se, ll qi)
{

    if (ss == se)
    {
        seg[si] = input[ss];
        return;
    }
    ll mid = (ss + se) / 2;
    if (qi <= mid)
    {
        update(2 * si, ss, mid, qi);
    }
    else
    {
        update(2 * si + 1, mid + 1, se, qi);
    }
    seg[si] = seg[2 * si] + seg[2 * si + 1];
}

int main()
{
    //check
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t, n, q, l, r;

    ll kase = 1;
    ll c=1;
    while (scanf("%lld", &n) && n != 0)
    {
        if(c==0){
            printf("\n");
        }
        memset(seg, INF, n);
        for (ll i = 1; i <= n; i++)
        {
            scanf("%lld", &input[i]);
        }
        
        printf("Case %lld:\n", kase++);
        build_seg(1, 1, n);
        char querys[4];
        while(scanf("%s", querys) != EOF && querys[0] != 'E') {    
            
            if (querys[0] == 'S')
            {
                ll x, y;
                scanf("%lld%lld", &x, &y);
                input[x] = y;
                update(1, 1, n, x);
            }
            else if (querys[0] == 'M')
            {
                ll l, r;

                scanf("%lld%lld", &l, &r);
                ll res = query(1, 1, n, l, r);
                printf("%lld\n", res);
            }
            
        }
        c=0;//
    }
}