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

char ch[102][102];

void call(){
    rep(i,101){
        rep(j,101) putchar(ch[i][j]);
        puts("");
    }
}

int main()
{
#ifndef ONLINE_JUDGE
	READ("in.txt");
#endif
    int tc,x,y,hi,lo,len,cas=0;
    SDi(tc);getchar();
    while(tc--){
        pf("Case #%d:\n",++cas);
        string str;
        cin>>str;
        mem(ch,' ');
        x = 50, y = 0;
        hi = 0, lo = 1<<28;
        len = str.length();
        rep(i,len){
            if(str.at(i)=='R'){
                ch[x][y] = '/';
                hi = max(hi,x),lo = min(lo,x);
                x--,y++;
            } else if(str.at(i)=='F'){
                x++;
                ch[x][y] = '\\';
                y++;
                hi = max(hi,x),lo = min(lo,x);
            } else {
                ch[x][y] = '_';
                y++;
                hi = max(hi,x),lo = min(lo,x);
            }
        }
//        call();
        FOR(i,lo,hi){
            pf("| ");
            for(int j=101;j>=0;j--)
                if(ch[i][j]=='_' || ch[i][j]=='/' || ch[i][j]=='\\'){ ch[i][j+1] = '\0';break;}
             puts(ch[i]);
        }
        putchar('+');
        rep(i,len+2) putchar('-');
        puts("\n");
    }
    return 0;
}
