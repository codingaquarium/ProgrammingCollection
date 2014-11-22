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
int par[MX], f,t,s,v,dis[MX],vis[MX],flow[MX][MX];
vii G[MX];
vector< string > vstr[40],ansStr;

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
    int tc,nproblem,names,max_flow,cas=0;
    string str;
    SDi(tc);
    while(tc--){
        pf("Case #%d:\n",++cas);
        memca(flow);
        SDi(nproblem);
        rep(i,nproblem){
            flow[0][i+1] = 1;
            G[0].pb(pmp(i+1,0));
            G[i+1].pb(pmp(0,0));
            SDi(names);
            rep(j,names){
                cin>>str;
                str[0] = toupper(str[0]);
                int v = nproblem + 1 + (str[0] - 'A');
                flow[i+1][v] = 1;
                G[i+1].pb(pmp(v,0));
                G[v].pb(pmp(i+1,0));
                vstr[i+1].pb(str);
            }
        }
        rep(i,nproblem){
            flow[nproblem+1+i][2*nproblem+1] = 1;
            G[nproblem+1+i].pb(pmp(2*nproblem+1,0));
            G[2*nproblem+1].pb(pmp(nproblem+1+i,0));
        }
        memca(par),max_flow = 0,s =0,t = 2*nproblem+1;
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
        rep(i,nproblem){
            rep(j,G[i+1].size()){
                int v = G[i+1][j].ft;
                if(flow[v][i+1]){
                    ansStr.pb(vstr[i+1][j-1]);//cout<<vstr[i+1][j]<<endl;
                    break;
                }
            }
        }
        sort(all(ansStr));
        rep(i,ansStr.size()){
            cout<<ansStr[i][0];
            repl(k,ansStr[i].size()-1)
               cout<<(char)tolower(ansStr[i][k]);
            cout<<endl;
        }
        rep(i,MX) G[i].clear();
        rep(i,40) vstr[i].clear();
        ansStr.clear();
    }
    return 0;
}
