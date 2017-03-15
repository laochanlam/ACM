#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int chess[9][9];
int queen;
int soluation;

bool condition( int x, int y ) {
    int cur_x,cur_y;

    if ( chess[x][y] ) return false;
    for (int i=1; i<=8; i++) {
      if (y != i)
          if ( chess[x][i] ) return false;
      if (x != i)
          if ( chess[i][y] ) return false;
    }

    cur_x = x;
    cur_y = y;
    while ( cur_x+1 <=8 && cur_y+1 <=8 && cur_x+1 >=1 && cur_y+1 >= 1 ) {
        cur_x++;
        cur_y++;
        if ( chess[cur_x][cur_y] ) return false;
    }
    cur_x = x;
    cur_y = y;
    while ( cur_x-1 <=8 && cur_y-1 <=8 && cur_x-1 >=1 && cur_y-1 >= 1 ) {
        cur_x--;
        cur_y--;
        if ( chess[cur_x][cur_y] ) return false;
    }
    cur_x = x;
    cur_y = y;
    while ( cur_x+1 <=8 && cur_y-1 <=8 && cur_x+1 >=1 && cur_y-1 >= 1 ) {
        cur_x++;
        cur_y--;
        if ( chess[cur_x][cur_y] ) return false;
    }
    cur_x = x;
    cur_y = y;
    while ( cur_x-1 <=8 && cur_y+1 <=8 && cur_x-1 >=1 && cur_y+1 >= 1 ) {
        cur_x--;
        cur_y++;
        if ( chess[cur_x][cur_y] ) return false;
    }

    return true;
}

void backtracking( int x, int y ) {


// cout<<endl<<"this is term: "<<x<<y<<endl;


    // for (int i=1; i<=8; ++i) {
    //     for (int j=1; j<=8; ++j) {
    //         cout<<chess[i][j];
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;

    if (queen == 8) {
        soluation++;
        return ;
    }

    for (int i=x; i<=8; ++i) {
      for (int j=1; j<=8; ++j) {
        if ( condition( i, j ) ) {

          // cout<<endl<<i<<j<<"QUEEN="<<queen<<endl;
          chess[i][j] = 1;
          queen++;


              cout<<endl<<"next" <<i<<j<<endl;
              backtracking(i,j);
              // cout<<"quit to up";


          chess[i][j] = 0;
          queen--;
        }
      }
    }

}

int main() {
    int cases;
    int inital_x,inital_y;

    cin>>cases;
    soluation = 0;

    while (cases--) {
        queen = 1;

        memset(chess, 0, sizeof(chess));
        cin>>inital_x>>inital_y;

        cout<<"SOLN      COLUMN"<<endl;
        cout<<" #"<<"    1 2 3 4 5 6 7 8"<<endl<<endl;
        chess[inital_x][inital_y] = 1;
        backtracking(1,1);
        cout<<soluation;
    }
}
