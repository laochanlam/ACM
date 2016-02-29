#include<cstdio>
#include<string>
#include<iostream>
using namespace std;

float counter (string str){
    int i;
    long long int count = 0;
    long long int ans = 0;
    for (i=0;i<str.length();i++)
    {
        if (str[i]>= 'A' && str[i]<= 'Z')
        {
            count = count + ( str[i] - 'A'+1 );
        }
        if (str[i]>= 'a' && str[i]<= 'z')
        {
            count = count + ( str[i] - 'a'+1 );
            
        }
    }
    if ( count == 0) return 9876;

    while (1)
    {
    
        ans = ans + ( count % 10 );
        count = count / 10 ;
        if (count == 0)
            if (ans <= 9)
        {
            break;
        }
        else
        {
            count = ans;
            ans = 0;
        }

    }
    
    return ans;
}

int main(){
    string str1,str2;
    float a,b,c;
    str1.clear(); str2.clear();
    while(getline(std::cin,str1))

    {
        getline(std::cin,str2);
    
        a = counter(str1);
        b = counter(str2);
        str1.clear(); str2.clear();
        
    if (a == 9876 && b == 9876)
        {
            printf("\n");
        }
        else{
    if (a == 9876 || b == 9876)
            {
                printf("0.00 %%\n");

            }
        else{
    if (a > b) c = b / a *100;
    if (a <= b) c = a / b *100;
    printf("%.2f %%\n",c);
            }
            
            }
    }
}
