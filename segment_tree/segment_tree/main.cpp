//
//  main.cpp
//  segment_tree
//
//  Created by Ankit Garg on 20/06/18.
//  Copyright © 2018 Ankit Garg. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstring>

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
    
    
    cout<<"\n----------------"<<endl;
    for(int i=0;i<4*n+1;i++)
    {
        cout<<seg_tree[i]<<"        ";
        
    }
    cout<<"\n----------------"<<endl;
    
    
    
    
    return 0;
}
