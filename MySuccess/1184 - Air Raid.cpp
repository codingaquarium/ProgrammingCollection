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
#define pii pair<int,int>
#define pmp make_pair
#define ft first
#define sd second
#define vi vector<int>
#define vpii vector<pii>
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

vi G[150];
int pr[150];
bool vis[150];
int dfs(int u){
    if(vis[u]) return 0;
    vis[u] = true;
    int r;
    rep(i,G[u].size()){
        r = G[u][i];
        if(pr[r]==-1 or dfs(pr[r])){
            pr[r] = u;
            return 1;
        }
    }
    return 0;
}

int main()
{
#ifndef ONLINE_JUDGE
    READ("in.txt");
    cout<<"Hello world!"<<endl;
#endif
    int tc,n,e;
    SDi(tc);
    while(tc--){
        SD2(n,e);
        rep(i,e){
            int x,y;
            SD2(x,y);
            G[x].pb(y);
        }
        int fdpr=0,rt;
        memdp(pr);
        repl(i,n){
            memca(vis);
            rt = dfs(i);
            fdpr+=rt;
        }
        pf("%d\n",n-fdpr);
        rep(i,150) G[i].clear();
    }
    return 0;
}
