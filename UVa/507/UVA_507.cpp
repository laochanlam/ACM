#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
#define MAXN 20010

int t , s;
int value[MAXN];
long long  dp[MAXN];
int start , end_point , len;

void solve(int k){
    long long max;
    int start_point , temp , lentgh;
    memset(dp , 0 , sizeof(dp));
    start = 1 ; end_point = 2 ; len = 1;
    start_point = 1 ; temp = 2 ; lentgh = 1;
    dp[1] = value[1] ; max = dp[1];
    for(int i = 2 ; i < s; i++){
        if(dp[i-1] >= 0){
            dp[i] = dp[i-1]+value[i];
            temp = i+1 ;  lentgh++ ;
            if(max < dp[i]){
                max = dp[i] ;
                start = start_point ; end_point = temp;
                len = lentgh;
            }
            else if(max == dp[i]){
                if(lentgh > len){
                   start = start_point ; end_point = temp;
                   len = lentgh;
                }
            }
        }
        else {
            dp[i] = value[i] ; start_point = i;
            temp = i+1 ; lentgh = 1;
            if(max < dp[i]){
                max = dp[i] ; len = lentgh;
                start = start_point ; end_point = temp;
            }
        }
    }
    printf("The nicest part of route %d is between stops %d and %d\n",k , start , end_point);
}

int main() {
    int i , k , flag;
    scanf("%d", &t);
    for(k = 1 ; k <= t ; k++){
        scanf("%d", &s) ; flag = 0;
        for(i = 1 ; i < s; i++){
            scanf("%d", &value[i]);
            if(value[i] > 0) flag = 1;
        }
        if(flag) solve(k);
        else printf("Route %d has no nice parts\n" , k);
    }
    return 0;
}
