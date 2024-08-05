#include <bits/stdc++.h>
#define fo(i, d, c) for (int i = d; i <= c; i++)
#define fod(i, c, d) for (int i = c; i >= d; i--)
#define maxn 110
#define N 1010
#define fi first
#define se second
#define pb emplace_back
#define en cout << "\n";
#define inf (int)1e9
#define pii pair<int, int>
#define vii vector<pii>
#define lb(x) x & -x
#define bit(i, j) ((i >> j) & 1)
#define offbit(i, j) (i ^ (1LL << j))
#define onbit(i, j) (i | (1LL << j))
#define vi vector<int>
template <typename T1, typename T2>
bool minimize(T1 &a, T2 b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}
template <typename T1, typename T2>
bool maximize(T1 &a, T2 b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}
using namespace std;
const int nsqrt = 450;
const int mod = 1e9 + 7;
int n,m,k;
vii ke[maxn];
int d[1 << 10][maxn];
int id[maxn];
main()
{
#define name "TASK"
    if (fopen(name ".inp", "r"))
    {
        freopen(name ".inp", "r", stdin);
        freopen(name ".out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;
    fo(i,0,(1 << k)) fo(j,1,n) d[i][j] = inf;
    fo(i,1,k)
    {
        int x;
        cin >> x;
        d[1 << (i - 1)][x] = 0;
        id[x] = i;
    }
    fo(i,1,m)
    {
        int u,v,w;
        cin >> u >> v >> w;
        ke[u].pb(v,w);
        ke[v].pb(u,w);
    }
    fo(mask,0,(1 << k) - 1)
    {
        fo(pre,0,((1 << k) - 1) / 2) if((mask & pre) == pre)
        {
            int suf = mask ^ pre;
            fo(i,1,n) minimize(d[mask][i],d[pre][i] + d[suf][i]);
        }
        priority_queue<pii,vii,greater<pii>> q;
        fo(i,1,n) if(d[mask][i] < inf) q.push({d[mask][i],i});
        while(q.size())
        {
            auto [du,u] = q.top();
            q.pop();
            if(d[mask][u] != du) continue;
            for(auto [v,w] : ke[u])
            {
                if(minimize(d[mask][v],du + w)) q.push({du + w,v});
            }
        }
    }
    cout << *min_element(d[(1 << k) - 1] + 1,d[(1 << k) - 1] + n + 1);
}
