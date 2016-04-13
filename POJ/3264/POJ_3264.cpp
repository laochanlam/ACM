#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;

struct node{
    int l,r;
    int mini,maxi;
    node *left,*right;
};

int counter = 0;
int num[5000];
node tree[5000*2];


void build(node *rt,int l,int r){
    rt->l = l;
    rt->r = r;
    if (l==r)
    {
        rt->mini = num[l];
        rt->maxi = num[r];
        return;
    }

    counter++;
    rt->left = tree + counter;
    counter++;
    rt->right = tree + counter;

    int mid = (l+r) / 2 ;

    build(rt->left,l,mid);
    build(rt->right,mid+1,r);
    rt->mini = min(rt->left->mini,rt->right->mini);
    rt->maxi = max(rt->left->maxi,rt->right->maxi);

}


int ans_max = 0,ans_min = 9999999;

void query(node *rt,int l,int r){
    if (rt->l == l && rt->r == r )
    {
        ans_min = min(rt->mini,ans_min);
        ans_max = max(rt->maxi,ans_max);
        return;
    } 

    int mid = (rt->l+rt->r) / 2;

    if (r <= mid)
        query(rt->left,l,r);
    else if (l > mid)
        query(rt->right,l,r);
    else
    {
    query(rt->left,l,mid);
    query(rt->right,mid+1,r);
    }   
}



int main(){
    int n,m;
    int i,k,j;
    int l,r;
    scanf("%d %d",&n,&m);
    for (i=1;i<=n;i++)
        scanf("%d",&num[i]);
    build(tree,1,n);

    for (i=1;i<=m;i++)
    {
        ans_max = 0; ans_min = 9999999;
        scanf("%d %d",&l,&r);
        query(tree,l,r);
        cout<<ans_max-ans_min<<endl;
    }  
    return 0;

}
