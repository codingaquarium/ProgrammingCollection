/*
http://codingaquarium.wordpress.com/
Shaikh shiam Rahman
Khunla University of Engineering and Technology(KUET)

*/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

/*** typedef ***/

#define MEMSET_LONG_MAX 127
#define MEMSET_HALF_LONG_MAX 63
#define stream istringstream
#define rep(i,n) for(__typeof(n) i=0; i<(n); i++)
#define repl(i,n) for(__typeof(n) i=1; i<=(n); i++)
#define FOR(i,a,b) for(__typeof(b) i=(a); i<=(b); i++)
#define inf (1<<30)
#define PI acos(-1.0)
#define pb push_back
#define ppb pop_back
#define all(x) x.begin(),x.end()
#define mem(x,y) memset(x,y,sizeof(x))
#define memsp(x) mem(x,MEMSET_LONG_MAX)
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

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define Pot(u,v) (d[u] + pi[u] - pi[v])
#define NN 150

int deg[NN],adj[NN][NN],par[NN],pi[NN];
i64 d[NN],fnet[NN][NN],cap[NN][NN],cost[NN][NN];
bool dijkstra( int n, int s, int t ) {
    int i;
    for( i = 0; i < n; i++ ) d[i] = LONG_MAX, par[i] = -1;
    d[s] = 0;
    par[s] = -n - 1;
    while( 1 ) {
        int u = -1;
        i64 bestD = LONG_MAX;
        for( i = 0; i < n; i++ ) if( par[i] < 0 && d[i] < bestD ) bestD = d[u = i];
        if( bestD == LONG_MAX ) break;
        par[u] = -par[u] - 1;
        for( i = 0; i < deg[u]; i++ ) {
            int v = adj[u][i];
            if( par[v] >= 0 ) continue;
            if( fnet[v][u] && d[v] > Pot(u,v) - cost[v][u] )
                d[v] = Pot( u, v ) - cost[v][u], par[v] = -u - 1;
            if( fnet[u][v] < cap[u][v] && d[v] > Pot(u,v) + cost[u][v] )
                d[v] = Pot(u,v) + cost[u][v], par[v] = -u - 1;
        }
    }
    for( i = 0; i < n; i++ ) if( pi[i] < LONG_MAX ) pi[i] += d[i];
    return par[t] >= 0;
}
int mcmf3( int n, int s, int t, i64 &fcost ) {
    int u, v, flow = 0;
    fcost = 0;
    memca( deg );
    for( u = 0; u < n; u++ ) for( v = 0; v < n; v++ ) if( cap[u][v] || cap[v][u] )
                adj[u][ deg[u]++ ] = v;
    memca( fnet );
    memca( pi );
    while( dijkstra( n, s, t ) ) {
        i64 bot = LONG_MAX;
        for( v = t, u = par[v]; v != s; u = par[v = u] )
            bot = min ( bot, fnet[v][u] ? fnet[v][u] : ( cap[u][v] - fnet[u][v] ) );
        for( v = t, u = par[v]; v != s; u = par[v = u] )
            if( fnet[v][u] ) {
                fnet[v][u] -= bot;
                fcost -= bot * cost[v][u];
            } else {
                fnet[u][v] += bot;
                fcost += bot * cost[u][v];
            }
        flow += bot;
    }
    return flow;
}


int main()
{
#ifndef ONLINE_JUDGE
	READ("in.txt");
#endif
    int n,m,K;
    while(SD2(n,m)==2){
        memca(cap),memca(cost);
        int x,y;
        i64 limit;
        rep(i,m){
            SD2(x,y);
            cin>>limit;
            cap[x][y] = cap[y][x] = 1;
            cost[x][y] = cost[y][x] = limit;
        }
        cin>>cap[0][1]>>K;
        repl(i,n) repl(j,n){
            cap[i][j]*=K;
        }
        n++;
        i64 min_cost;
        mcmf3(n,0,n-1,min_cost);
        if (fnet[0][1] != cap[0][1])
			printf("Impossible.\n");
		else
            cout<<min_cost<<endl;
    }
    return 0;
}
