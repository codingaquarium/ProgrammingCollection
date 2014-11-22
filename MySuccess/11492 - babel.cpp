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
#define MAX 2003

vi G[MAX],cost[MAX];
string sor,dis,sr[MAX],st[MAX],wd[MAX];
int n,fin[MAX],len[MAX],d[MAX];

struct data {
    int city, dist;
    bool operator < ( const data& p ) const {
        return dist > p.dist;
    }
};

int dijkstra() {
    memsp(d);
    priority_queue<data> q;
    data u, v;
    rep(i,n){
        if(sor==st[i] or sr[i]==sor){
            u.city = i;
            u.dist = d[i] = len[i];
            q.push(u);
        }
    }
    while( !q.empty() ) {
        u = q.top(); q.pop();
        int ucost = d[ u.city ];
        if(fin[u.city]) return ucost;

        for(size_t i=0; i<G[u.city].size(); i++) {
            v.city = G[u.city][i], v.dist = cost[u.city][i] + ucost;
            // relaxing :)
            if( d[v.city] > v.dist ) {
                d[v.city] = v.dist;
                q.push( v );
            }
        }
    }
    return -1;
}

int main()
{
#ifndef ONLINE_JUDGE
	READ("in.txt");
#endif
    while(SDi(n) and n){
        memca(fin);
        cin>>sor>>dis;
        rep(i,n){
            cin>>st[i]>>sr[i]>>wd[i];
            if(st[i] == dis or sr[i] == dis){
                fin[i] = 1;
            }
            len[i] = wd[i].length();
        }
        rep(i,n) FOR(j,i+1,n-1){
            if(wd[i][0]!=wd[j][0])
                if(st[i]==st[j] or st[i]==sr[j] or sr[i]==st[j] or sr[i]==sr[j]){
                    G[i].pb(j);
                    G[j].pb(i);
                    cost[i].pb(len[j]);
                    cost[j].pb(len[i]);
                }
        }
        int ret = dijkstra();
        if( ret == -1) puts("impossivel");
        else pf("%d\n",ret);
        rep(i,MAX) G[i].clear(),cost[i].clear();
    }
    return 0;
}
