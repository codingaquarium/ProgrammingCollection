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

#define MAX 10010

int main()
{
#ifndef ONLINE_JUDGE
	READ("in.txt");
#endif
    int m,n,pos[1001],num[1001],r;
    vpii mat[MAX],trans[MAX];
    while(SD2(m,n)==2){
        rep(i,m){
            SDi(r);
            rep(j,r) SDi(pos[j]);
            rep(j,r) SDi(num[j]);
            rep(j,r) mat[i].pb(pmp( pos[j]-1,num[j] ) );
        }
        rep(i,m) rep(j,mat[i].size()){
            pii p = mat[i][j];
            trans[ p.ft ].pb(pmp(i+1,p.sd ) );
        }
        pf("%d %d\n",n,m);
        rep(i,n){
            pf("%u",trans[i].size());
            rep(j,trans[i].size())
                pf(" %d",trans[i][j].ft);
            puts("");
            rep(j,trans[i].size()){
                pf("%d",trans[i][j].sd);
                if(j != trans[i].size()-1) pf(" ");
            } puts("");
        }
        rep(i,MAX) mat[i].clear(),trans[i].clear();
     }
    return 0;
}
