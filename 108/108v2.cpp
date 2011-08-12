#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
	int v;
	int n;
	int max = INT_MIN;
	vector<vector<int > > s(101, vector<int > (101, 0));

	while (cin >> n) {

		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> v;
				s[i][j] = v;
				if (v > max)
					max = v;
			}
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < n; j++) {
				v = s[i-1][j] + s[i][j];
				s[i][j] = v;
				if (v > max)
					max = v;
			}
		}

		for (int i = 0; i <= n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = i+1; k <= n; k++) {
					v = 0;
					for (int l = j; l < n; l++) {
						v += s[k][l] - s[i][l];
						if (v > max)
							max = v;
					}
				}
			}
		}

		cout << max << endl;
	}

	return 0;
}
