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
#define MX 100000+5

int a[MX],tree[MX];

int query(int idx){
       int sum=0;
       while(idx>0){
             sum+=tree[idx];
             idx -= idx & (-idx);
       }
       return sum;
}

void update(int idx, int x, int n){
       while(idx<=n){
             tree[idx]+=x;
             idx += idx & (-idx);
       }
}

int main (int argc, char **argv) {
#ifndef ONLINE_JUDGE
    READ("in.txt");
//    cout<<"hello world!"<<endl;
#endif
    int tc,n,q,cas=0;
    SDi(tc);
    while(tc--){
        pf("Case %d:\n",++cas);
        SD2(n,q);
        memca(tree);
        repl(i,n){
            SDi(a[i]);
            update(i,a[i],n);
        }
        int ic,idx,v,x,y;
        rep(i,q){
            SDi(ic);
            if(ic==1){
               SDi(idx);idx++;
               update(idx,-a[idx],n);
               pf("%d\n",a[idx]);
               a[idx]=0;
            } else if(ic==2) {
                SD2(idx,v);idx++;
                update(idx,v,n);
                a[idx]+=v;
            } else {
                SD2(x,y);
                pf("%d\n",query(y+1)-query(x));
            }
        }

    }
    return 0;
}
