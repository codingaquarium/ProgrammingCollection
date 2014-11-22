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
#define pf printf
#define sf scanf
#define vi vector<int>
#define vpii vector<pii>
#define si set<int>
#define msi map<string , int >
typedef long long i64;
typedef unsigned long long ui64;

/** function **/

#define SDi(x) sf("%d",&x)
#define SDl(x) sf("%lld",&x)
#define SDs(x) sf("%s",x)
#define SD2(x,y) sf("%d%d",&x,&y)
#define SD3(x,y,z) sf("%d%d%d",&x,&y,&z)

using namespace std;

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

#define MAX 10010
#define white 0
#define gray 1
#define black 2

msi w;
si s;
vi edge[MAX];
int indegree[MAX];
int dfs_num[MAX];
bool cycle;

void dfs(int sor) {
    dfs_num[sor] = gray;
    rep(i,edge[sor].size()) {
        int v = edge[sor][i];
        if( dfs_num[v] == white)
            dfs(v);
        else if(dfs_num[v] == gray) {
            cycle = true;
            return;
        }
    }
    dfs_num[sor] = black;
}

int main() {
    int tc,cas=1;
    cin>>tc;
    while(tc--) {
        pf("Case %d: ",cas++);
        int m,cod=1;
        cin>>m;
        rep(i,m) {
            string s1,s2;
            cin>>s1>>s2;
            if(w[s1]==0)
                w[s1]=cod++;
            if(w[s2]==0)
                w[s2]=cod++;
            indegree[w[s2]]++;
            edge[w[s1]].pb(w[s2]);
            s.insert(w[s1]);
            s.insert(w[s2]);
        }
        memca(dfs_num);
        cycle=false;
        rep(i,cod-1) {
            if(dfs_num[i]==white) {
                dfs(i);
            }
            if(cycle)break;
        }
        if(cycle)
            puts("No");
        else
            puts("Yes");
        w.clear();
        s.clear();
        int i = MAX;
        while(i--)
            edge[i].clear();
    }
    return 0;
}
