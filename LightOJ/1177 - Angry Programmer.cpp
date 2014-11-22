/*
http://codingaquarium.wordpress.com/
Shaikh shiam Rahman
Khunla University of Engineering and Technology(KUET)

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

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

#define MX 250

int par[MX],f,t,s,dis[MX],vis[MX],flow[MX][MX];
vii G[MX];
si Set;
void dfs(int u){
    int v;
    Set.insert(u);
    vis[u] = 1;
    rep(i,G[u].size()){
        v = G[u][i].ft;
        if(flow[u][v]>0 and vis[v]==0)
            dfs(v);
    }
}

void minCut(){
    int u,v;
    Set.clear();
    dfs(s);
    for(si::iterator it = Set.begin(); it!=Set.end();++it){
        u = *it;
        rep(i,G[u].size()){
            v = G[u][i].ft;
            if(vis[v]==0 and flow[u][v]<=0)
                pf("%d %d\n",u,v);
        }
    } puts("");
}

void agumentPath(int v,int minEdge){
    if(v==s){
        f = minEdge;
        return;
    }
    else if(vis[v]){
        agumentPath(par[v],min(minEdge,flow[ par[v] ][v]));
        flow[par[v]][v]-=f;
        flow[v][par[v]]+=f;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
	READ("in.txt");
#endif
    int max_flow,tc,cas=0,m,N1=1,N,N2;
    SDi(tc);
    while(tc--){
        pf("Case %d: ",++cas);
        memca(flow);
        int x,y,w;
        SD2(N,m);
        N2 = N+1;
        G[0].pb(pmp(1,INF));
        G[1].pb(pmp(0,0));
        flow[0][1] = INF;
        G[2*N].pb(pmp(N*2+1,INF));
        G[N*2+1].pb(pmp(2*N,0));
        flow[2*N][N*2+1] = INF;
        G[1].pb(pmp(N2,INF));
        G[N2].pb(pmp(1,0));
        flow[1][N2] = INF;
        G[N].pb(pmp(N*2,INF));
        G[N*2].pb(pmp(N,0));
        flow[N][N*2] = INF;
        rep(i,N-2){
            SDi(w);
            flow[N1+1+i][N2+1+i] = w;
            G[N1+1+i].pb(pmp(N2+1+i,w));
            G[N2+1+i].pb(pmp(N1+1+i,0));
        }
        rep(i,m){
            SD3(x,y,w);
            x--,y--;
            flow[N2+x][N1+y] = w;
            flow[N2+y][N1+x] = w;
            G[N2+x].pb(pmp(N1+y,w));
            G[N2+y].pb(pmp(N1+x,w));
        }
        memca(par),max_flow = 0;
        s = 0,t = 2*N+1;
        while(1){
            f = 0;
            memca(dis),memca(vis);
            queue< int > q;
            q.push(s), dis[s] = 0, vis[s] = 1;
            while(q.size()){
                int v,u = q.front(); q.pop();
                if(u==t) break;
                rep(i,G[u].size()){
                    v = G[u][i].ft;
                    if(vis[v]==0 and flow[u][v] > 0){
                        vis[v] = 1, dis[v] = dis[u] + 1;
                        par[v] = u;
                        q.push(v);
                    }
                }
            }
            agumentPath(t,INF);
            if(f==0) break;
            max_flow+=f;
        }
//        memca(vis),minCut();
        pf("%d\n",max_flow);
        rep(i,MX) G[i].clear();
    }
    return 0;
}
