#include <iostream>
#include <vector>

using namespace std;

int main() {
  int v;
  int n;
  int max;
  int cmax;
  vector<vector<int > > s(101, vector<int > (101, 0));

  while (cin >> n) {

    for (int i = 1; i <= n; i++)
      for (int j = 0; j < n; j++)
        cin >> s[i][j];

    for (int i = 1; i <= n; i++)
      for (int j = 0; j < n; j++)
        s[i][j] = s[i-1][j] + s[i][j];

    max = s[1][0];

    for (int a = 0; a <= n; a++) {
      for (int b = a+1; b <= n; b++) {
        // Kadane's Algorithm
        cmax = 0;
        for (int col = 0; col < n; col++) {
          cmax += s[b][col] - s[a][col];
          if (cmax > max)
            max = cmax;
          if (cmax < 0)
            cmax = 0;
        }
      }
    }

    cout << max << endl;
  }

  return 0;
}
