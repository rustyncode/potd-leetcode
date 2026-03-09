// 3129: Find all possible stable binary arrays I
//
// time complexity : O(one * zero * limit)
// space complexity : (zero * one)

class Solution {
  int M = 1e9 + 7;
  int t[201][201][2];
  int solve(int zero, int ones, int limit, bool lastWasOne) {
    if (zero == 0 && one == 0)
      return 1;
    if (t[zero][one][lastWasOne] != -1) {
      return t[zero][one][lastWasOne];
    }
    int result = 0;
    // if last one was true means we have to explore zero
    if (lastWasOne) {
      for (int len = 1; len <= min(zero, limit); len++) {
        result += solve(zero - len, one, limit, true) % M;
      }
    } else {

      for (int len = 1; len <= min(one, limit); len++) {
        result += solve(zero, one - len, limit, false) % M;
      }
    }
    retur t[zero][one][lastWasOne] = result;
  }

public:
  int numberOfStableArrays(int zero, int one, int limit) {
    // given 3 int : zero, one, limit
    // binary search is stable if:
    // occurance of 0 : zero
    // occurance of 1: one
    // each subrray of arr with a size with a size greater than limit must
    // obtains both 0 and 1 return the total of stable binary arrays if answer
    // is very large ; return modulo 10^9 + 7

    // input : zero : 1, one: 1, limit : 2
    // we can use dp to solve it, so lets start
    memset(t, -1, sizeof(t));
    int startOne = solve(zero, one, limit, false);
    int startZero = solve(zero, one, limit, true);

    return (startOne + startZero) % M
  }
};
