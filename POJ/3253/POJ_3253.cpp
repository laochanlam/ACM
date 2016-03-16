#include<queue>
#include<iostream>
#include<cstdio>
using namespace std;

int main(){
    int n,i;
    long long ans = 0;
    long long int l = 0;
    priority_queue< long long int,vector<long long int>,greater<long long int> > pq;
    while (scanf("%d",&n)!=EOF)
    {
        for (i=0;i<n;i++)
        {
            scanf("%lld",&l);
            pq.push(l);
        }
        l = 0;
        while (pq.size() != 1)
        {
            l = 0;
            l = pq.top() + l;
            pq.pop();
            l = pq.top() + l;
            pq.pop();
            pq.push(l);
            ans = ans + l;
        }
            cout<<ans;

    }
}
