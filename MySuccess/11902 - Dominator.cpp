/*
 * marathonJ.cpp
 *
 *  Created on: Oct 13, 2013
 *      Author: shiam
 */
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

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define MX 103

int out[MX][MX],mat[MX][MX],n;
bool vis[MX],previs[MX];

void dfs(int u,int abs){
	if(u==abs) return;
	vis[u] = true;
	rep(i,n){
		if(mat[u][i]==1 and vis[i]==false)
			dfs(i,abs);
	}
}

void println(){
	pf("+");
	rep(i,2*n-1) pf("-");
	pf("+\n");
}

int main (int argc, char **argv) {
#ifndef ONLINE_JUDGE
	READ("in.txt");
	cout<<"hello world!"<<endl;
#endif
	int tc,cas=0;
	SDi(tc);
	while(tc--){
		memca(mat);
		SDi(n);
		rep(i,n) rep(j,n){
			SDi(mat[i][j]);
		}
		memca(vis);
		memca(previs);
		dfs(0,-1);
		rep(i,n) previs[i] = vis[i];
		memca(out);
		rep(i,n){
			memca(vis);
			dfs(0,i);
			rep(j,n){
				if(previs[j] and vis[j]==false)
					out[i][j]=true;
			}
			out[i][i] = previs[i];
		}
		pf("Case %d:\n",++cas);
		println();
		rep(i,n){
			pf("|");
			rep(j,n){
				if(out[i][j]) pf("Y|");
				else pf("N|");
			} puts("");
			println();
		}
	}
    return 0;
}
