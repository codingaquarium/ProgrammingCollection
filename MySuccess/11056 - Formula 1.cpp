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

struct state{
    int min,sec,mili;
    string str,name;
    bool operator < (const state& d) const {
        if(min == d.min){
            if(sec == d.sec){
                if(mili == d.mili){
                    return str < d.str;
                } else return mili < d.mili;
            } else return sec < d.sec;
        } else return min < d.min;
    }
}obj[1000];

int main()
{
#ifndef ONLINE_JUDGE
	READ("in.txt");
#endif
    int tc;
    while(SDi(tc)==1){
        string tem;
        rep(i,tc){
            cin>>obj[i].str>>tem>>obj[i].min>>tem>>obj[i].sec>>tem>>obj[i].mili>>tem;
            obj[i].name = obj[i].str;
            rep(j,obj[i].str.length()){
                if( isupper(obj[i].str.at(j) ) ) obj[i].str[j] = tolower( obj[i].str.at(j) );
            }
        }
        sort(obj,obj+tc);
        int cases=0;
        rep(i,tc){
            if (i % 2 == 0)
				cout << "Row " << ++cases << endl;
			cout << obj[i].name << endl;
        } puts("");
    }
    return 0;
}
