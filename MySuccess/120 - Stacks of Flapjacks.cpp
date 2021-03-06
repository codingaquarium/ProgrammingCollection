/*
http://codingaquarium.wordpress.com/
Shaikh shiam Rahman
UVa : 120 - Stacks of Flapjacks
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

const i64 INFFF=1e16;

vector< int > v;

bool isREverse() {
    for(int i=1; i<(int)v.size(); i++) {
        if( v[i-1]<v[i] ) return false;
    }
    return true;
}

bool isSorted() {
    for(int i=0; i<(int)v.size()-1; i++)
        if(v[i]>v[i+1]) return false;
    return true;
}

bool movetotop(int len){
    int idx = max_element( v.begin(),v.begin()+len ) - v.begin();
    if(idx==0) return true;
    if(idx==len-1) return false;
    reverse(v.begin(),v.begin()+idx+1);
    pf("%d ",v.size()-idx);
    return true;
}

int main() {
#ifndef ONLINE_JUDGE
    READ("in.txt");
    cout<<"hello world!"<<endl;
#endif
    char line[1000];
    while( gets( line ) ) {
        puts(line);
        stringstream ss( line );
        int num;
        v.clear();
        while( ss >> num )
            v.push_back( num );
        if(v.size()==1) {
            puts("0");
            continue;
        } else if(isREverse()){
            pf("1 0\n");
            continue;
        } else if(isSorted()) {
            pf("0\n");
            continue;
        } else {
            for(int i=v.size();!isSorted();i--){
                if(movetotop(i)){
                    reverse(v.begin(),v.begin()+i);
                    pf("%d ",v.size()-i+1);
                }
            } puts("0");
        }
    }
    return 0;
}
