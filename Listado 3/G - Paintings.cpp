#include <bits/stdc++.h>
using namespace std;
/*
Hecho con GTP!! EStudiar luego

*/


int N;
vector<string> names;
vector<vector<bool>> adj;
vector<bool> used;

// busca si existe alguna completación (devuelve true en cuanto encuentra una)
bool exist_completion(int pos, int prev) {
  if (pos == N) return true;
  for (int c = 0; c < N; ++c) {
    if (used[c]) continue;
    if (pos > 0 && !adj[prev][c]) continue;
    used[c] = true;
    if (exist_completion(pos + 1, c)) { used[c] = false; return true; }
    used[c] = false;
  }
  return false;
}

// cuenta todas las pinturas válidas por backtracking (sin memo)
void count_all(int pos, int prev, long long &cnt) {
  if (pos == N) { ++cnt; return; }
  for (int c = 0; c < N; ++c) {
    if (used[c]) continue;
    if (pos > 0 && !adj[prev][c]) continue;
    used[c] = true;
    count_all(pos + 1, c, cnt);
    used[c] = false;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T; if (!(cin >> T)) return 0;
  while (T--) {
    cin >> N;
    names.assign(N, "");
    unordered_map<string,int> id;
    for (int i = 0; i < N; ++i) { cin >> names[i]; id[names[i]] = i; }

    adj.assign(N, vector<bool>(N, true));
    for (int i = 0; i < N; ++i) adj[i][i] = false;

    int M; cin >> M;
    while (M--) {
      string a, b; cin >> a >> b;
      int ia = id[a], ib = id[b];
      adj[ia][ib] = adj[ib][ia] = false;
    }

    used.assign(N, false);
    long long total = 0;
    count_all(0, -1, total);
    cout << total << "\n";

    // construir pintura favorita por preferencia (names ya viene en orden de preferencia)
    used.assign(N, false);
    vector<string> fav;
    int prev = -1;
    for (int pos = 0; pos < N; ++pos) {
      for (int cand = 0; cand < N; ++cand) {
        if (used[cand]) continue;
        if (pos > 0 && !adj[prev][cand]) continue;
        used[cand] = true;
        bool ok = exist_completion(pos + 1, cand);
        if (ok) { fav.push_back(names[cand]); prev = cand; break; }
        used[cand] = false;
      }
    }

    for (int i = 0; i < (int)fav.size(); ++i) {
      if (i) cout << ' ';
      cout << fav[i];
    }
    cout << "\n";
  }
  return 0;
}
