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
#define MAX 1009

int comp[MAX],maps[MAX],ncomps,visits,vis[MAX],flag[MAX];
stack<int> st;
vector< int > G[MAX],R[MAX],S[MAX];
bool OK;
void dfs1(int u){
    int sz,v;
    sz = G[u].size();
    vis[u] = visits;
    rep(i,sz){
        v = G[u][i];
        if(vis[v]!=visits) dfs1(v);
    }
    st.push(u);
}
void dfs2(int u){
    int sz,v;
    sz = R[u].size();
    comp[u] = ncomps;
    vis[u] = visits;
    rep(i,sz){
        v = R[u][i];
        if(vis[v]!=visits) dfs2(v);
    }
}

void dfs(int u){
    if(S[u].size()>1){
        OK = false;
        return;
    }
    flag[u] = visits;
    if(S[u].size()) dfs(S[u][0]);
}
int main () {
#ifndef ONLINE_JUDGE
    READ("in.txt");
#endif
    int tc,cas=1,n,k,u,v,nodes;
    SDi(tc);
    while(tc--){
        SDi(n);
        memdp(maps);
        maps[0] = 0 , nodes = 1;
        rep(i,n){
            SDi(k);
            rep(j,k){
                SD2(u,v);
                if(maps[u]==-1) maps[u] = nodes++;
                if(maps[v]==-1) maps[v] = nodes++;
                G[maps[u]].pb(maps[v]);
                R[maps[v]].pb(maps[u]);
            }
        }
        visits++;
        rep(i,nodes){
            if(vis[i]!= visits)
                dfs1(i);
        }
//        cout<<nodes<<"--"<<st.size()<<endl;
        ncomps=0, visits++;
        while(st.size()){
            u = st.top();
            st.pop();
            if(vis[u]!=visits){
                dfs2(u);
                ncomps++;
            }
        }
//        cout<<nodes<<"--"<<st.size()<<endl;
        rep(i,nodes){
            rep(j,G[i].size()){
                v = G[i][j];
                if(comp[i]!=comp[v]) S[comp[i]].pb(comp[v]);
            }
        }
        OK = true;
        dfs(comp[0]);
        if(OK){
            rep(i,ncomps){
                if(flag[i]!=visits){
                    OK = false;
                    break;
                }
            }
        } pfcas(cas++);
        if(OK) puts("YES");
        else puts("NO");
        rep(i,MAX) G[i].clear(),R[i].clear(),S[i].clear();
    }
    return 0;
}
