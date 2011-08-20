#include <iostream>
#include <string>

using namespace std;

void spaces() {
  while(cin.peek() == ' ' || cin.peek() == '\n')
    cin.ignore(1);
}

// Returns true if node is ()
bool node(int sum, int val, bool *output) {
  int v, signal = 1;
  spaces();
  cin.ignore(1); // (
  spaces();
  if (cin.peek() == ')') {
    cin.ignore(1); // )
    return sum == val? true : false;
  }
  spaces();
  if(cin.peek() == '-') {
    signal = -1;
    cin.ignore(1);
  }
  cin >> v; // number
  v *= signal;
  bool n1 = node(sum + v, val, output);
  bool n2 = node(sum + v, val, output);
  if (n1 && n2)
    *output = true;
  spaces();
  cin.ignore(1); // )
  return false;
}

int main() {
  int val;
  bool output;
  while (cin >> val) {
    output = false;
    node(0, val, &output);
    cout << (output ? "yes" : "no") << endl;
  }
  return 0;
}