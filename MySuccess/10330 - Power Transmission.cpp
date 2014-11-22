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
    int max_flow,m,B,D,N1=1,N,N2;
    while(SDi(N)==1){
        memca(flow);
        int x,y,w;
        N2 = N+1;
        rep(i,N){
            SDi(w);
            flow[N1+i][N2+i] = w;
            G[N1+i].pb(pmp(N2+i,w));
            G[N2+i].pb(pmp(N1+i,0));
        }
        SDi(m);
        rep(i,m){
            SD3(x,y,w);
            x--,y--;
            flow[N2+x][N1+y] = w;
            G[N2+x].pb(pmp(N1+y,w));
            G[N1+y].pb(pmp(N2+x,0));
        }
        SD2(B,D);
        rep(i,B){
            SDi(x);
            x--;
            flow[0][N1+x] = INF;
            G[0].pb(pmp(N1+x,INF));
            G[N1+x].pb(pmp(0,0));
        }
        rep(i,D){
            SDi(x);
            x--;
            flow[N2+x][2*N+1] = INF;
            G[N2+x].pb(pmp(2*N+1,INF));
            G[2*N+1].pb(pmp(N2+x,0));
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
        pf("%d\n",max_flow);
        rep(i,MX) G[i].clear();
    }
    return 0;
}
