#include<cstdio>
#include<iostream>
using namespace std;


int main(){
    float a,b,ans;
    char c;
    while (scanf("%f%c%f",&a,&c,&b) != EOF){
        if (a == 0 && b == 0) return 0;
        a = a*30+(b*6/12); b = b*6;
        if (a > b){
            ans = a-b;
        }
        else {
            ans = b-a;
        }

        if (ans >180){
            ans = 360 - ans;
        }
        printf("%.3f\n",ans);

    }
    

}
