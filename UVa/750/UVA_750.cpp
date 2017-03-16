#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int chess[9][9];
int queen;
int soluation;
int position[20][9];

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

    if (queen == 8) {
        soluation++;
        return ;
    }

    for (int i=x; i<=8; ++i) {
      for (int j=1; j<=8; ++j) {
        if ( condition( i, j ) ) {
          chess[i][j] = 1;
          for (int k=soluation; k<20; k++)
              position[k][j] = i;
          queen++;
          backtracking(i,j);
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

    while (cases--) {
        queen = 1;
        soluation = 1;

        for (int i=1; i<=8; i++)
            for (int j=1; j<=8; j++)
                chess[i][j] = 0;
        cin>>inital_x>>inital_y;

        cout<<"SOLN       COLUMN"<<endl;
        cout<<" #      1 2 3 4 5 6 7 8"<<endl<<endl;
        chess[inital_x][inital_y] = 1;
        for (int i=0; i<20; i++)
            position[i][inital_y] = inital_x;
        backtracking(1,1);

                  int temp, fuck;
                  for (int i=1; i<soluation; i++) {
                      for (int j=i+1; j<soluation; j++) {
                          fuck = 1;
                          while ( fuck <= 8 ) {
                              if ( position[i][fuck] < position[j][fuck] ) break;
                              else if ( position[i][fuck] == position[j][fuck] )
                                  fuck++;
                              else if ( position[i][fuck] > position[j][fuck] ) {
                                  for (int exc_i = 1; exc_i <=8; exc_i++) {
                                      temp = position[i][exc_i];
                                      position[i][exc_i] = position[j][exc_i];
                                      position[j][exc_i] = temp;
                                  }
                                  break;
                              }
                          }
                      }
                  }



          for (int i=1; i<soluation; i++) {
              printf("%2d",i);
              cout<<"     ";
                  for (int k=1; k<=8; k++)
                      cout<<" "<<position[i][k];
                  cout<<endl;
          }

          if ( cases != 0)
          cout<<endl;
    }
}
