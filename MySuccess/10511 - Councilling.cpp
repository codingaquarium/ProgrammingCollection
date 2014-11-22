/*
http://codingaquarium.wordpress.com/
Shaikh shiam Rahman
Khunla University of Engineering and Technology(KUET)

*/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
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
#define MX 1300

int par[MX], f,t,s,v,dis[MX],vis[MX],flow[MX][MX],n;
vii G[MX];
msi EP,EM,EC;
void agumentPath(int v,int minEdge){
    if(v==s){
        f = minEdge;
        return;
    }
    else if(vis[v]){
        agumentPath(par[v],min(minEdge,flow[ par[v] ][v]));
        flow[par[v]][v]-=f;
        flow[v][par[v]]+=f;
    }
}
int MM(string str){ if(EM.count(str)) return EM[str]; return EM[str] = n++; }
int PP(string str){ if(EP.count(str)) return EP[str]; return EP[str] = n++; }
int CC(string str){ if(EC.count(str)) return EC[str]; return EC[str] = n++; }
void print(msi m){
    for(msi::iterator it = m.begin();it!=m.end();++it)
        cout<<it->ft <<" "<<it->sd<<endl;
}
int main()
{
#ifndef ONLINE_JUDGE
	READ("in.txt");
#endif
    int tc,max_flow;
    SDi(tc);getchar();getchar();
    while(tc--){
        memca(flow);
        char ch[2000];
        n = 2;
        string P,M,C;
        while(gets(ch)){
            if(strcmp(ch,"")==0 or strcmp(ch," ")==0) break;
            stringstream ss(ch);
            ss>>M>>P;
            G[PP(P)].pb(pmp(MM(M),1));
            G[MM(M)].pb(pmp(PP(P),1));
            flow[PP(P)][MM(M)] = 1;
            while(ss>>C){
                G[MM(M)].pb(pmp(CC(C),1));
                G[CC(C)].pb(pmp(MM(M),1));
                flow[MM(M)][CC(C)] = 1;
                G[CC(C)].pb(pmp(1,1));
                G[1].pb(pmp(CC(C),1));
                flow[CC(C)][1] = 1;
            }
        }
        int target_flow = (EC.size()-1)/2;
        for(msi::iterator it = EP.begin();it!=EP.end();++it){
            G[0].pb(pmp(it->sd,1));
            G[it->sd].pb(pmp(0,1));
            flow[0][it->sd] = target_flow;
        }
//        print(EP),print(EC),print(EM);
        memca(par),max_flow = 0,s=0,t=1;
        while(1){
            f = 0;
            memca(dis),memca(vis);
            queue< int > q;
            q.push(s), dis[s] = 0, vis[s] = 1;
            while(q.size()){
                int v,u = q.front(); q.pop();
                if(u==t) break;
                rep(i,G[u].size()){
                    v = G[u][i].ft;
                    if(vis[v]==0 and flow[u][v] > 0){
                        vis[v] = 1, dis[v] = dis[u] + 1;
                        q.push(v);
                        par[v] = u;
                    }
                }
            }
            agumentPath(t,INF);
            if(f==0) break;
            max_flow+=f;
        }
        if((int)EC.size()==max_flow){
            for(msi::iterator it = EM.begin();it!=EM.end();++it){
                for(msi::iterator jt = EC.begin();jt!=EC.end();++jt){
                    if(flow[ jt->sd ][ it->sd ]==1)
                        cout<< it->ft <<" "<<jt->ft<<endl;
                }
            }
        }else puts("Impossible.");
        rep(i,n+10) G[i].clear();
        EC.clear(),EP.clear(),EM.clear();
        if(tc) puts("");
    }
    return 0;
}
