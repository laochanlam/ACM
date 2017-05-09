#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
 
bool appear[10010];
int a[10010];
int n;
long long int ans;

void recursive (int depth) {

    if (depth == n) {
        int maxi = -1;
        int mini = -1;
        for (int i = 0; i < n; i++)
            if ( appear[i] ) {
                mini = i;
                break;
            }
        for (int i = n-1; i > 0; i--)
            if ( appear[i] ) {
                maxi = i;
                break;
            }

            if ( maxi != -1 && mini != -1)
                ans += a[maxi] - a[mini];
            if (ans > 1000000007)
                ans %= 1000000007;
        return;
    }

    appear[depth] = true;
    recursive(depth+1);

    appear[depth] = false;
    recursive(depth+1);
}


int main(){
    int T;

    cin >> T;
    for (int k = 0; k < T; k++) {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        ans = 0;
        recursive(0);
        cout << "Case #" << k+1 << ": " << ans << endl;
    }
}