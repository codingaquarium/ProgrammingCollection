#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
using namespace std;


int SET(int N,int pos){	return N=N | (1<<pos);}
int RESET(int N,int pos){	return N= N & ~(1<<pos);}
int check(int N,int pos){	return (N & (1<<pos));}
int toggle(int N,int pos){if(check(N,pos))return N=RESET(N,pos);return N=SET(N,pos);}
int main(void) {
    freopen("in.txt","r",stdin);
    int n;
    string input;
    string hieroglyphs[10];
    cin >> n;
    while (n--) {
        getline(cin, input);

        for (int i = 0; i < 10; i++) {
            getline(cin, hieroglyphs[i]);
        }
        int m = hieroglyphs[0].size() - 2;
        for (int i = 0; i < m; i++) {
            int decoded = 0;
            for (int j = 0; j < 8; j++)
                if (hieroglyphs[j+1][i+1] != '/')
                    decoded = SET(decoded,j);

            putchar(decoded);//cout << decoded;
        }
        cout << endl;
    }
    return 0;
}
