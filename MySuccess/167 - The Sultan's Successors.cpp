/*
http://codingaquarium.wordpress.com/
Shaikh shiam Rahman
Khunla University of Engineering and Technology(KUET)
UVa - 167 - The Sultan's Successors
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

int n=8;
int x[10],cnt=0,a[10][10];
vi v[100];

bool place(int k,int i){
    rep(j,k)
        if(x[j]==i or abs(x[j] - i)==abs(j-k))
            return false;
    return true;
}

void bktk(int k){
    if(k==n) return;
    rep(i,n){
        if(place(k,i)){
            x[k] = i;
            if(k == n-1){
                rep(j,n){
                    v[cnt].pb(x[j]);
                } cnt++;
            } else
                bktk(k+1);
        }
    }
}

int main(){
#ifndef ONLINE_JUDGE
	READ("in.txt");
#endif
    bktk(0);
    int tc,sum,ans;
    cin>>tc;
    while(tc--){
        rep(i,8) rep(j,8) SDi(a[i][j]);
        ans = -(1<<28);
        rep(j,cnt){
            sum = 0;
            rep(i,8)
                sum += (a[i][ v[j][i] ]);
            ans = max(ans,sum);
        } pf("%5d\n",ans);
    }
    return EXIT_SUCCESS;
}
