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
#define pfcas(x) pf("Case %d: ",x)

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define MAX 20010

int main (int argc, char **argv) {
#ifndef ONLINE_JUDGE
    READ("in.txt");
    cout<<"hello world!"<<endl;
#endif
    int n,t,num,cnt[21],cas=0;
    string str[21],str1,str2;
    msi m;
    while(SD2(n,t),n or t){
        getchar();
        rep(i,n) cin>>str[i],m[str[i] ]=i;
        memca(cnt);
        rep(i,t){
            cin>>str1>>str2>>num;
//            cout<<m[str1]<<" "<<m[str2]<<endl;
            cnt[ m[str1] ]+=num;
            cnt[ m[str2] ]-=num;
        }
        int i,j,idx1,idx2;
        pf("Case #%d\n",++cas);
        while(1){
            int mx=INT_MIN,mn=INT_MAX;
            for(i=0;i<n;i++){
                if(cnt[i]>mx) mx = cnt[i],idx1=i;
                if(cnt[i]<mn) mn = cnt[i],idx2=i;
            }
            if( mx == 0) break;
            if(mx>=-mn){
                j = -mn;
                pf("%s %s %d\n",str[idx2].c_str(),str[idx1].c_str(),j);
                cnt[idx1]-=j;
                cnt[idx2]+=j;
            } else {
                j = mx;
                pf("%s %s %d\n",str[idx2].c_str(),str[idx1].c_str(),j);
                cnt[idx1]-=j;
                cnt[idx2]+=j;
            }
        } puts("");
        m.clear();
    }
    return 0;
}
