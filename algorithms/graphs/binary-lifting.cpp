const int MAXN = 2e5, MAXLOG2 = 60;
int bl[MAXN][MAXLOG2 + 1];

int jump(int u, ll k) {
  for (int i = 0; i <= MAXLOG2; i++)
    if (k & (1LL << i)) u = bl[u][i];

  return u;
}

void build(int N) {
  for (int i = 1; i <= MAXLOG2; i++)
    for (int j = 0; j < N; j++) bl[j][i] = bl[bl[j][i - 1]][i - 1];
}
