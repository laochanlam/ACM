#include<cstdio>
#include<cstdio>
using namespace std;


int gcd(int a, int b)
{
    while (b){
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}


int main(){
    int a,b;
    while (scanf("%d%d",&a,&b) != EOF)
        printf("%10d%10d    %s\n\n",a,b,gcd(step,mod) == 1 ? "Good Choice":"Bad Choice");
}
