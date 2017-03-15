#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

#define PI 3.14159265358979323846
#define GAP 0.000001

int main() {
    int counter;
    
    cin >> counter;
    while( counter-- ) {
        double B, H, C ;
        double temp ;
        scanf("%lf %lf", &B, &H);
        double area = B*H/2;
        C = 0;
        double L = sqrt( H * H + B * B / 4 ) * 2 + B ;
        double R = area*2 / L;
        
        
        while( R >= GAP ) {
            C = R * PI * 2 + C;
            temp = H;    
            H = H - 2 * R;
			R = R * H / temp;
        }
        printf("%13.6lf\n", C );
        if( counter )
            puts("");
    }
}
