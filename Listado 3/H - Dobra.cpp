#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/*
HECHO CON GPT! ESTUDIAR
*/
int main() {
  string s;
  if (!(cin >> s)) return 0;
  int n = s.size();

  // dp[pos][runType][runLen][hasL]
  // runType: 0 = none/start, 1 = vowel, 2 = consonant
  // runLen: 0..2 (we only store up to 2; 3 is invalid)
  static ll dp[101][3][3][2];
  dp[0][0][0][0] = 1;

  auto isVowel = [](char c){
    return c=='A' || c=='E' || c=='I' || c=='O' || c=='U';
  };

  for (int pos = 0; pos < n; ++pos) {
    char ch = s[pos];
    for (int rt = 0; rt <= 2; ++rt) {
      for (int rl = 0; rl <= 2; ++rl) {
        for (int hasL = 0; hasL <= 1; ++hasL) {
          ll cur = dp[pos][rt][rl][hasL];
          if (cur == 0) continue;

          if (ch == '_') {
            // 1) place a vowel (5 choices)
            {
              int t = 1;
              int nrl = (rt == t && rt != 0) ? rl + 1 : 1;
              if (nrl < 3) dp[pos+1][t][nrl][hasL] += cur * 5LL;
            }
            // 2) place 'L' (1 choice, a consonant that sets hasL)
            {
              int t = 2;
              int nrl = (rt == t && rt != 0) ? rl + 1 : 1;
              if (nrl < 3) dp[pos+1][t][nrl][1] += cur * 1LL;
            }
            // 3) place other consonant (20 choices)
            {
              int t = 2;
              int nrl = (rt == t && rt != 0) ? rl + 1 : 1;
              if (nrl < 3) dp[pos+1][t][nrl][hasL] += cur * 20LL;
            }
          } else {
            // fixed letter
            if (isVowel(ch)) {
              int t = 1;
              int nrl = (rt == t && rt != 0) ? rl + 1 : 1;
              if (nrl < 3) dp[pos+1][t][nrl][hasL] += cur;
            } else {
              int t = 2;
              int nrl = (rt == t && rt != 0) ? rl + 1 : 1;
              if (nrl < 3) {
                int nh = hasL | (ch == 'L');
                dp[pos+1][t][nrl][nh] += cur;
              }
            }
          }
        }
      }
    }
  }

  ll ans = 0;
  for (int rt = 0; rt <= 2; ++rt)
    for (int rl = 0; rl <= 2; ++rl)
      ans += dp[n][rt][rl][1]; // hasL == 1

  cout << ans << "\n";
  return 0;
}
