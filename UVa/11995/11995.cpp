
#include<iostream>
#include<stack>
#include<queue>
#include<cstdio>
using namespace std;

int main(){
    int m,number,i,k,j,n;
    int qc = 0;
    int pqc = 0;
    int sc = 0;
    queue<int> q;
    stack<int> s;
    priority_queue<int> pq;
//    freopen("input.in","rt",stdin);
//    freopen("output.out","wt",stdout);
    while ( scanf("%d",&n) != EOF )
    {
        for (i=0;i<n;i++)
        {
            scanf("%d",&m);
            if (m == 1)
            {
                scanf("%d",&number);
                q.push(number);
                s.push(number);
                pq.push(number);
            }


            if (m == 2)
            {
                scanf("%d",&number);
                if (!q.empty()) 
                {
                    if ( q.front() !=number ) qc=1;
                    q.pop();
                }

 
                if (!s.empty())
                {
                    if (s.top() != number) sc = 1;
                    s.pop();
                }


                if (!pq.empty())
                {
                    if (pq.top() != number) pqc = 1;
                    pq.pop();
                }

            }
      
        }

/*    
    if (qc == 0 || sc == 0 || pqc == 0)
        {
           if ((qc == 0 && sc == 0) || (qc == 0 && pqc == 0) || (sc == 0 && pqc == 0))
                {
                    cout<<"not sure"<<endl;
                }        
            else
                {
                    if (qc == 0 )
                     cout<<"queue"<<endl;
                    if (sc == 0 )
                     cout<<"stack"<<endl;
                    if (pqc == 0)
                     cout<<"priority queue"<<endl;
                }
        }
    else
        {
            cout<<"impossible"<<endl;          
        }
*/
	  if ((qc == 0 && sc == 0) || (qc == 0 && pqc == 0) || (sc == 0 && pqc == 0))
            puts("not sure");
        else if (sc == 0) puts("stack");
        else if (qc == 0) puts("queue");
        else if (pqc == 0) puts("priority queue");
        else puts("impossible");

    qc = 0; sc = 0; pqc = 0;
 
    while (!q.empty())  q.pop();
    while (!s.empty())  s.pop();
    while (!pq.empty()) pq.pop();
    }

return 0;
}

