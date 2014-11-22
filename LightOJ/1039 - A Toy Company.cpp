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
#define stream istringstream
#define rep(i,n) for(__typeof(n) i=0; i<(n); i++)
#define repl(i,n) for(__typeof(n) i=1; i<=(n); i++)
#define FOR(i,a,b) for(__typeof(b) i=(a); i<=(b); i++)
#define INF (1<<30)
#define PI 3.14159265358979323846264338327950
#define pb(x) push_back(x)
#define ppb pop_back
#define all(x) x.begin(),x.end()
#define cclear(x,y) memset(x,y,sizeof(x));
#define mem(x,y) memset(x,y,sizeof(x));
#define eps 1e-9
#define pii pair<int,int>
#define pmp make_pair


#define SDi(x) scanf("%d",&x)
#define SDl(x) scanf("%lld",&x)
#define SDs(x) scanf("%s",x)

using namespace std;

int main()
{
    //READ("in.txt");
    int kas,cas=1;
    cin>>kas;getchar();
    while(kas--)
    {
        getchar();
        printf("Case %d: ",cas++);
        string sor,dis;
        cin>>sor>>dis;
        int n ;
        cin>>n;
        string s[n][3];
        bool flag = true;
        rep(i,n)
            cin>>s[i][0]>>s[i][1]>>s[i][2];
        rep(i,n)
        {
            if(!flag) break;
            rep(j,s[i][0].length())
            {
                string s1 = s[i][0].substr(j,1);
                rep(k,s[i][1].length())
                {
                    string s2 = s[i][1].substr(k,1);
                    rep(m,s[i][2].length())
                    {
                        string s3 = s[i][2].substr(m,1);
                        string ss = s1+s2+s3;
                        if(ss==sor||ss==dis)
                            flag = false;
                    }
                }
            }
        }

        if(!flag) puts("-1");
        else
        {
            int sum=0,num;
            rep(i,3)
            {
                char q = toupper(sor[i]);
                char r = toupper(dis[i]);
                int a = (int)q-64;
                int b = (int)r-64;
                if(a>b) swap(a,b);
                num = min(b-a,26-(b-a));
                sum+=num;
            }
            printf("%d\n",sum);
        }
    }
    return 0;
}
