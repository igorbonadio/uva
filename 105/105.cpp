#include <iostream>

using namespace std;

void PutBuild(int height[], int a, int h, int b) {
  for (int i = a; i < b; i++)
    if (height[i] < h)
      height[i] = h;
}

void Skyline(int height[], int max_x) {
  int h = 0;
  for (int i = 0; i <= max_x; i++) {
    if (height[i] != h) {
      h = height[i];
      cout << i << " " << h << (max_x == i ? "" : " ");
    }
  }
  cout << endl;
}

int main() {
  int height[10001] = {0};
  int a, h, b, max_x = 0;
  while (cin >> a >> h >> b) {
    PutBuild(height, a, h, b);
    if (b > max_x)
      max_x = b;
  }
  Skyline(height, max_x);
  return 0;
}
