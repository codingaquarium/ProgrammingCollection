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

typedef pair<int, int> ii;

#define MAX_N 100010                         // second approach: O(n log n)
char T[MAX_N];                   // the input string, up to 100K characters
int n;                                        // the length of input string
int RA[MAX_N], tempRA[MAX_N];        // rank array and temporary rank array
int SA[MAX_N], tempSA[MAX_N];    // suffix array and temporary suffix array
int c[MAX_N];                                    // for counting/radix sort

char P[MAX_N];                  // the pattern string (for string matching)
int m;                                      // the length of pattern string

int Phi[MAX_N];                      // for computing longest common prefix
int PLCP[MAX_N];
int LCP[MAX_N];  // LCP[i] stores the LCP between previous suffix T+SA[i-1]
                                              // and current suffix T+SA[i]
void countingSort(int k) {                                          // O(n)
  int i, sum, maxi = max(300, n);   // up to 255 ASCII chars or length of n
  memset(c, 0, sizeof c);                          // clear frequency table
  for (i = 0; i < n; i++)       // count the frequency of each integer rank
    c[i + k < n ? RA[i + k] : 0]++;
  for (i = sum = 0; i < maxi; i++) {
    int t = c[i]; c[i] = sum; sum += t;
  }
  for (i = 0; i < n; i++)          // shuffle the suffix array if necessary
    tempSA[c[SA[i]+k < n ? RA[SA[i]+k] : 0]++] = SA[i];
  for (i = 0; i < n; i++)                     // update the suffix array SA
    SA[i] = tempSA[i];
}

void constructSA() {         // this version can go up to 100000 characters
  int i, k, r;
  for (i = 0; i < n; i++) RA[i] = T[i];                 // initial rankings
  for (i = 0; i < n; i++) SA[i] = i;     // initial SA: {0, 1, 2, ..., n-1}
  for (k = 1; k < n; k <<= 1) {       // repeat sorting process log n times
    countingSort(k);  // actually radix sort: sort based on the second item
    countingSort(0);          // then (stable) sort based on the first item
    tempRA[SA[0]] = r = 0;             // re-ranking; start from rank r = 0
    for (i = 1; i < n; i++)                    // compare adjacent suffixes
      tempRA[SA[i]] = // if same pair => same rank r; otherwise, increase r
      (RA[SA[i]] == RA[SA[i-1]] && RA[SA[i]+k] == RA[SA[i-1]+k]) ? r : ++r;
    for (i = 0; i < n; i++)                     // update the rank array RA
      RA[i] = tempRA[i];
    if (RA[SA[n-1]] == n-1) break;               // nice optimization trick
  }
}

void computeLCP() {
  int i, L;
  Phi[SA[0]] = -1;                                         // default value
  for (i = 1; i < n; i++)                            // compute Phi in O(n)
    Phi[SA[i]] = SA[i-1];    // remember which suffix is behind this suffix
  for (i = L = 0; i < n; i++) {             // compute Permuted LCP in O(n)
    if (Phi[i] == -1) { PLCP[i] = 0; continue; }            // special case
    while (T[i + L] == T[Phi[i] + L]) L++;       // L increased max n times
    PLCP[i] = L;
    L = max(L-1, 0);                             // L decreased max n times
  }
  for (i = 0; i < n; i++)                            // compute LCP in O(n)
    LCP[i] = PLCP[SA[i]];   // put the permuted LCP to the correct position
}

int owner(int idx) { return (idx < n-m-1) ? 1 : 2; }

vpii LCS() {                 // returns a pair (the LCS length and its index)
  int i, idx = 0, maxLCP = -1;
  vpii v;
  for (i = 1; i < n; i++)                         // O(n), start from i = 1
    if (owner(SA[i]) != owner(SA[i-1]) && LCP[i] > maxLCP){
      v.clear();
      maxLCP = LCP[i], idx = i;
      v.pb(pmp(maxLCP,idx));
    } else if (owner(SA[i]) != owner(SA[i-1]) && LCP[i]==maxLCP){
        v.pb(pmp(LCP[i],i));
    }
  return v;
}

int main()
{
#ifndef ONLINE_JUDGE
	READ("in.txt");
	WRITE("out.txt");
#endif
    bool line = false;
    while(gets(T) and gets(P)){
        if(line){
//            char temp[MAX_N];
            mem(T,'\0');
            strcpy(T,P);
            gets(P);
            puts("");
        }
        line = true;
        n = (int)strlen(T);
        T[n++] = '$';
        // if '\n' is read, uncomment the next line
        T[n-1] = '$'; T[n] = 0;
        m = (int)strlen(P);
        // if '\n' is read, uncomment the next line
//        P[m-1] = 0; m--;
        strcat(T, P);                                                 // append P
        strcat(T, "#");                                    // add '$' at the back
        n = (int)strlen(T);
//      reconstruct SA
        constructSA();                                              // O(n log n)
        computeLCP();                                                     // O(n)
//        printf("\nThe LCP information of 'T+P' = '%s':\n", T);
//        printf("i\tSA[i]\tLCP[i]\tOwner\tSuffix\n");
//        for (int i = 0; i < n; i++)
//            printf("%2d\t%2d\t%2d\t%2d\t%s\n", i, SA[i], LCP[i], owner(SA[i]), T + SA[i]);


        vpii ans = LCS();         // find the longest common substring between T and P
//        cout<<P<<" "<<T<<" "<<ans.size()<<endl;
        sort(all(ans));
        char lcsans[MAX_N];
        mem(lcsans,'\0');
        vpii::iterator non_duplicate = unique(all(ans));
        set< string > st;
        for(vpii::iterator it = ans.begin();it!=non_duplicate;++it){
            strncpy(lcsans, T + SA[it->sd], it->ft);
            if(it->ft == 0) continue;
            st.insert(string(lcsans));
//            cout<<it->sd<<" " << it->ft;
//            cout<<lcsans<<endl;
//            printf(" The LCS is '%s' with length = %d\n", lcsans, it->ft);
        }
        if(st.size()){
            for(set< string >::iterator it=st.begin();it!=st.end();++it)
                cout<<*it<<endl;
        }
        else cout << "No common sequence." << endl;
        mem(P,'\0');
    }
    return 0;
}
