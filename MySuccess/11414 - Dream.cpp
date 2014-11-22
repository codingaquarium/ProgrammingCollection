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
    int n,a,odd,tc;
    SDi(tc);
    bool flag;
    while(tc--){
        SDi(n);
        priority_queue< int > pq;
        queue< int > q;
        flag = true;
        odd = 0;
        rep(i,n){
            SDi(a);
            if(a>=n or a<0) flag = false;
            if(a & 1) odd++;
            if(a > 0)
                pq.push(a);
        }
        if(odd & 1) flag = false;
        if(flag){
            int b;
            while(pq.size() and flag){
                b = pq.top();
                pq.pop();
                q = queue< int >();
                while(b--){
                    if(pq.empty()){
                        flag = false;
                        break;
                    }
                    a = pq.top();pq.pop();
                    a--;
                    if(a > 0)
                        q.push(a);
                }
                while(q.size()) pq.push(q.front()),q.pop();
                #ifndef ONLINE_JUDGE
                    //cout<<pq.size()<<endl;
                #endif
            }
        }

//        if(flag){
//            for(int i=0;i<idx;i++){
//                if(arr[i]==0) continue;
//                for(int j=i+1;j<idx and arr[i]>0;j++){
//                    if(arr[j]>0){
//                        arr[j]--;
//                        arr[i]--;
//                    }
//                } if(arr[i]){
//                    flag = false;
//                    break;
//                } sort(arr,arr+idx,greater<int>());
//                if(arr[0]==0)break;
//                i = -1;
//            }
//        }
        if(flag) puts("Yes");
        else puts("No");
    }
    return 0;
}
