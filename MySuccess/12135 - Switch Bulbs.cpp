/*
 * marathonE.cpp
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
#define MAX 20010

int main (int argc, char **argv) {
#ifndef ONLINE_JUDGE
	READ("in.txt");
	cout<<"hello world!"<<endl;
#endif
	int tc,cas=0,n,m,mask,vis[1<<16],a,b,u,v;
	vector<int> G[1<<16];
	string str;
	SDi(tc);
	while(tc--){
		SD2(n,m);
		n = 1<<n;
		rep(i,m){
			SDi(a);
			mask = 0;
			while(a--){
				SDi(b);
				mask |= 1<<b;
			}
#ifndef ONLINE_JUDGE
			cout<<i<<" : "<<mask<<endl;
#endif
			rep(j,n){
				G[j].push_back(j^mask);
			}
		}
		memdp(vis);
		queue<int> q;
		q.push(0);
		vis[0]=0;
		while(q.size()){
			u = q.front();
			q.pop();
			rep(i,G[u].size()){
				v = G[u][i];
				if(vis[v]==-1){
					vis[v] = vis[u]+1;
					q.push(v);
				}
			}
		}
		pf("Case %d:\n",++cas);
		SDi(m);
		while(m--){
			cin>>str;
			mask = 0;
 			rep(i,str.size()){
				mask = mask*2 + (str[i]-'0');
			}
#ifndef ONLINE_JUDGE
			cout<<m<<" : "<<mask<<endl;
#endif
 			pf("%d\n",vis[mask]);
		}
		puts("");
		rep(i,n+1) G[i].clear();
	}
    return 0;
}
