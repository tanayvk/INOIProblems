#include <iostream>
#include <algorithm>

struct Contestant {
  int t1;
  int t2;
};

// Overload the less than operator for the struct such that
// stable_sort sorts with respect to t2 in the descending order
bool operator<(const Contestant &left, const Contestant &right) {
  return (left.t2 > right.t2);
}

using namespace std;

int main(int argc, char const *argv[]) {
  int N;
  cin >> N;

  Contestant people[N];

  for ( int i = 0; i < N; i++ ) {
    int p, q, r;
    cin >> p >> q >> r;

    Contestant c;
    // time for programming contest
    c.t1 = p;
    // add the other two times
    c.t2 = q + r;
    people[i] = c;
  }

  // sort (in descending order)
  // sorting in descending order with respect to t2 is guarranteed to give the proper order of contestants for the least time
  // this can be proven mathematically, with the help of some simple case-wise analysis
  stable_sort(people, people + N);

  // compute the max time. the time taken by the contestant who comes out last.
  int prefix = 0;
  int maxTime = 0;
  for ( int i = 0; i < N; i++ ) {
    prefix = prefix + people[i].t1;
    maxTime = max(maxTime, prefix + people[i].t2);
  }

  cout << maxTime;

  return 0;
}
