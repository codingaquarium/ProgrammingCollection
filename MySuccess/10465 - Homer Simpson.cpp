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
#define MAX 20010
int n,m,t;
int dp[10005];
int call(int burger,int time){
//    if(time==t) pf("first dp: %d %d\n",dp[t],time);
    if(time>=t) return dp[time] =  max(burger,dp[time]);
    int p1 = INT_MIN,p2 = INT_MIN;
    if(dp[time]!=-1) return dp[time];
    if(time+m<=t)
        p1 = call(burger+1,time+m);
    if(time+n<=t)
        p2 = call(burger+1,time+n);
//    if(time==t-m or time==t-n) pf("last dp: %d %d\n",dp[t],time);
    return dp[time]  = max(max(p1,p2),burger);
}

int main () {
#ifndef ONLINE_JUDGE
    READ("in.txt");
    WRITE("out.txt");
#endif
    while(~SD3(m,n,t)){
        if(m>n) swap(m,n);
        memdp(dp);
        call(0,0);
        if(dp[t]!=-1) pf("%d\n",dp[t]);
        else {
            int x=t;
            while(dp[x]==-1)x--;
            pf("%d %d\n",dp[x],t-x);
        }
    }
    return 0;
}
