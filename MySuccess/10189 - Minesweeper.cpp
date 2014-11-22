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

string str[105];
int n,m;
int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};
bool valid(int i,int j){
    if(i>=0 and i<n and j>=0 and j<m) return true;
    else return false;
}

void call(int p,int q){
    int x,y,mine = 0;
    rep(i,8) {
        x = p+rrr[i];
        y = q+ccc[i];
        if(valid(x,y))
            if(str[x][y]=='*'){
                mine++;
            }
    }
    str[p][q] = '0'+mine;
}

int main (int argc, char **argv) {
#ifndef ONLINE_JUDGE
    READ("in.txt");
//    WRITE("out.txt");
//    cout<<"hello world!"<<endl;
#endif
    int cas=0;
    while(SD2(n,m)){
        if(m==0 and n==0) break;
        if(cas)puts("");
        pf("Field #%d:\n",++cas);
        rep(i,n) cin>>str[i];
        rep(i,n) rep(j,m){
            if(str[i][j]!='*') call(i,j);
        }
        rep(i,n) cout<<str[i]<<endl;
    }

    return 0;
}
