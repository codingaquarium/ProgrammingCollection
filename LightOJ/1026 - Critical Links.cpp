#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <iomanip>

/*** typedef ***/

#define MEMSET_INF 127
#define MEMSET_HALF_INF 63
#define stream istringstream
#define rep(i,n) for(__typeof(n) i=0; i<(n); i++)
#define repl(i,n) for(__typeof(n) i=1; i<=(n); i++)
#define FOR(i,a,b) for(__typeof(b) i=(a); i<=(b); i++)
#define INF (1<<30)
#define PI acos(-1.0)
#define pb push_back
#define ppb pop_back
#define all(x) x.begin(),x.end()
#define mem(x,y) memset(x,y,sizeof(x))
#define memsp(x) mem(x,MEMSET_INF)
#define memdp(x) mem(x,-1)
#define memca(x) mem(x,0)
#define eps 1e-9
#define pii pair<int,int>
#define pmp make_pair
#define ft first
#define sd second
#define pf printf
#define sf scanf
#define vi vector<int>
#define vpii vector<pii>
#define si set<int>
#define msi map<string , int >
typedef long long i64;
typedef unsigned long long ui64;

/** function **/

#define SDi(x) sf("%d",&x)
#define SDl(x) sf("%lld",&x)
#define SDs(x) sf("%s",x)
#define SD2(x,y) sf("%d%d",&x,&y)
#define SD3(x,y,z) sf("%d%d%d",&x,&y,&z)

using namespace std;

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

#define white -1
#define N 10010
int dfscounter;
int dfs_num[N], dfs_low[N], dfs_parent[N];
bool arc_point[N];
int dfsroot, rootchild;
vi edge[N];
vpii B;
void  atri_bridge(int u) {
    dfs_num[u] = dfs_low[u] = dfscounter++;
    rep(i, edge[u].size()) {
        int v = edge[u][i];
        if (dfs_num[v] == white) {
            dfs_parent[v] = u;
            if (u == dfsroot) rootchild++;
            atri_bridge(v);
            if (dfs_low[v] >= dfs_num[u])
                arc_point[u] = true;
            if (dfs_low[v] > dfs_num[u])
                B.pb(u < v ? pmp(u, v) : pmp(v, u));
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        } else if (v != dfs_parent[u])
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
    }
}
int main() {
    int tc, n, cas = 1;
    SDi(tc);
    while (tc--) {
        SDi(n);
        pf("Case %d:\n", cas++);
        int u, m;
        rep(j, n) {
            sf("%d (%d)", &u, &m);
            rep(i, m) {
                int v;
                SDi(v);
                edge[u].pb(v);
            }
        }
        memdp(dfs_num);
        mem(arc_point, false);
        dfscounter = 0;
        rep(i, n) {
            if (dfs_num[i] == white)
                atri_bridge(i);
        }
        sort(all(B));
        pf("%d critical links\n", (int)B.size());
        rep(i, B.size()) {
            pf("%d - %d\n", B[i].ft, B[i].sd);
        }
        B.clear();
        int i = N;
        while (i--) edge[i].clear();
    }
    return 0;
}
