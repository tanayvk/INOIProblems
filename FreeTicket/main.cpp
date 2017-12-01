#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[]) {
  int C, F;
  cin >> C;
  cin >> F;

  int cache[C][C];

  //
  // Floyd Warshall's
  //

  // initialize array with large values
  for (int i = 0; i < C; i++) {
    fill_n(cache[i], C, pow(10, 8) + 1);
    cache[i][i] = 0;
  }

  // fill in the
  for (int i = 0; i < F; i++) {
    int x, y, p;
    cin >> x >> y >> p;

    cache[y - 1][x - 1] = cache[x - 1][y - 1] = p;
  }

  for ( int k = 0; k < C; k++ )
    for ( int i = 0; i < C; i++ )
      for ( int j = 0; j < C; j++ )
        cache[i][j] = min(cache[i][j], cache[i][k] + cache[k][j]);


  int maxPrice = -1;
  for ( int i = 0; i < C; i++ ) {
    for ( int j = 0; j < C; j++ ) {
      if (cache[i][j] != (pow(10, 8) + 1))
        maxPrice = max(maxPrice, cache[i][j]);
    }
  }

  cout << maxPrice;

  return 0;
}
