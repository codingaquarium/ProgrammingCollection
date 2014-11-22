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
#define MX 220

template<class T> inline T sqr(T x){return x*x;}
double _dist(double x1,double y1,double x2,double y2){return sqrt(sqr(x1-x2)+sqr(y1-y2));}

int par[MX], f,t,s,v,dis[MX],vis[MX],flow[MX][MX];
vii G[MX];
pair< double,double > gopher[MX],holes[MX];
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
    int n,m,sec,d,max_flow;
    while(sf("%d %d %d %d",&n,&m,&sec,&d)==4){
        double x,y;
        memca(flow);
        rep(i,n){
            sf("%lf %lf",&x,&y);
            gopher[i] = pmp(x,y);
        }
        rep(i,m){
            sf("%lf %lf",&x,&y);
            holes[i] = pmp(x,y);
        }
        rep(i,n){
            G[1].pb(pmp(3+i,1));
            G[3+i].pb(pmp(1,0));
            flow[1][3+i] = 1;
            rep(j,m){
                double D1;
                D1 = _dist(gopher[i].ft,gopher[i].sd,holes[j].ft,holes[j].sd);
                if( (D1/(double)d - sec) < eps){
                    G[3+i].pb(pmp(3+n+j,1));
                    G[3+n+j].pb(pmp(3+i,0));
                    flow[3+i][3+n+j]=1;
                }
            }
        }
        rep(i,m){
            G[3+n+i].pb(pmp(2,1));
            G[2].pb(pmp(3+n+i,0));
            flow[3+n+i][2] = 1;
        }
        memca(par),max_flow = 0,s=1,t=2;
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
                        q.push(v);
                        par[v] = u;
                    }
                }
            }
            agumentPath(t,INF);
            if(f==0) break;
            max_flow+=f;
        }
        pf("%d\n",n - max_flow);
        rep(i,MX) G[i].clear();
    }
    return 0;
}
