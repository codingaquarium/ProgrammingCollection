/*
http://codingaquarium.wordpress.com/
Shaikh shiam Rahman
Khunla University of Engineering and Technology(KUET)

*/

#include <bits/stdc++.h>
using namespace std;

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
#define ii pair<int,int>
#define pmp make_pair
#define ft first
#define sd second
#define vi vector<int>
#define vii vector<ii>
#define si set<int>
#define msi map<string , int >
#define mis map<int , string >
typedef long long i64;
typedef unsigned long long ui64;

/** function **/

#define SDi(x) sf("%d",&x)
#define SDl(x) sf("%lld",&x)
#define SDs(x) sf("%s",x)
#define SD2(x,y) sf("%d%d",&x,&y)
#define SD3(x,y,z) sf("%d%d%d",&x,&y,&z)
#define pf printf
#define sf scanf
#define pfcas(x) pf("Case %d: ",x)

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define MAX 101

vector<int> edge[MAX], cost[MAX];
int n,m,fuelcost[MAX],inf;

struct data {
    int city, total,tank;
    bool operator < ( const data& p ) const {
        return total > p.total;
    }
};

int dijkstra(int source, int des,int cap) {
    int d[MAX][MAX];
    priority_queue<data> q;
    data u, v;
    u.city = source, u.total = 0,u.tank = 0;
    q.push( u );
    memsp(d);
    inf = d[0][0];
    d[ source ][0] = 0;

    while( !q.empty() ) {
        u = q.top();
        q.pop();
        if(d[u.city][u.tank]<u.total) continue;
        if(u.city==des) return d[u.city][u.tank];
        for(unsigned i=0; i<edge[u.city].size(); i++) {
            v.city = edge[u.city][i], v.total = u.total, v.tank = u.tank-cost[u.city][i];
            if(cost[u.city][i]>cap) continue;
            if(u.tank>=cost[u.city][i] and d[v.city][u.tank-cost[u.city][i] ] > d[u.city][u.tank]){
                d[v.city][u.tank-cost[u.city][i] ] = d[u.city][u.tank];
                q.push(v);
            }
        }
        if(u.tank<cap){
            d[u.city][u.tank+1] = d[u.city][u.tank] + fuelcost[u.city];
            u.tank++,u.total+=fuelcost[u.city];
            q.push(u);
        }
    } return inf;
}

int main () {
#ifndef ONLINE_JUDGE
    READ("in.txt");
    cout<<"hello world!"<<endl;
#endif
    int tc,cas=0,u,v,w,s,t,c,q;
    SDi(tc);
    while(tc--){
        SD2(n,m);
        rep(i,n) SDi(fuelcost[i]);
        rep(i,m){
            SD3(u,v,w);
            edge[u].pb(v);
            cost[u].pb(w);
            edge[v].pb(u);
            cost[v].pb(w);
        }
        SDi(q);
        pf("Case %d:\n",++cas);
        while(q--){
            SD3(c,s,t);
            int ans = dijkstra(s,t,c);
            if(ans==inf) puts("impossible");
            else pf("%d\n",ans);
        }
        rep(i,n) edge[i].clear(),cost[i].clear();
    }
    return 0;
}
