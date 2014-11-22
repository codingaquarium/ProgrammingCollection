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

int G[16][16],deg[16],odd,total,dp[1 << 17];
vector< pair< int,pii > > E;
pair< int,pii > edge;


int solve(int mask){
    if(mask == 0) return 0;
    if(dp[mask] != -1) return dp[mask];
    int ret = INF;
    rep(i,E.size()){
        if( (mask & 1<<E[i].sd.ft) && (mask & 1<<E[i].sd.sd) ){
//            int m = 1<<E[i].sd.ft, n = 1<<E[i].sd.sd, w = E[i].ft;
            int nmask = mask & ~(1<<E[i].sd.ft) & ~(1<<E[i].sd.sd);
            ret = min(ret , E[i].ft + solve(nmask));
        }
    }
    return dp[mask] = ret;
}

int main()
{
#ifndef ONLINE_JUDGE
	READ("in.txt");
#endif
    int tc,cas=1;
    cin>>tc;
    while(tc--){
        E.clear();
        pf("Case %d: ",cas++);
        int n,m;
        SD2(n,m);
        rep(i,n){
            deg[i] = 0;
            rep(j,n)
                G[i][j] = 100000000;
        }
        total = odd = 0;
        rep(i,m){
            int x,y,w;
            SD3(x,y,w);
            x--,y--;
            deg[x]++,deg[y]++;
            G[x][y] = G[y][x] = min(G[x][y],w);
            total+=w;
        }
        int mask = 0;
        rep(i,n)
            if(deg[i]&1) odd++, mask |= 1<<i;

        if(odd == 0){
            pf("%d\n",total);
            continue;
        }
        rep(k,n) rep(i,n) rep(j,n) G[i][j] = min( G[i][j] , G[i][k]+G[k][j] );

        rep(i,n)
            if(deg[i]&1)
                FOR(j,i+1,n-1)
                    if(deg[j]&1)
                        E.pb(pmp( G[i][j],pmp(i,j) ));
        if(E.size()==1){
            pf("%d\n",total + E.at(0).ft);
            continue;
        }
        memdp(dp);
        pf("%d\n",solve(mask) + total);
    }
    return 0;
}
