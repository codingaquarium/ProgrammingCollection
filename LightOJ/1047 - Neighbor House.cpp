/*
http://codingaquarium.wordpress.com/
Shaikh shiam Rahman
Khunla University of Engineering and Technology(KUET)
idea : http://www.shafaetsplanet.com/planetcoding/?p=1158
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
#define MAX 20010
int n,dp[21][3],cost[21][3];
int call(int idx,int l){
    if(idx==n) return 0;
    int &ans = dp[idx][l];
    if(ans!=-1) return ans;
    ans = INT_MAX;
    rep(i,3){
        if(i==l) continue;
        ans = min(ans,cost[idx][i]+call(idx+1,i));
    }
    return ans;
}

int main (int argc, char **argv) {
#ifndef ONLINE_JUDGE
    READ("in.txt");
#endif
    int tc,cas=0;
    SDi(tc);
    while(tc--){
        SDi(n);
        memdp(dp);
        rep(i,n)
            rep(j,3)
                SDi(cost[i][j]);
        int ans = INT_MAX;
        rep(i,3){
            ans = min(ans,call(0,i));
        }
        pf("Case %d: %d\n",++cas,ans);
    }
    return 0;
}
