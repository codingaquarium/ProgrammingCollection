/*
http://codingaquarium.wordpress.com/
Shaikh shiam Rahman
Khunla University of Engineering and Technology(KUET)
idea : http://13codes.wordpress.com/2013/01/13/uva-11331-the-joys-of-farming/
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
#define MAX 2002

int B,C;
vector< int > G[MAX];
vii colors;
bool vis[MAX];

bool bicolor(int x){
    queue< int > q;
    q.push(x);
    vis[x] = true;
    int u,v,color[MAX],black,white;
    memca(color);
    color[x] = 1;
    black  = 0, white = 1;
    while(q.size()){
        u  = q.front();
        q.pop();
        rep(i,G[u].size()){
            v = G[u][i];
            if(color[v]){
                if(color[u]==color[v]) return false;
            }
            if(!vis[v]){
                if(color[u]==1){
                    color[v] = 2;
                    black++;
                } else {
                    color[v] = 1;
                    white++;
                }
                q.push(v);
                vis[v] = true;
            }
        }
    }
    colors.pb(pmp(black,white));
    return true;
}

int dp[MAX][MAX];

int call(int idx,int cap){
    if(cap==0 and idx==(int)colors.size()) return 1;

    if(cap<0 or idx==(int)colors.size()) return 0;

    if(dp[idx][cap]!=-1) return dp[idx][cap];

    return dp[idx][cap] = call(idx+1,cap-colors[idx].ft) + call(idx+1,cap-colors[idx].sd);
}

int main (int argc, char **argv) {
#ifndef ONLINE_JUDGE
    READ("in.txt");
    //cout<<"hello world!"<<endl;
#endif
    int a,tc;
    SDi(tc);
    while(tc--){
        int x,y;
        SD3(B,C,a);
        rep(i,a){
            SD2(x,y);
            G[x].push_back(y);
            G[y].push_back(x);
        }
        memca(vis);
        bool flag = false;
        repl(i,B+C){
            if(!vis[i]){
                if(!bicolor(i)){
                    puts("no");
                    flag = true;
                    break;
                }
            }
        }

        if(!flag){
            memdp(dp);
            if(call(0,B)){
                puts("yes");
            } else puts("no");
        }

        rep(i,MAX) G[i].clear();
        colors.clear();
    }
    return 0;
}
