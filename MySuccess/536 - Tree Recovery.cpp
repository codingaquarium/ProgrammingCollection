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
/***
http://greeness2008.blogspot.com/2008/10/tree-recovery.html
The idea behind the code below is this:
1) The root is first element of the pre-order traversal
2) Everything left of the root in the in-order traversal belongs to the left subtree. Similarly everything to the right belongs to the right subtree.
3) The children of the current root are the first elements of the sub-pre-order-traversals.
4) recurse and put the numbers of the children in an array
5) recurse in post-order traversal through the new tree
***/
void post(string pre,string in){
    int sz = pre.size();
    if(sz>0){
        int pos = in.find(pre[0]);
        post(pre.substr(1,pos),in.substr(0,pos)); // left sub tree
        post(pre.substr(pos+1,sz-pos-1),in.substr(pos+1)); // right sub tree
        putchar(pre[0]);
    }
}
int main (int argc, char **argv) {
#ifndef ONLINE_JUDGE
    READ("in.txt");
    cout<<"hello world!"<<endl;
#endif
    string a,b;
    while(cin>>a>>b) post(a,b),puts("");
    return 0;
}
