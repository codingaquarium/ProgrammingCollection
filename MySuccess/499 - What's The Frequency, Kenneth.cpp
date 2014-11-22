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

char ch[100000];

int main(){
#ifndef ONLINE_JUDGE
    READ("in.txt");
    cout<<"Hello world!"<<endl;
#endif
    map<char,int> m;
    int mx,xz;
    while(gets(ch)){
            mx = 0;
            xz = strlen(ch);
        rep(i,xz){
            if(isalpha(ch[i])){
                    m[ch[i]]++;
                    mx = max(mx,m[ch[i]]);
            }
        }
        for(map<char,int>::iterator it=m.begin();it!=m.end();++it){
            if(it->second==mx) cout<<it->first;
        }
        cout<<" "<<mx<<endl;
        m.clear();
    }
    return 0;
}
