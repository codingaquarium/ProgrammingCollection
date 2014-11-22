/*
http://codingaquarium.wordpress.com/
Shaikh shiam Rahman
Khunla University of Engineering and Technology(KUET)
idea : http://code.google.com/p/my-solution-from-different-oj/source/browse/trunk/LightOJ/1321.cxx?spec=svn362&r=362
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
#define MAX 100

vector<int> edge[MAX];
vector<double> cost[MAX];
int n,m,S,K;
struct data {
    int city;
    double dist;
    bool operator < ( const data& p ) const {
        return dist < p.dist;
    }
};

double dijkstra(int source) {
    double d[MAX];
    fill(d,d+n,0);
    bool vis[MAX];
    memset(vis, false, sizeof vis);
    priority_queue<data> q;
    data u, v;
    u.city = source, u.dist = 1.0;
    q.push( u );
    d[ source ] = 1.0;

    while( !q.empty() ) {
        u = q.top();
        q.pop();
        if(vis[u.city]) continue;
        double ucost = d[ u.city ];
        for(size_t i=0; i<edge[u.city].size(); i++) {
            v.city = edge[u.city][i], v.dist = cost[u.city][i] * ucost;
            if( vis[v.city]==false and v.dist > d[v.city]  ) {
                d[v.city] = v.dist;
                q.push( v );
            }
        }
        vis[u.city] = true;
    }
    return d[n-1];
}
int main (int argc, char **argv) {
#ifndef ONLINE_JUDGE
    READ("in.txt");
#endif
    int tc,cas=0,u,v,w;
    SDi(tc);
    while(tc--){
        SD2(n,m);
        SD2(S,K);
        rep(i,m){
            SD3(u,v,w);
            edge[u].pb(v);
            cost[u].pb((double)w/100.0);
            edge[v].pb(u);
            cost[v].pb((double)w/100.0);
        }
        double answer = dijkstra(0);
        pf("Case %d: %.9lf\n",++cas,(double)(2.0*K*S)/answer);
        rep(i,n) edge[i].clear(),cost[i].clear();
    }
    return 0;
}
