/*
 * cf_181_2_C.cpp
 *
 *  Created on: Oct 31, 2013
 *      Author: DELL
 */

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

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define MAX 20010
const int mod = 1000003;
const int mx = (int)1e6;
i64 fac[mx];

struct Euclid {
    i64 x, y, d;
//    Euclid() {}
    Euclid( i64 xx, i64 yy, i64 dd ) { x = xx, y = yy, d = dd; }
};
i64 gcd( i64 a, i64 b ) { return !b ? a : gcd ( b, a % b ); }
Euclid egcd( i64 a, i64 b ) { // Input a, b; Output x, y, d; ax + by = d, d = gcd(a,b)
    if( !b ) return Euclid ( 1, 0, a );
    Euclid r = egcd ( b, a % b );
    return Euclid( r.y, r.x - a / b * r.y, r.d );
}
i64 modularInverse( i64 a, i64 n ) { // given a and n, returns x, ax mod n = 1
    Euclid t = egcd( a, n );
    if( t.d > 1 ) return 0;
    i64 r = t.x % n;
    return r < 0 ? r + n : r;
}

void fact(){
	fac[0] = 1;
	repl(i,(int)1e6){
		fac[i] = (fac[i-1]*i)%mod;
	}
}


int main (int argc, char **argv) {
#ifndef ONLINE_JUDGE
    READ("in.txt");
    cout<<"hello world!"<<endl;
#endif
    int n,k,tc,cas=0;
    SDi(tc);
    fact();
    while(tc--){
    	SD2(n,k);
    	i64 div = fac[n-k]*fac[k];
    	i64 r = modularInverse(div,mod);
    	i64 ans = (fac[n]*(r%mod) )%mod;
    	pf("Case %d: ",++cas);
    	cout<<ans<<endl;
    }
    return 0;
}



