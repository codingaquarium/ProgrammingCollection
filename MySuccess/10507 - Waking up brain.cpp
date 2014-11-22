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

int main()
{
#ifndef ONLINE_JUDGE
	READ("in.txt");
#endif
    int par[30],n,m,totalFound,years;
    string str;
    vi G[30];
    while(SDi(n)==1){
        queue< int > curr,next;
        SDi(m);
        cin>>str;
        memca(par);
        par[ str[0] - 'A'] = par[ str[1] - 'A'] = par[ str[2] - 'A'] = 3;
        curr.push(str[0] - 'A'), curr.push(str[1] - 'A'),curr.push(str[2] - 'A');
        rep(i,m){
            cin>>str;
            int a = str[0] - 'A', b  = str[1] - 'A';
            G[a].pb(b);
            G[b].pb(a);
        }
        if(n==3){
            pf("WAKE UP IN, 0, YEARS\n");
            goto A;
        }
        years = 0;totalFound = 3;
        while(curr.size()){
            years++;
            while(curr.size()){
                int v,p =curr.front();curr.pop();
                rep(i,G[p].size()){
                    v = G[p][i];
                    ++par[v];
                    if(par[v]==3){
                        next.push(v);
                        totalFound++;
                        if(totalFound == n){
                            pf("WAKE UP IN, %d, YEARS\n",years);
                            goto A;
                        }
                    }
                }
            }
            curr = next;
            next = queue< int >();
        }
        puts("THIS BRAIN NEVER WAKES UP");
        A:
        rep(i,30) G[i].clear();
    }
    return 0;
}
