#include <iostream>
#include <string>

using namespace std;

int GetMoviments(int bottles[9], int first_min, int second_min, int third_min) {
  int moviments = 0;
  moviments += bottles[first_min + 3] + bottles[first_min + 6];
  moviments += bottles[second_min + 6] + bottles[second_min];
  moviments += bottles[third_min] + bottles[third_min + 3];
  return moviments;
}

string GetColorName(int c) {
  switch(c){
    case 0: return "B";
    case 1: return "G";
    case 2: return "C";
  }
  return "";
}

int main() {
  int num[6][3] = {{0, 2, 1}, {0, 1, 2},
                   {2, 0, 1}, {2, 1, 0},
                   {1, 0, 2}, {1, 2, 0}};
  int bottles[9];
  int mov, min, min_i;
  while (cin >> bottles[0] >> bottles[1] >> bottles[2] >> 
                bottles[3] >> bottles[4] >> bottles[5] >>
                bottles[6] >> bottles[7] >> bottles[8]) {
    min = GetMoviments(bottles, num[0][0], num[0][1], num[0][2]);
    min_i = 0;
    for (int i = 1; i < 6; i++) {
      mov = GetMoviments(bottles, num[i][0], num[i][1], num[i][2]);
      if(min > mov) {
        min = mov;
        min_i = i;
      }
    }
    cout << GetColorName(num[min_i][0]) << GetColorName(num[min_i][1]) 
         << GetColorName(num[min_i][2]) << " " << min << endl;
  }
  
  return 0;
}
