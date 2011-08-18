#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
  double x, y;
  
  bool operator <(const Point &p) const {
    return x < p.x || (x == p.x && y < p.y);
  }
  
};

typedef vector<Point > VPoint;
typedef vector<VPoint > VVPoint;

double IsLeft( Point p0, Point p1, Point p2 ) {
  return (p1.x - p0.x)*(p2.y - p0.y) - (p2.x - p0.x)*(p1.y - p0.y);
}

int ChainHull2D(VPoint p, VPoint &h ) {
  int n = p.size();
  int k = 0;
  
  sort(p.begin(), p.end());
  
  for (int i = 0; i < n; i++) {
    while (k >= 2 && IsLeft(h[k-2], h[k-1], p[i]) <= 0)
      k--;
    h[k++] = p[i];
  }
  
  for (int i = n-2, t = k+1; i >= 0; i--) {
    while (k >= t && IsLeft(h[k-2], h[k-1], p[i]) <= 0)
      k--;
    h[k++] = p[i];
  }
  
  return k;
}

int Check(VPoint h, Point p) {
  int n = h.size();
  int i, j, c = 0;
  for (i = 0, j = n-1; i < n; j = i++)
    if ((((h[i].y <= p.y) && (p.y < h[j].y)) || ((h[j].y <= p.y) && (p.y < h[i].y))) && (p.x < (h[j].x - h[i].x) * (p.y - h[i].y) / (h[j].y - h[i].y) + h[i].x))
      c = !c;
  return c;
}

double Area(VPoint p) {
  int n = p.size();
  double s = 0;
  for (int i = 1; i < n; i++) {
    s += ((p[i-1].x * p[i].y) - (p[i].x * p[i-1].y))/2;
  }
  return s;
}

int main() {
  int n;
  VVPoint hull;
  
  while (true) {
    cin >> n;
    if (n == -1)
      break;
    
    VPoint p(n);
    for (int i = 0; i < n; i++) {
      cin >> p[i].x >> p[i].y;
    }
  
    VPoint h(n+1);
    n = ChainHull2D(p, h);
    h.resize(n);
    hull.push_back(h);
  }
  
  Point k;
  double a = 0;
  while (cin >> k.x >> k.y) {
    VVPoint::iterator it;
    for (it = hull.begin(); it < hull.end(); it++ ) {
      if (Check(*it, k)) {
        a += Area(*it);
        hull.erase(it);
        break;
      }
    }
  }
  
  cout.precision(2);
  cout.setf(ios::fixed,ios::floatfield);
  cout << a << endl;

  return 0;
}
