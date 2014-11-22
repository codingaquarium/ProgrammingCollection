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

string months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November" , "December"};
map<string,int > m;
int main (int argc, char **argv) {
#ifndef ONLINE_JUDGE
    READ("in.txt");
#endif
    int tc,cas=0,day1,day2,year1,year2;
    string month1,month2;
    char c;
    rep(i,12) m[ months[i] ] = i;
    SDi(tc);
    while(tc--){
        cin>>month1>>day1>>c>>year1;
        if( m[month1]>1 ) year1++;

        cin>>month2>>day2>>c>>year2;
        if(m[month2]<1 || (m[month2]==1 and day2<29) ) year2--;
        int ans = 0;
        ans += year2/4 - (year1-1)/4;
        ans -= year2/100 - (year1-1)/100;
        ans += year2/400 - (year1-1)/400;
        pf("Case %d: %d\n",++cas,ans);
    }
    return 0;
}
