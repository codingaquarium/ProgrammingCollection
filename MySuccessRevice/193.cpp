/*
http://codingaquarium.wordpress.com/
Shaikh shiam Rahman
Khunla University of Engineering and Technology(KUET)

*/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
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
#define MX 110
#define white 1
#define black 2
int node;
struct scolor{
    int nBlack,status[MX];
}best,temp;
vi G[MX];
void bktk(int u){
    if(u==node+1){
        if(temp.nBlack > best.nBlack)
            best = temp;
            return;
    }
    bool canBalck = true;
    int sz = (int)G[u].size();
    rep(i,sz){
        int v = G[u][i];
        if(temp.status[v]==black){
            canBalck = false;
            break;
        }
    }
    if(canBalck){
        temp.status[u] = black;
        temp.nBlack++;
        bktk(u+1);
    }
    temp.status[u] = white;
    if(canBalck) temp.nBlack--;
    bktk(u+1);
}

int main(){
#ifndef ONLINE_JUDGE
	READ("in.txt");
#endif
    int tc,m,x,y;
    SDi(tc);
    while(tc--){
        SD2(node,m);
        rep(i,m){
            SD2(x,y);
            G[x].pb(y);
            G[y].pb(x);
        }
        memca(temp.status);
        best.nBlack = temp.nBlack = 0;
        bktk(1);
        pf("%d\n",best.nBlack);
        bool flag = false;
        repl(i,node){
            if(best.status[i]==black){
                if(flag) pf(" ");
                pf("%d",i);
                flag = true;
            }
        } puts("");
        rep(i,node+1) G[i].clear();
    }
    return 0;
}
