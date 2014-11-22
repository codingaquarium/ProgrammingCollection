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
    int tc,len,cas=0,cnt;
    stack< pair<char,int> > st;
    vector< pair<char,int> > v;
    char ch[10000],C;
    SDi(tc);getchar();
    while(tc--){
        pf("Case %d\n",++cas);
        gets(ch);
        len = strlen(ch);
        st.push(pmp(ch[0],0) );
        rep(i,len-2){
            if(ch[i+1]==ch[i+2]){
                v.pb(pmp(ch[i+1],1));
                i++;
                C = st.top().ft;
                cnt = st.top().sd;
                st.pop();
                st.push(pmp(C,cnt+1));
            } else{
                if(ch[i+1]==st.top().ft){
                    C = st.top().ft;
                    cnt = st.top().sd;
                    v.pb(pmp(ch[i+1],cnt));
                    st.pop();
                } else {
                    C = st.top().ft;
                    cnt = st.top().sd;
                    st.pop();
                    st.push(pmp(C,cnt+1));
                    st.push(pmp(ch[i+1],1) );
                }
            }
//            pf("%c - v : %u\n",ch[i+1],v.size());
        }
        v.pb(pmp(st.top().ft,st.top().sd));
        sort(all(v));
        rep(i,v.size()) pf("%C = %d\n",v[i].ft,v[i].sd);
        v.clear();
        st = stack<pair < char,int > >();
    }

    return 0;
}
