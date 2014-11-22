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
    int tc;
    SDi(tc);getchar();
    string encode,decode;
    map< char, char >coded;
    map< char, int > enmap,demap;
    vector< pair< int, char> > en,de;
    while(tc--){
        getchar();
        getline(cin, encode);
        getline(cin, decode);
        rep(i,encode.size()){
             enmap[ encode[i] ]++;
        }
        rep(i,decode.size()){
            demap[ decode[i] ]++;
        }
//        cout<<demap.size() << " " << enmap.size() <<endl;
        for(map<char,int>::iterator iten=enmap.begin(),itde = demap.begin();iten!=enmap.end();++iten,++itde){
//            cout<<itde->sd <<" "<< itde->ft <<" - "<< iten->sd <<" " << iten->ft << endl;
            en.pb(pmp(iten->sd,iten->ft));
            de.pb(pmp(itde->sd,itde->ft));
        }
        sort(all(en)),sort(all(de));
        rep(i,de.size()){
            coded[ de[i].sd ] = en[i].sd;
//            cout<< de[i].sd <<" "<<en[i].sd<<endl;
        }
//        cout<<decode.size()<<endl;
        rep(i,decode.size()){
            putchar(coded[ decode[i] ]);
        } puts("");
        coded.clear(),enmap.clear(),demap.clear();
        en.clear(),de.clear();
        if(tc) puts("");
    }
    return 0;
}
