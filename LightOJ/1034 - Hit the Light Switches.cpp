/*
Shiakh Shiam Rahman
UVa : 11770 - Lighting Away
*/
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

#define N 100010
int n, m;
vi G[N];
vi order;
bool visit[N];

void dfs(int u) {
    if (!visit[u]) {
        visit[u] = true;
        rep(i, G[u].size()) {
            int v = G[u][i];
            dfs(v);
        }
    }
    order.pb(u);
}

void find(int u) {
    if (!visit[u]) {
        visit[u] = true;
        rep(i, G[u].size()) {
            int v = G[u][i];
            find(v);
        }
    }
}

int main() {
    //    READ("in.txt");
    int tc, cas = 1;
    cin >> tc;
    while (tc--) {
        pf("Case %d: ", cas++);
        SD2(n, m);
        rep(i, m) {
            int u, v;
            SD2(u, v);
            G[u].pb(v);
        }
        memca(visit);
        order.clear();
        repl(i, n)
        if (!visit[i])
            dfs(i);
        //puts("back DFS");
        memca(visit);
        int ans = 0;
        for (int i = order.size() - 1; i >= 0; i--) {
            int v  = order[i];
            if (!visit[v]) {
                find(v);
                ans++;
            }
        }
        printf("%d\n", ans);
        int i = n + 2;
        order.clear();
        while (i--) G[i].clear();
    }
    return 0;
}
