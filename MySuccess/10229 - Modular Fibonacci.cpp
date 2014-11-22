#include "bits/stdc++.h"
typedef long long i64;
using namespace std;

struct matrix {
  i64 v[5][5];
  int row, col; // number of row and column
};
i64 mod;

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
  i64 n, m;

  while (cin >> n >> m) {
    matrix mat;
    mat.row = mat.col = 2;
    mat.v[0][0] = mat.v[0][1] = mat.v[1][0] = 1;
    mat.v[1][1] = 0;

    // preparing mod value
    mod = (i64)pow(2,m);

    if (n < 3) {
      if (n == 0) cout << 0 << endl;
      if (n == 1) cout << 1 << endl;
      if (n == 2) cout << 1 % mod << endl;
    } else {
      mat = power(mat, n - 1);
      i64 ans = 1 * mat.v[0][0] + 0 * mat.v[0][1];
//      ans %= mod;
      cout << ans%mod << endl;
    }
  }
  return 0;
}
