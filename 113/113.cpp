#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

unsigned long long Root(double n, double p) {
  double result = exp(log(p)/n);
  double i;
  return modf(result, &i) >= 0.5 ? ceil(result) : floor(result);
}

int main() {
  double n, p;
  while (cin >> n >> p) {
    cout << Root(n, p) << endl;
  }
  return 0;
}
