//
//  main.cpp
//  segment_tree
//
//  Created by Ankit Garg on 20/06/18.
//  Copyright © 2018 Ankit Garg. All rights reserved.
//

//segmetn tree for minimum in range



#include <iostream>
#include <algorithm>
#include "cstring"


using namespace std;

void build_tree(int *arr,int start,int end,int index,int *seg_tree)
{
    
    if (start==end)
    {
        seg_tree[index]=arr[start];
        return;
    }
    
    int mid=(start+end)/2;
    build_tree(arr, start, mid, index*2, seg_tree);
    build_tree(arr, mid+1, end, index*2+1, seg_tree);
    seg_tree[index]=min(seg_tree[index*2],seg_tree[index*2+1]);

}


int query(int *seg_tree,int l,int r,int ql,int qr,int node)
{
    
    
    if (ql<=l && qr>=r )
    {
        return seg_tree[node];
        
    }
    if (ql>r || qr<l || ql>qr)
    {
    
        return INT_MAX;
        
    }
   
        int mid=(l+r)/2;
        
        int q1=query(seg_tree, l, mid,ql, qr,node*2);
        int q2=query(seg_tree, mid+1, r, ql, qr,node*2+1);
        
        
        return min(q1,q2);
}


void update_point(int *seg_tree,int l,int r,int node,int i,int value)

{
    if (l==r && l==i)
    {
        seg_tree[node]=value;
        return;
    }
    
    if (i<l || i>r || l>r)
    {
        return;
    }
    
    int mid=(l+r)/2;
    update_point(seg_tree, l, mid, node*2, i, value);
    update_point(seg_tree, mid+1  , r, node*2+1, i, value);
    seg_tree[node]= min(seg_tree[node*2],seg_tree[node*2+1]);
    
}

//increment range by gven no
void update_range(int *seg_tree,int l , int r, int ul,int ur ,int inc,int node)

{

    if ( ul>r || ur<l || l>r )
    {
        return;
    
    }
    
    if (l==r && ul<=l<=ur )
        
    {
        seg_tree[node]+=inc;
        return;
    }
    
    int mid=(l+r)/2;
    
    update_range(seg_tree, l, mid, ul, ur, inc, node*2);
    
    update_range(seg_tree, mid+1, r, ul, ur, inc, node*2+1);
 
    seg_tree[node]=min(seg_tree[node*2],seg_tree[node*2+1]);
    return;
    
    
    
    
    
}

int main(int argc, const char * argv[]) {
    
    
    int n;
    cin>>n;
    int *arr=new int[n];
    for (int i = 0; i<n; i++) {
        cin>>arr[i];
    }
    
    int *seg_tree=new int[4*n+1];
 
    for(int i=0;i<4*n+1;i++)
    {
        seg_tree[i]=0;
        
    }
    
    
    build_tree(arr,0,n-1,1,seg_tree);
    
    
    cout<<"Segment tree:"<<endl;
    for(int i=0;i<4*n+1;i++)
    {
        cout<<seg_tree[i]<<"        ";
        
    }
    
    //update
    /*int index,value;
    cin>>index>>value;
    update_point(seg_tree, 0, n-1, 1, index, value);
    */
     
     
    //range update
    
    cout<<"update range increment by number-"<<endl;
    int ul,ur,inc;
    cin>>ul>>ur>>inc;
    update_range(seg_tree, 0, n-1, ul, ur, inc, 1);
    
    //query
    int c;
    cout<<"No of queries:";
    
    cin>>c;
    while(c--)
    {
    int ql,qr;
    cout<<"Enter range of query:"<<endl;
    cin>>ql>>qr;
    cout<<query(seg_tree, 0, n-1, ql, qr,1)<<endl;
    }
    
    
    return 0;
}
