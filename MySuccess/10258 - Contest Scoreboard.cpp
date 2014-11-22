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

struct teams{
    int num,solved,problems[12],penalty,times[12];
    bool submit;
}a[105];

void reset(){
    rep(i,105){
        a[i].num = i;
        memca(a[i].problems),memca(a[i].times);
        a[i].solved = a[i].penalty = a[i].submit = 0;
    }
}

void calculation(){
    rep(i,105){
        if(a[i].submit){
            repl(j,9){
                if( a[i].problems[j] == 1 ){
                    a[i].solved++;
                    a[i].penalty+=a[i].times[j];
                }
            }
        }
    }
}

bool comp(teams a, teams b){
    if(a.solved > b.solved) return true;
    if(a.solved == b.solved)
        if (a.penalty == b.penalty)
            if(a.num < b.num) return true;
            else return false;
        else return false;
    else return false;
}

int main()
{
#ifndef ONLINE_JUDGE
	READ("in.txt");
#endif
    int tc;SDi(tc);getchar();getchar();
    char ch[1000],stu;
    int team,prob,sub;
    while(tc--){
        reset();
        while(gets(ch) and strlen(ch)){
            sscanf(ch,"%d %d %d %c",&team,&prob,&sub,&stu);
            a[team].submit = true;
            if(stu == 'U' or stu == 'R' or stu == 'E') continue;
            if(!a[team].problems[prob] and stu == 'C'){
                a[team].problems[prob] = 1;
                a[team].times[prob]+=sub;
            } else {
                if(!a[team].problems[prob])
                    a[team].times[prob]+=20;
            }
        }
        calculation();
        sort(a,a+105,comp);
        rep(i,105)
            if(a[i].submit)
                pf("%d %d %d\n",a[i].num,a[i].solved,a[i].penalty);
        if(tc) puts("");
    }
    return 0;
}
