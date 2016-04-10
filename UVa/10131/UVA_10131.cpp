#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct ele{
    int num;
    int weight;
    int IQ;
};

bool cmp(ele a,ele b){
    if (a.weight < b.weight) return true;
    else
    {
        if (a.weight == b.weight)
            return a.IQ >b.IQ;
        else return false;
    }

}

void prt(vector<ele> &elephant,vector<int> &indexvector,int index){
    if (indexvector[index] != -1) prt(elephant,indexvector,indexvector[index]);
    printf("%d\n",elephant[index].num);
}

int main(){
    vector <ele> elephant;
    ele ele;
    int i,j,k,m,n;
    int max; int index;
    while (scanf("%d %d",&ele.weight,&ele.IQ)!=EOF)
    {
        ele.num = elephant.size()+1;
        elephant.push_back(ele);
    }

    sort(elephant.begin(),elephant.end(),cmp);

    vector<int> length(elephant.size(),1);
    vector<int> prev(elephant.size(),-1);

    max = 0;

    for (i=0;i<elephant.size();i++)
        for (j=i+1;j<elephant.size();j++)
    {
        if ( elephant[i].IQ > elephant[j].IQ && elephant[i].weight < elephant[j].weight )
            if (length[i]+1 > length[j])
        {
            length[j] = length[i] +1;
            prev[j] = i;
        }
    }

    for (i=0;i<elephant.size();i++)
        if (length[i] > max) {max = length[i]; index = i;}
    
    cout<<max<<endl;
    prt(elephant,prev,index);

    for (i=0;i<elephant.size();i++)
        cout<<elephant[i].num<<" "<<elephant[i].IQ<<"     ";
        cout<<endl<<max;





}
