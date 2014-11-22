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

typedef long long i64;
typedef unsigned long long ui64;

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
const i64 INF64 = (i64)1E18;

vector < int > pset(1000);
void initSet(int _size) {
    pset.resize(_size);
    FOR(i, 0, _size - 1) pset[i] = i;
}
int findSet(int i) {
    return (pset[i] == i) ? i : (pset[i] = findSet(pset[i]));
}
void unionSet(int i, int j) {
    pset[findSet(i)] = findSet(j);
}
bool isSameSet(int i, int j) {
    return findSet(i) == findSet(j);
}

#define G struct edge

G {
    int u, v, cost;
};

G node[12010];

bool compmin(G a, G b) {
    return a.cost < b.cost;
}
bool compmax(G a, G b) {
    return a.cost > b.cost;
}

int krus(int edge) {
    int sum = 0;
    for (int i = 0; i < edge; i++) {
        if (!isSameSet(node[i].u, node[i].v)) {
            sum += node[i].cost;
            unionSet(node[i].u, node[i].v);
        }
    }
    return sum;
}

int main() {
    //READ("in.txt");
    int t;
    cin >> t;
    int cas = 1;
    while (t--) {
        printf("Case %d: ", cas++);
        int n, edge = 0;
        cin >> n;
        int x, y, loss;
        while (scanf("%d %d %d", &x, &y, &loss) && (x || y || loss)) {
            node[edge].u = x;
            node[edge].v = y;
            node[edge].cost = loss;
            edge++;
        }
        sort(node, node + edge, compmin);
        initSet(n + 3);
        int a = krus(edge);
        sort(node, node + edge, compmax);
        initSet(n + 3);
        int b = krus(edge);
        if ((a + b) % 2 == 0)
            printf("%d\n", (a + b) / 2);
        else
            printf("%d/2\n", (a + b));
    }
    return 0;
}
