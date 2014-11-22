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

vector<int> edge[MAX];
bool vis[MAX];
int color[MAX];

int bfs(int sor){
    int a,b,v,u =sor;
    vis[u] = true;
    color[u] = 1;
    a=0,b=1;
    queue< int > q;
    q.push(u);
    while(q.size()){
        u = q.front();
        q.pop();
        rep(i,edge[u].size()){
            v = edge[u][i];
            if(!vis[v]){
                vis[v] = true;
                q.push(v);
                if(color[u]==1) color[v] = 2,a++;
                else color[v] = 1,++b;
            }
        }
    }
    return max(a,b);
}

int main (int argc, char **argv) {
#ifndef ONLINE_JUDGE
    READ("in.txt");
    //cout<<"hello world!"<<endl;
#endif
    int cas=0,tc,n,x,y;
    SDi(tc);
    si s;
    while(tc--){
        SDi(n);
        rep(i,n){
            SD2(x,y);
            s.insert(x);
            s.insert(y);
            edge[x].pb(y);
            edge[y].pb(x);
        }
        int ret = 0;
        mem(vis,false);
        memca(color);
        for(si::iterator it = s.begin();it!=s.end();++it){
            if(!vis[*it]){
                ret+=bfs(*it);
            }
        }
        pf("Case %d: %d\n",++cas,ret);
        rep(i,MAX) edge[i].clear();
        s.clear();
    }
    return 0;
}
