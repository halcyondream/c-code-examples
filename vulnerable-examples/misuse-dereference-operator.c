int main() {
  // Good.
  int n;
  int *np = &n;

  // Bad.
  int m;
  int *mp;
  *mp = &m;

  // good.
  int o;
  int *op;
  op = &o;
}