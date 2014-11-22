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
#define MAX 10010

vector < int > pset(1000);

void initSet(int _size){ pset.resize(_size); FOR(i,0,_size-1) pset[i]=i;}
int findSet(int i){return (pset[i]== i)?i: (pset[i] = findSet(pset[i]));}
void unionSet(int i,int j){ pset[findSet(i)]=findSet(j);}
bool isSameSet(int i,int j){ return findSet(i)==findSet(j);}

int edges;
struct G{
    int u,v,w;
    bool operator < (G a) const {
        return w<a.w;
    }
}g[MAX];

int krus(int n){
    initSet(n+3);
    int taken = 0,res=0;
    rep(i,edges){
        if(!isSameSet(g[i].u,g[i].v)){
            unionSet(g[i].u,g[i].v);
            taken++;
            res+=g[i].w;
        }
    }
    if(taken==n-1) return res;
    else return -1;
}


int main(){
    #ifndef ONLINE_JUDGE
        READ("in.txt");
        //cout<<"hello world!"<<endl;
    #endif
    int tc,cas=0,num,sum,n;
    SDi(tc);
    while(tc--){
        SDi(n);
        edges= sum = 0;
        rep(i,n) rep(j,n){
            SDi(num);
            sum+=num;
            if(i==j) continue;
            if(num==0) continue;
            g[edges].u = i;
            g[edges].v = j;
            g[edges].w = num;
            edges++;
        }
        sort(g,g+edges);
        int ans,total = krus(n);
        if(total==-1) ans = -1;
        else ans = sum-total;
        pf("Case %d: %d\n",++cas,ans);
    }
    return 0;
}
