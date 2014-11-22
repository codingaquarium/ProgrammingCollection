/*
http://codingaquarium.wordpress.com/
Shaikh shiam Rahman
Khunla University of Engineering and Technology(KUET)
idea : http://www.shafaetsplanet.com/planetcoding/?p=1211
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

int CAP;
int weight[31],cost[31],d[31];
int n;
int dp[31][1001],dir[31][1001];
vector< int > paths;

int func(int i, int w) {
    if (i >= n) return 0;

    if (dp[i][w] != -1) return dp[i][w];

    int profit1;
    if (w + weight[i] <= CAP)
        profit1 = cost[i] + func(i + 1, w + weight[i]);
    else
        profit1 = 0;
    int profit2 = func(i + 1, w);

    dp[i][w] = max(profit1, profit2);
    if(profit1>profit2) dir[i][w] = 1;
    else dir[i][w] = 2;
    return dp[i][w];
}

 void path(int i,int w){
    if(dir[i][w]==1){
        paths.pb(i);
        path(i+1,w+weight[i]);
    } else if(dir[i][w]==2) {
        path(i+1,w);
    }
 }

int main (int argc, char **argv) {
#ifndef ONLINE_JUDGE
    READ("in.txt");
#endif
    int w;
    bool pflag = false;
    while(cin>>CAP>>w){
        SDi(n);
        rep(i,n){
            SD2(d[i],cost[i]);
            weight[i] = 3*w*d[i];
        }
        if(pflag) puts("");
        pflag = true;
        memdp(dp);
        memdp(dir);
        int ans = func(0,0);
        pf("%d\n",ans);
        path(0,0);
        pf("%u\n",paths.size());
        rep(i,paths.size()) pf("%d %d\n",d[paths[i]],cost[paths[i]]);
        paths.clear();
    }
    return 0;
}
