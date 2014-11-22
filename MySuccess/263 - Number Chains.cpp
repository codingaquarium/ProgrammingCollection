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
    int n;
    while(~SDi(n)){
        if(!n) break;
        char num[20],num2[20];
        sprintf(num,"%d",n);
        pf("Original number was %d\n",n);
        sort(num,num+strlen(num));
        strcpy(num2,num);
        reverse(num2,num2+strlen(num2));
        int a,b,sub;
        a = atoi(num2), b = atoi(num);
        sub = a - b;
        pf("%d - %d = %d\n",a,b,sub);
        map< int, bool > m;
        int len=1;
        while(m[sub] == false){
            m[sub] = true;
            sprintf(num,"%d",sub);
            sort(num,num+strlen(num));
            strcpy(num2,num);
            reverse(num2,num2+strlen(num2));
            a = atoi(num2), b = atoi(num);
            sub = a - b;
            pf("%d - %d = %d\n",a,b,sub);
            len++;
        } pf("Chain length %d\n\n",len);
    }
    return 0;
}
