#include <iostream>
#include <vector>

using namespace std;

int Max(int a, int b) {
  return (a > b) ? a : b;
}

int Score(vector<int> correct, vector<int> student) {
  int n = correct.size();
  int temp = 0;
  int temp2 = 0;
  vector<int> score(n, 0);
  for (int i = 1; i < n; i++) {
    temp = 0;
    for (int j = 1; j < n; j++) {
      temp2 = score[j];
      if (correct[i] == student[j])
        score[j] = temp + 1;
      else
        score[j] = Max(score[j-1], score[j]);
      temp = temp2;
    }
  }
  return score[n-1];
}

int main() {
  int n, x;
  
  cin >> n;
  vector<int> correct(n+1, 0);
  for (int i = 1; i < n+1; i++) {
    cin >> x;
    correct[x] = i;
  }
  
  vector<int> student(n+1, 0);
  while (cin >> x) {
    student[x] = 1;
    
    for (int i = 2; i < n+1; i++) {
      cin >> x;
      student[x] = i;
    }
    
    cout << Score(correct, student) << endl;
    
  }
  return 0;
}
