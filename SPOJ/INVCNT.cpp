/*
http://codingaquarium.wordpress.com/
Shaikh shiam Rahman
Khunla University of Engineering and Technology(KUET)

*/
/**
idea:
1. http://www.shafaetsplanet.com/planetcoding/?p=1961
2. http://codeaspirant.wordpress.com/2013/10/09/spoj-problem-invcnt/
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
#define MAX (int)1e7+8
#define MX 200000+5
int tree[MAX];
int query(int idx) {
    int sum=0;
    while(idx>0) {
        sum+=tree[idx];
        idx -= idx & (-idx);
    }
    return sum;

}
void update(int idx, int x, int n) {
    while(idx<=n) {
        tree[idx]+=x;
        idx += idx & (-idx);
    }
}
int main (int argc, char **argv) {
#ifndef ONLINE_JUDGE
    READ("in.txt");
    cout<<"hello world!"<<endl;
#endif
    int tc,n,a[MX];
    i64 sum;
    SDi(tc);
    while(tc--){
        memca(tree);
        SDi(n);
        sum = 0L;
        int mymax = INT_MIN;
        rep(i,n) SDi(a[i]),mymax = max(mymax,a[i]);
        for(int i=n-1;i>=0;i--){
            sum+=query(a[i]-1);
            update(a[i],1,mymax);
        }
        cout<<sum<<endl;
    }
    return 0;
}
