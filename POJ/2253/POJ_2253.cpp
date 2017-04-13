#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;

struct coordinate {
    int x;
    int y;
} data[201];

double table [201][201];

int main(){
    int c_counter = 0;
    int n;
    while (1) {
        c_counter++;
        cin >> n;
        if ( n == 0 ) return 0;
        for (int i = 0; i < n; i++)
            cin >> data[i].x >> data[i].y;
            
        for (int i = 0; i < n; i++)
            for (int j = i+1; j < n; j++)
                table[i][j] = table[j][i] = sqrt( pow(abs(data[i].x - data[j].x),2)  + pow(abs(data[i].y - data[j].y),2)  );

        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    table[i][j] = min ( max (table[i][k], table[k][j]), table[i][j]);

        printf("Scenario #%d\nFrog Distance = %.3f\n\n",c_counter,table[0][1]);

    }
}
