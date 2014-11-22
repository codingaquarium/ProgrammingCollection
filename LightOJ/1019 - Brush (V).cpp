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
#define PI 3.14159265358979323846264338327950
#define pb(x) push_back(x)
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

vpii edge[110];
int n, e, inf;

struct data {
    int city, dist, par;
    bool operator < ( const data &p ) const {
        return dist > p.dist;
    }
};

int dijkstra(int source, int destination) {
    int d[110];
    memsp(d);
    inf = d[0];
    priority_queue<data> q;
    data u, v;
    u.city = source, u.dist = 0;
    q.push( u );
    d[ source ] = 0;

    while ( !q.empty() ) {
        u = q.top(); q.pop();
        int ucost = d[ u.city ];

        for (size_t i = 0; i < edge[u.city].size(); i++) {
            v.city = edge[u.city][i].ft, v.dist = edge[u.city][i].sd + ucost;
            if ( d[v.city] > v.dist ) {
                d[v.city] = v.dist;
                q.push( v );
            }
        }
    }
    return d[ destination ];
}

int main() {
    //READ("in.txt");
    int tc, cas = 1;
    cin >> tc;
    while (tc--) {
        pf("Case %d: ", cas++);
        SD2(n, e);
        rep(i, e) {
            int x, y, w;
            SD3(x, y, w);
            edge[x].pb(pmp(y, w));
            edge[y].pb(pmp(x, w));
        }
        int sp = dijkstra(1, n);
        if (sp == inf) puts("Impossible");
        else pf("%d\n", sp);
        int c = 110;
        while (c--) edge[c].clear();
    }
    return 0;
}
