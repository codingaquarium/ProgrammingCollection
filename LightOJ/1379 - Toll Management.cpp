/*
http://codingaquarium.wordpress.com/
Shaikh shiam Rahman
Khunla University of Engineering and Technology(KUET)
idea : http://lbv-pc.blogspot.com/2012/10/highest-paid-toll.html
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
#define MAX 10009

vector<int> redge[MAX],edge[MAX];
vector< i64 >cost[MAX], rcost[MAX];
int n,m;
i64 d[MAX],rd[MAX],p;

struct data {
    int city;
    i64 dist;
    bool operator < ( const data& p ) const {
        return dist > p.dist;
    }
};

void dijkstra(int source) {
    priority_queue<data> q;
    data u, v;
    u.city = source, u.dist = 0;
    q.push( u );
//    memsp(d);
    d[ source ] = 0;
    while( !q.empty() ) {
        u = q.top();
        q.pop();
        for(unsigned i=0; i<edge[u.city].size(); i++) {
            v.city = edge[u.city][i], v.dist = d[u.city]+cost[u.city][i];
            if(d[v.city]>v.dist and v.dist<=p) {
                d[v.city] = v.dist;
                q.push( v );
            }
        }
    }
}

void rdijkstra(int source) {
    priority_queue<data> q;
    data u, v;
    u.city = source, u.dist = 0;
    q.push( u );
//    memsp(rd);
    rd[ source ] = 0;

    while( !q.empty() ) {
        u = q.top();
        q.pop();
        for(unsigned i=0; i<redge[u.city].size(); i++) {
            v.city = redge[u.city][i], v.dist = rd[u.city]+rcost[u.city][i];
            if(rd[v.city]>v.dist and v.dist<=p) {
                rd[v.city] = v.dist;
                q.push( v );
            }
        }
    }
}

int main (int argc, char **argv) {
#ifndef ONLINE_JUDGE
    READ("in.txt");
#endif
    int tc,cas=0,s,t,u,v,w;
    SDi(tc);
    while(tc--){
        sf("%d %d %d %d %lld",&n,&m,&s,&t,&p);
        rep(i,m){
            SD3(u,v,w);
            edge[u].pb(v);
            cost[u].pb(w);
            redge[v].pb((i64)u);
            rcost[v].pb((i64)w);
        }
        rep(i,n+2) d[i] = rd[i] = (i64)1e10;
        dijkstra(s);
        rdijkstra(t);
        i64 ans = -1L;
        repl(i,n){
//            cout<<i<<": "<<d[i]<<" -- ";
            rep(j,edge[i].size()){
                u = i, v = edge[i][j];
//                cout<<v<<": "<<rd[v]<<" ";
                if(d[u]+rd[v]+cost[i][j]<=p){
//                    cout<<"\ncounted: "<<u<<" "<<v<<endl;
                    ans = max(ans,cost[i][j]);
                }
            } //puts("");
        }
        pf("Case %d: %lld\n",++cas,ans);
        rep(i,n+2) edge[i].clear(),redge[i].clear(),cost[i].clear(),rcost[i].clear();
    }
    return 0;
}
