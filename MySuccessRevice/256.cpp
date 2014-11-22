/*
http://codingaquarium.wordpress.com/
Shaikh shiam Rahman
Khunla University of Engineering and Technology(KUET)

*/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
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

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define MX 110

int main(){
#ifndef ONLINE_JUDGE
	READ("in.txt");
//	WRITE("out.txt");
#endif
//    int a,b;
//    FOR(i,1,99999999){
//        {
//            a = i/100, b = i%100;
//            if((a+b)*(a+b)==i){
//                pf("%04d\\n",i);//puts("");
//            }
//        }
//        {
//            a = i/1000, b = i%1000;
//            if((a+b)*(a+b)==i){
//                pf("%06d\\n",i);//puts("");
//            }
//        }
//        {
//            a = i/10000, b = i%10000;
//            if((a+b)*(a+b)==i){
//                pf("%08d\\n",i);//puts("");
//            }
//        }
//    }
    int n;
    while(~SDi(n)){
        if(n==2){
            puts("00\n01\n81");
        } else if(n==4){
            puts("0000\n0001\n2025\n3025\n9801");
        } else if(n==6){
            puts("000000\n000001\n088209\n494209\n998001");
        } else {
            puts("00000000\n00000001\n04941729\n07441984\n24502500\n25502500\n52881984\n60481729\n99980001");
        }
    }
    return 0;
}
