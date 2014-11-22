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

int n,k,a[1010];
bool cheak(int ti){
    int total = 0,j=0;
    FOR(i,0,n){
        total+=a[i];
        if(total > ti){
            j++;
            total-=a[i];
            if(total<=0) return false;
            total = a[i];
        }
    }
    return j<=k;
}

int search(int mn,int mx){
    int mid;
    while(mn<mx){
        mid = (mn+mx)/2;
        if (cheak(mid)) mx = mid;
        else mn = mid+1;
    }
    return mx;
}

int main()
{
#ifndef ONLINE_JUDGE
	READ("in.txt");
#endif
    int tc,cas=1;
    cin>>tc;
    while(tc--) {
        pf("Case %d: ",cas++);
        SD2(n,k);
        int lo, hi;
        lo = hi = 0;
        rep(i,n+1){
            SDi(a[i]);
            if(a[i]>lo) lo = a[i];
            hi+=a[i];
        }
        int mymax = search(lo,hi);
        int total,j;
        total = j = 0;
        pf("%d\n",mymax);
        rep(i,n+1){
            total+=a[i];
            if(total > mymax || k-j > n-i){
                j++;
                total-=a[i];
                pf("%d\n",total);
                total = a[i];
            }
        }
        pf("%d\n",total);
    }
    return 0;
}
