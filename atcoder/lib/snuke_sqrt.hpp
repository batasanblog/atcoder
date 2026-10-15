ll sqrt_(ll x) {
  ll l = 0, r = INF+1;
  while (l+1<r) {
    ll c = (l+r)/2;
    if (c*c <= x) l = c; else r = c;
  }
  return l;
}
