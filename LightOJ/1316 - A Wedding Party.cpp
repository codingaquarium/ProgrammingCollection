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
#define MAX 10001

vector<int> edge[MAX], cost[MAX];
vector<int> redge[20], rcost[20];

int shoploc[20],shopID[MAX],d[MAX],pops[1<<15],infs,costs[17][1<<15];;
struct data {
    int city, dist,masks;
    bool operator < ( const data& p ) const {
        return dist > p.dist;
    }
};

void dijkstra(int source) {
    memsp(d);
    infs = d[0];
    priority_queue<data> q;
    data u, v;
    u.city = source, u.dist = 0;
    q.push( u );
    d[ source ] = 0;

    while( !q.empty() ) {
        u = q.top();
        q.pop();
        int ucost = d[ u.city ];
        for(size_t i=0; i<edge[u.city].size(); i++) {
            v.city = edge[u.city][i], v.dist = cost[u.city][i] + ucost;
            if( d[v.city] > v.dist ) {
                d[v.city] = v.dist;
                q.push( v );
            }
        }
    }
}

ii dijkstra2(int source, int destination,int ns) {
    memsp(costs);
    int mask=0;
    priority_queue<data> q;
    data u, v;
    if(source<ns) mask |= 1<<source;
    u.city = source, u.dist = 0,u.masks = mask;
    q.push( u );
    costs[ source ][mask] = 0;
    while( !q.empty() ) {
        u = q.top();
        q.pop();
        if(costs[u.city][u.masks]<u.dist) continue;
        int ucost = costs[ u.city ][u.masks];
        for(size_t i=0; i<redge[u.city].size(); i++) {
            v.city = redge[u.city][i], v.dist = rcost[u.city][i] + ucost,v.masks = u.masks;
            if(v.city<ns) v.masks |= 1<<v.city;
            if( costs[v.city][v.masks] > v.dist ) {
                costs[v.city][v.masks] = v.dist;
                q.push( v );
            }
        }
    }
    int best_cost = infs,bits = 0,nb;
    rep(i,1<<15){
        if(costs[destination][i]<infs){
            nb = pops[i];
            if(nb>bits){
                bits = nb;
                best_cost = costs[destination][i];
            } else if(nb==bits){
                best_cost = min(best_cost,costs[destination][i]);
            }
        }
    }
    return pmp(best_cost,bits);
}

int main (int argc, char **argv) {
#ifndef ONLINE_JUDGE
    READ("in.txt");
//    cout<<"hello world! "<<__builtin_popcount(7)<<endl;
#endif
    int tc,cas=0,n,m,s,u,v,w,j;
    rep(i,1<<15) pops[i] = __builtin_popcount(i);
    SDi(tc);
    while(tc--){
        SD3(n,m,s);
        j=0;
        memdp(shopID);
        rep(i,s){
            SDi(u);
            shoploc[j]= u;
            shopID[u] = j;
            j++;
        }
        if(shopID[0]==-1){
            shoploc[j] = 0;
            shopID[0] = j;
            j++;
        }
        if(shopID[n-1]==-1){
            shoploc[j] = n-1;
            shopID[n-1] = j;
            j++;
        }
        rep(i,m){
            SD3(u,v,w);
            edge[u].pb(v);
            cost[u].pb(w);
        }
        rep(i,j){
            redge[i].clear(),rcost[i].clear();
//            cout<<shoploc[i]<<endl;
            dijkstra(shoploc[i]);
            rep(k,n){
//                cout<<shopID[k]<<"--"<<d[k]<<endl;
                if(k!=shoploc[i] and shopID[k]>=0 and d[k]<infs){
//                    cout<<shopID[k]<<"--"<<d[k]<<endl;
                    redge[i].pb(shopID[k]);
                    rcost[i].pb(d[k]);
                }
            }
        }
        ii ans = dijkstra2(shopID[0],shopID[n-1],s);
        if(ans.ft<infs) pf("Case %d: %d %d\n",++cas,ans.sd,ans.ft);
        else pf("Case %d: Impossible\n",++cas);
        rep(i,n) edge[i].clear(),cost[i].clear();
    }
    return 0;
}
