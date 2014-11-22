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

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    char ch[1000];
    int num;
    bool f;
    while(gets(ch)){
        stringstream ss(ch);
        pf("{");
        f = false;
        while(ss>>num){
            if(f) cout<<", ";
            cout<<num;
            f=true;
        } puts("},");
    }
}

/*
int a[20][20] = {
    {8,2,22,97,38,15,0,40,0,75,4,5,7,78,52,12,50,77,91,8},
    {49,49,99,40,17,81,18,57,60,87,17,40,98,43,69,48,4,56,62,0},
    {81,49,31,73,55,79,14,29,93,71,40,67,53,88,30,3,49,13,36,65},
    {52,70,95,23,4,60,11,42,69,24,68,56,1,32,56,71,37,2,36,91},
    {22,31,16,71,51,67,63,89,41,92,36,54,22,40,40,28,66,33,13,80},
    {24,47,32,60,99,3,45,2,44,75,33,53,78,36,84,20,35,17,12,50},
    {32,98,81,28,64,23,67,10,26,38,40,67,59,54,70,66,18,38,64,70},
    {67,26,20,68,2,62,12,20,95,63,94,39,63,8,40,91,66,49,94,21},
    {24,55,58,5,66,73,99,26,97,17,78,78,96,83,14,88,34,89,63,72},
    {21,36,23,9,75,0,76,44,20,45,35,14,0,61,33,97,34,31,33,95},
    {78,17,53,28,22,75,31,67,15,94,3,80,4,62,16,14,9,53,56,92},
    {16,39,5,42,96,35,31,47,55,58,88,24,0,17,54,24,36,29,85,57},
    {86,56,0,48,35,71,89,7,5,44,44,37,44,60,21,58,51,54,17,58},
    {19,80,81,68,5,94,47,69,28,73,92,13,86,52,17,77,4,89,55,40},
    {4,52,8,83,97,35,99,16,7,97,57,32,16,26,26,79,33,27,98,66},
    {88,36,68,87,57,62,20,72,3,46,33,67,46,55,12,32,63,93,53,69},
    {4,42,16,73,38,25,39,11,24,94,72,18,8,46,29,32,40,62,76,36},
    {20,69,36,41,72,30,23,88,34,62,99,69,82,67,59,85,74,4,36,16},
    {20,73,35,29,78,31,90,1,74,31,49,71,48,86,81,16,23,57,5,54},
    {1,70,54,71,83,51,54,69,16,92,33,48,61,43,52,1,89,19,67,48}
};


int main(){
    int a1,a2,a3,a4,mx;
    a1 = a2 = a3 = a4 = mx = 0;
    rep(i,20) rep(j,20){
        if(i<17) a1 = a[i][j]*a[i+1][j]*a[i+2][j]*a[i+3][j];
        if(j<17) a2 = a[i][j]*a[i][j+1]*a[i][j+2]*a[i][j+3];
        if(i<17 and j<17 ) a3 = a[i][j]*a[i+1][j+1]*a[i+2][j+2]*a[i+3][j+3];
        if(i<17 and j>=3) a4 = a[i][j]*a[i+1][j-1]*a[i+2][j-2]*a[i+3][j-3];
        int ans = max( max(a1,a2), max(a3,a4) );
        mx = max(ans,mx);
    } cout<<mx<<endl;
    return 0;
}
*/
