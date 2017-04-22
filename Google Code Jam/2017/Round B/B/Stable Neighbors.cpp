#include < iostream >
#include < cstdio >
#include < algorithm >
#include < string >
using namespace std;

/**************************

  Time Limit Exceeded!!!!

**************************/

string list;
string ans;
int N, R, O, Y, G, B, V;
long long int ans_count;
bool endFlag;

bool rule(string A, string B) {
  switch (A[0]) {
  case 'R':
    if (B[0] == 'O' || B[0] == 'V' || B[0] == 'R')
      return false;
    break;
  case 'O':
    if (B[0] == 'O' || B[0] == 'Y' || B[0] == 'R')
      return false;
    break;
  case 'Y':
    if (B[0] == 'G' || B[0] == 'O' || B[0] == 'Y')
      return false;
    break;
  case 'G':
    if (B[0] == 'G' || B[0] == 'B' || B[0] == 'Y')
      return false;
    break;
  case 'B':
    if (B[0] == 'G' || B[0] == 'V' || B[0] == 'B')
      return false;
    break;
  case 'V':
    if (B[0] == 'R' || B[0] == 'V' || B[0] == 'B')
      return false;
    break;
  }
  return true;
}

void backtracking(string in ) {

  // cout  << R << O << Y << G << B << V <<endl;
  if (endFlag) return;
  if ( in == "R") R--;
  if ( in == "O") O--;
  if ( in == "Y") Y--;
  if ( in == "G") G--;
  if ( in == "B") B--;
  if ( in == "V") V--;
  ans_count++;
  ans += in ;
  // cout << ans_count << endl;
  // cout<< ans << endl;
  // cout  << R << O << Y << G << B << V <<endl;
  if (ans_count == N) {
    if (rule( in , "R") && rule( in , ans)) {
      cout << ans << endl;
      endFlag = true;
      return;
    }
    if (rule( in , "O") && rule( in , ans)) {
      cout << ans << endl;
      endFlag = true;
      return;
    }
    if (rule( in , "Y") && rule( in , ans)) {
      cout << ans << endl;
      endFlag = true;
      return;
    }
    if (rule( in , "G") && rule( in , ans)) {
      cout << ans << endl;
      endFlag = true;
      return;
    }
    if (rule( in , "B") && rule( in , ans)) {
      cout << ans << endl;
      endFlag = true;
      return;
    }
    if (rule( in , "V") && rule( in , ans)) {
      cout << ans << endl;
      endFlag = true;
      return;
    }

  }

  if (rule( in , "R") && R > 0)
    backtracking("R");
  if (rule( in , "O") && O > 0)
    backtracking("O");
  if (rule( in , "Y") && Y > 0)
    backtracking("Y");
  if (rule( in , "G") && G > 0)
    backtracking("G");
  if (rule( in , "B") && B > 0)
    backtracking("B");
  if (rule( in , "V") && V > 0)
    backtracking("V");

  ans = ans.substr(0, ans.length() - 1);
  ans_count--;
  if ( in == "R") R++;
  if ( in == "O") O++;
  if ( in == "Y") Y++;
  if ( in == "G") G++;
  if ( in == "B") B++;
  if ( in == "V") V++;
}

int main() {
  int cases;
  int c_counter;
  long long int destination, horse_count;

  cin >> cases;
  for (int i = 1; i <= cases; i++) {
    list = "";
    cin >> N >> R >> O >> Y >> G >> B >> V;
    // for (int j = 0; j < R; j++)
    //     list += "R";
    // for (int j = 0; j < O; j++)
    //     list += "O";
    // for (int j = 0; j < Y; j++)
    //     list += "Y";
    // for (int j = 0; j < G; j++)
    //     list += "G";
    // for (int j = 0; j < B; j++)
    //     list += "B";
    // for (int j = 0; j < V; j++)
    //     list += "V";
    // cout << list << endl;
    endFlag = false;
    // cout  << R << O << Y << G << B << V <<endl;
    cout << "Case #" << i << ": ";
    ans = "";
    ans_count = 0;
    if (R > 0)
      backtracking("R");
    else if (O > 0)
      backtracking("O");
    else if (Y > 0)
      backtracking("Y");
    else if (G > 0)
      backtracking("G");
    else if (B > 0)
      backtracking("B");
    else if (V > 0)
      backtracking("V");
    else cout << "IMPOSSIBLE" << endl;

    if (!endFlag)
      cout << "IMPOSSIBLE" << endl;

  }

}
