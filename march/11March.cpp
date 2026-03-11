// 1001: complement of base 10 integer
//
// 0 -> 1 and viceversa
// 5 : 101
// complement of 5 : 010
// return 010 -> 2

class Solution {
  int binToDec(string s) {
    int ans = 0;
    int j = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
      ans += pow(2, j) * (s[i] - '0');
      j++;
    }
    return ans;
  }
  string decToBin(in n) {
    string binary = "";
    while (n > 0) {
      int bit = n & 1;
      binary.push_back('0' + bit);
      n = n >> 1;
    }
    reverse(binary.begin(), binary.end());
    return binary;
  }
  int solve(int n) {
    string binary = decToBin(n);
    int len = binary.size();
    string used = "";
    for (int i = 0; i < len; i++) {
      used += '1';
    }

    // binary = '101'
    // used = '111'
    // complement = used - binary = 010
    string comp = "";
    for (int i = 0; i < len; i++) {
      comp += (used[i] - binary[i]) + '0';
    }

    return binToDec(comp);
  }

public:
  int bitwiseComplement(int n) {
    // simple approach is:
    // 5: 101 so we have to convert 5 into binary
    // if we substract with 111
    // 111 - 101 -> 010 = 2

    if (n == 0 || n == 1) {
      return n == 0 ? 1 : 0;
    }

    return solve(n);
  }
};
