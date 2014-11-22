/*
http://codingaquarium.wordpress.com/
Shaikh shiam Rahman
Khunla University of Engineering and Technology(KUET)
idea : http://amrfeldfrawy.wordpress.com/2014/02/22/10944-nuts-for-nuts-uva/
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

char ch[50][50];
vii s;
int N,dp[16][1<<16];

int dis(int a,int b){
    return max( abs(s[a].ft-s[b].ft) ,abs(s[a].sd-s[b].sd) );
}

int call(int idx,int mask){
    if(mask==(1<<N)-1)
        return dis(idx,0);
    int &ans = dp[idx][mask];
    if(ans!=-1) return ans;
    ans = INT_MAX;
    rep(i,N){
        if( !( mask&(1<<i) ) )
            ans = min( ans,dis(idx,i)+call(i, mask|(1<<i)) );
    }
    return ans;
}
int main (int argc, char **argv) {
#ifndef ONLINE_JUDGE
    READ("in.txt");
#endif
    int n,m;
    while(~SD2(n,m)){
        getchar();
        rep(i,n) gets(ch[i]);
        rep(i,n) rep(j,m){
            if(ch[i][j]=='L') s.pb(pmp(i,j)), i = j = max(m,n)+1;
        }
        rep(i,n) rep(j,m){
            if(ch[i][j]=='#') s.pb(pmp(i,j));
        }
        memdp(dp);
        N = s.size();
        int ans = call(0,1);
        pf("%d\n",ans);
        s.clear();
    }
    return 0;
}
