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

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)


struct matrix {
    i64 v[17][17];
    int row, col; // number of row and column
};
int mod = 10000;

// multiplies two matrices and returns the result
matrix multiply(matrix a, matrix b) {
    assert(a.col == b.row);
    matrix r;
    r.row = a.row;
    r.col = b.col;
    for (int i = 0; i < r.row; i++) {
        for (int j = 0; j < r.col; j++) {
            i64 sum = 0L;
            for (int k = 0; k < a.col;  k++) {
                sum += a.v[i][k] * b.v[k][j];
                sum %= mod;
            }
            r.v[i][j] = sum;
        }
    }
    return r;
}

// returns mat^p
matrix power(matrix mat, int p) {
    assert(p >= 1);
    if (p == 1) return mat;
    if (p % 2 == 1)
        return multiply(mat, power(mat, p - 1));
    matrix ret = power(mat, p / 2);
    ret = multiply(ret, ret);
    return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	READ("in.txt");
#endif
    int d,n,m,ai,sq[100];
    while (SD3(d,n,m)==3) {
        if( d==0 and n==0 and m==0 ) break;
        // preparing the matrix
        matrix mat;
        mat.row = mat.col = d;
        memca(mat.v);
        rep(i,d){ SDi(ai); mat.v[0][i] = ai; }
        for(int i=1;i<d;i++) mat.v[i][i-1] = 1;

//        rep(i,d){ rep(j,d) cout<<mat.v[i][j]<<" "; puts("");}
        mod = m;
        for(int i=d-1;i>=0;i--){
            SDi(sq[i]);
        }
        if (n <= d) {
            pf("%d\n",sq[n-1]%mod);
        } else {
            mat = power(mat, n - d );
            int ans = 0;
            rep(i,d){
                ans+=(mat.v[0][i]*sq[i])%mod;
            }
            ans %= mod;
            cout << ans << endl;
        }
    }
    return 0;
}
