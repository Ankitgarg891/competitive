//
//  main.cpp
//  prata_spoj
//
//  Created by Ankit Garg on 18/06/18.
//  Copyright © 2018 Ankit Garg. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool can_cook(int p,int l,vector<int> cooks,int mid)

{
    
    int ctr=0;
    
    for (int i=0;i<l;i++)
    {
       // cout<<"for "<<i<<" cook"<<floor(-1.0+sqrt(1.0+(8.0*(float)mid)/(float)cooks[i]))/2.0<<endl;
        
        ctr+=(-1+sqrt(1+(8*(float)mid)/(float)cooks[i]))/2;
        
    }
    
    //cout<<"ctr:"<<ctr<<endl;
    
    if (ctr>=p)
    {
        return true;
    }
    return false;
}
int min_time(int p,int l,vector <int> cooks)
{
    
    int min_time=-1;
    
    int left=1;
    int right=(4*p*p)+(4*p);
    
    int mid=(left+right)/2;
    
    
    
    while (right>=left)
    {
    
      mid=(left+right)/2;
        
    //cout<<"  left:"<<left<<"  right:"<<right<<"  mid:"<<mid<<endl;
      if (can_cook(p,l,cooks,mid))
            {
                right=mid-1;
                min_time=mid;
                //cout<<"true"<<endl;
            }
      else
            {
                left=mid+1;
               // cout<<"false"<<endl;
            }
            
            
    }
        
        
        
   
    
    
    
    
    
    return min_time;



}
int main(int argc, const char * argv[]) {
    
    int test;
    cin>>test;
    
    for (int i=0;i<test;i++)
    {
        
        int p;
        cin>>p;
        int l;
        cin>>l;
        
        vector <int> cooks(l);
        
        for (int i=0;i<l;i++)
        {
            cin>>cooks[i];
        }
        
        cout<<min_time(p,l,cooks)<<endl;
        
        
    
    
    }
    
    
    
    
    return 0;
}
