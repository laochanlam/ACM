#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    long double a[1001];
    int n;
    int dp_left[1001];
    int dp_right[1001];

    cin >> n;

    for (int i = 0; i < n; i++) {
        dp_left[i] = 0;
        dp_right[i] = 0;
    }

    dp_left[1] = 1 ;
    dp_right[n-1] = 1;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (int j = 0; j < i; j++)
            if ( a[i] > a[j] )
                dp_left[i] = max( dp_left[i], dp_left[j]+1 );

    }

    for (int i = n-1; i >= 0; i--)
        for (int j = i+1; j < n; j++)
            if ( a[i] > a[j] )
                dp_left[i] = max( dp_left[i], dp_left[j]+1 );
    // for (int i = 0; i < n; i++) {
    //     cout<<dp_left[i] << " " << dp_right[i]<<" "<<n-output<<endl;
    // }


    int output = -1;
    for (int i = 0; i < n-1; i++)
        for (int j = i+1; j < n; j++)
        output = max (output, dp_left[i] + dp_right[j]);


        cout<<n - output;

}
