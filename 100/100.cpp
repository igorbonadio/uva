#include <map>
#include <iostream>

using namespace std;

map<int,int> cycle;

int GetCycle(int n) {
  if (cycle[n]) 
    return cycle[n];
  if (n==1) return 1;
  if (n%2 == 1) {
    cycle[n] = GetCycle((3*n+1)/2) + 2;
  } else {
    cycle[n] = GetCycle(n/2) + 1;
  }
  return cycle[n];
}

int MaxCycle(int a, int b) {
  int max = 0;
  int curr;
  for (int i = a; i <= b; i++) {
    curr = GetCycle(i);
    if (max < curr)
      max = curr;
  }
  return max;
}

int main() {
  int a, b, max;
  while (cin >> a >> b) {
    if (a > b)
      max = MaxCycle(b, a);
    else
      max = MaxCycle(a, b);
    cout << a << " " << b << " " << max << endl;
  }
  return 0;
}
