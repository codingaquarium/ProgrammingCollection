//copied
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#include <ctime>
#define Inf 2147483647
#define Pi acos(-1.0)
#define N 1000000
#define LL long long 
#define F(i, a, b) for( int i = (a); i < (b); i++ )
#define Fs(i, sz) for( size_t i = 0; i < sz.size (); i++ )
#define Fe(it, x) for(typeof (x.begin()) it = x.begin(); it != x.end (); it++)
#define Pr(x) for(typeof (x.begin()) it = x.begin(); it != x.end (); it++) cout << *it << " "; cout << endl;
#define Set(a, s) memset(a, s, sizeof (a))
#define Rd(r) freopen(r, "r", stdin)
#define Wt(w) freopen(w, "w", stdout) 
using namespace std;
int main() {
    int testCase;
    scanf("%d", &testCase);
    while (testCase--) {
        char inp[2000 + 10];
        scanf("%s", inp);
        int len = strlen(inp);
        string inpStr = inp;
        string basic;
        for (int i = len / 2; i >= 0; i--) {
            basic = inpStr.substr(0, i);
            string repeat = inpStr.substr(i, i);
            // cout << basic << " " << repeat << endl;
            if (basic == repeat)
                break;
        }
        int ind = basic.size() * 2;
        int basicInd = 0;
        while (ind < (int)inpStr.size()) {
            ind++;
            basicInd++;
        }
        int output = 8;
        while (output) {
            cout << basic [basicInd % basic.size()];
            output--;
            basicInd++;
        }
        cout << "..." << endl;
    }
    return 0;
}
