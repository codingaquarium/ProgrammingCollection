/*
Shiakh Shiam Rahman 
UVa : 10199 - Turist Guide
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
#define mis map<int , string >
#define vs vector<string>
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
const i64 INF64 = (i64)1E18;

template<class T> inline T gcd(T a,T b) {if(a<0)return
gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
template<class T> inline T lcm(T a,T b) {if(a<0)return lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/gcd(a,b));}
template<class T> inline T sqr(T x){return x*x;}
template<class T> T power(T N,T P){ return (P==0)?  1: N*power(N,P-1); }
template<class T> bool inside(T a,T b,T c){ return (b>=a && b<=c);}


double _dist(double x1,double y1,double x2,double y2){return sqrt(sqr(x1-x2)+sqr(y1-y2));}
int distsq(int x1,int y1,int x2,int y2){return sqr(x1-x2)+sqr(y1-y2);}
i64 toInt64(string s){i64 r=0;istringstream sin(s);sin>>r;return r;}

double LOG(i64 N,i64 B){	return (log10l(N))/(log10l(B));	}
string itoa(long long a){if(a==0) return "0";string ret;for(long long i=a; i>0; i=i/10) ret.push_back((i%10)+48);reverse(ret.begin(),ret.end());return ret;}

vector< string > token( string a, string b )
{
    const char *q = a.c_str();while( count( b.begin(), b.end(), *q ) ) q++;vector< string >
	oot;while( *q ) {const char *e = q;while( *e && !count( b.begin(), b.end(),
	*e ) ) e++;oot.push_back( string( q, e ) );q = e;while( count( b.begin(),
	b.end(), *q ) ) q++;}return oot;
}
int isvowel(char s){s=tolower(s); if(s=='a' || s=='e' || s=='i' || s=='o' || s=='u')return 1; return 0;}
int isupper(char s) {if(s>='A' and s<='Z') return 1; return 0;}
template<class T> struct Fraction{T a,b;Fraction(T a=0,T b=1);string toString();};//NOTES:Fraction
template<class T> Fraction<T>::Fraction(T a,T b){T d=gcd(a,b);a/=d;b/=d;if (b<0) a=-a,b=-b;this->a=a;this->b=b;}
template<class T> string Fraction<T>::toString(){ostringstream sout;sout<<a<<"/"<<b;return sout.str();}
template<class T> Fraction<T> operator+(Fraction<T> p,Fraction<T> q){return Fraction<T>(p.a*q.b+q.a*p.b,p.b*q.b);}
template<class T> Fraction<T> operator-(Fraction<T> p,Fraction<T> q){return Fraction<T>(p.a*q.b-q.a*p.b,p.b*q.b);}
template<class T> Fraction<T> operator*(Fraction<T> p,Fraction<T> q){return Fraction<T>(p.a*q.a,p.b*q.b);}
template<class T> Fraction<T> operator/(Fraction<T> p,Fraction<T> q){return Fraction<T>(p.a*q.b,p.b*q.a);}

//bool operator < ( const node& p ) const {      return dist > p.dist;   }

/** Bitamsk **/

int SET(int N,int pos){	return N=N | (1<<pos);}
int RESET(int N,int pos){	return N= N & ~(1<<pos);}
int check(int N,int pos){	return (N & (1<<pos));}
int toggle(int N,int pos){if(check(N,pos))return N=RESET(N,pos);return N=SET(N,pos);}
void PRINTBIT(int N){	printf("("); for(int i=6;i>=1;i--)	{bool x=check(N,i);cout<<x;}	puts(")");}

const i64 INFFF=1e16;
#define MAX 110

vector< int > G[MAX];
int low[MAX], vis[MAX], used[MAX], cut[MAX], dfstime;
msi m;
mis id;
bool ap_taken[MAX];
vs point;
void dfs(int u, int par = -1) {
	int i, v, child = 0;
	used[u] = 1;
	vis[u] = low[u] = ++dfstime;
	for(i = 0; i < (int)G[u].size(); i++) {
		v = G[u][i];
		if(v == par) continue;
		if(used[v]) low[u] = min(low[u], vis[v]);
		else {
			child++;
			dfs(v, u);
			low[u] = min(low[u], low[v]);
			if(low[v] >= vis[u]&&par!=-1&&!ap_taken[u]){ point.pb(id[u]);ap_taken[u]=true;}
		}
	}
	if(par == -1) if(child > 1&&!ap_taken[u]){ point.pb(id[u]);ap_taken[u]=true;}
}


int main()
{
    READ("in.txt");
    int n,cas=1;
    bool l = false;
    while(SDi(n)&&n)
    {
        if(l) puts("");
        l = true;
        int index=1;
        getchar();
        rep(i,n)
        {
            char ch[200];
            gets(ch);
            string s(ch);
            m[s]=index;
            id[index]=s;
            index++;
        }
        int M;
        SDi(M);getchar();
        rep(i,M)
        {
            string s1,s2;
            cin>>s1>>s2;
            int u,v ;
            u = m[s1];
            v = m[s2];
            G[u].pb(v);
            G[v].pb(u);
        }
        /*
        repl(i,n) pf("%d ",i);puts("");
        repl(i,n) pf("%s ",id[i].c_str());puts("");
        */
        memca(used);
        mem(ap_taken,false);
        repl(i,n-1)
            dfs(i);

        sort(all(point));
        /*
        repl(i,n) pf("%d ",dfs_num[i]);puts("");
        repl(i,n) pf("%d ",dfs_low[i]);puts("");
        */
        pf("City map #%d: %d camera(s) found\n",cas++,(int)point.size());
        rep(i,point.size()) pf("%s\n",point[i].c_str());
        m.clear();
        id.clear();
        point.clear();
        int i = 110;
        while(i--) G[i].clear();
    }
    return 0;
}

