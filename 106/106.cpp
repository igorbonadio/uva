#include <iostream>
#include <vector>
#include<cstdlib>
#include<cmath> 

using namespace std;

int GCD(int x, int y) {
	if (y > 0)
		return GCD(y, x%y);
	else
		return x;
}

void FermatVsPythagoras(int n) {
	int total, others, sqrt_n;
	vector<int> num(n+1);
	sqrt_n = sqrt(static_cast<double>(n));
	total = 0;
	int c = 0;
	for (int r = 1; r <= sqrt_n; r++) {
		for (int s = r+1; s <= sqrt_n; s++) {
			c++;
			int x = abs(r*r-s*s);
			int y = 2*r*s;
			int z = r*r+s*s;
			if (z > n)
				continue;
			for(int k = 1; k*z<=n; k++) {
				num[k*x] = 1;
				num[k*y] = 1;
				num[k*z] = 1;
			}
			if (GCD(x,y)==1)
				total++;
		}
	}
	others = 0;
	for (int i = 1; i <= n; i++)
		if (!num[i])
			others++;
	cout << total << " " << others << endl;
}

int main() {
	int n;
	while (cin >> n)
		FermatVsPythagoras(n);
	return 0;
}
