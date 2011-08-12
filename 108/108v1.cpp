#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
	int v;
	int n;
	int max = INT_MIN;
	vector<vector<vector<vector<int > > > > s(100, vector<vector<vector<int > > >(100, vector<vector<int > >(100, vector<int >(100))));

	while (cin >> n) {

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> v;
				s[i][j][i][j] = v;
				if (v > max)
					max = v;
			}
		}
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = i+1; k < n; k++) {
					v = s[i][j][k-1][j] + s[k][j][k][j];
					s[i][j][k][j] = v;
					if (v > max)
						max = v;
				}
			}
		}
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = i; k < n; k++) {
					for (int l = j+1; l < n; l++) {
						v = s[i][j][k][l-1] + s[i][l][k][l];
						s[i][j][k][l] = v;
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
