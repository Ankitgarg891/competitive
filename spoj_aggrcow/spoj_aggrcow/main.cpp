//
//  main.cpp
//  spoj_aggrcow
//
//  Created by Ankit Garg on 19/06/18.
//  Copyright © 2018 Ankit Garg. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

bool canplace(int *stalls,int c,int n,int m)
{
    int s=0;
    int ctr=1;
    
    for (int i=1;i<n;i++)
    {
        if (stalls[i]-stalls[s]>=m)
        {
            ctr++;
            s=i;
        }
    }
    
    
    if (ctr>=c)
    {
        return true;
    }
    
    else
    {
    
        return false;}
}

int aggrcows(int *stalls,int c,int n)
{
    int max_distance=-1;
    
    int l=stalls[0];
    int r=stalls[n-1];
    
    
    
    while (r>=l) {
        int m=(l+r)/2;

        
        if (canplace(stalls,c,n,m))
        {
            l=m+1;
            max_distance=m;
        
        }
        else
        {
            r=m-1;
        
        
        }
        
        
    
    }
    
    

    return max_distance;
}







int main(int argc, const char * argv[]) {
    // insert code here...
    
    
    int c;
    cin>>c;
    
    for (int i=0;i<c;i++)
    {
        int n;
        cin>>n;
        int c;
        cin>>c;
        int a;
        int stalls[n];
        
        for(int i=0;i<n;i++)
        {   cin>>a;
            stalls[i]=a;
            
        }
        
        sort(stalls,stalls+n);
        
        
        
        cout<<aggrcows(stalls, c, n)<<endl;
        
        
    
    }
    
    
    
    
    return 0;
}
