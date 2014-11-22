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
#define pf printf
#define sf scanf
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define MX 1100
struct point{
    int x,y;
}sor[550],des[550];
int jTime[550],tTime[550];
vi G[MX];
int pr[MX];
bool vis[MX];
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
    int tc,n;
    SDi(tc);
    while(tc--){
        SDi(n);
        int h,m;
        rep(i,n){
            sf("%d:%d %d %d %d %d",&h,&m,&sor[i].x,&sor[i].y,&des[i].x,&des[i].y);
            jTime[i] = h*60+m;
            tTime[i] = abs(sor[i].x - des[i].x) + abs(sor[i].y-des[i].y);
        }
        int trsTime;
        rep(i,n){
            FOR(j,i+1,n-1){
                trsTime = abs(des[i].x - sor[j].x) + abs(des[i].y-sor[j].y);
                if(jTime[j]>jTime[i]+tTime[i]+trsTime){
                    G[i].pb(j+n);
                }
            }
        }
        int fdpr=0,rt;
        memdp(pr);
        rep(i,n){
            memca(vis);
            rt = dfs(i);
            fdpr+=rt;
        }
        pf("%d\n",n-fdpr);
        rep(i,MX) G[i].clear();
    }
    return 0;
}
