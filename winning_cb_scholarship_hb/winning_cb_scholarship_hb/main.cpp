//
//  main.cpp
//  winning_cb_scholarship_hb
//
//  Created by Ankit Garg on 22/06/18.
//  Copyright © 2018 Ankit Garg. All rights reserved.
//

#include <iostream>
using namespace std;

long long max_stud(long long n,long long m,long long x,long long y)
{
    long long max_stud=0;
    
    long long l=0;
    long long r=n;
    
    long long mid=(l+r)/2;
    
    while(r>=l)
    {
        mid=(l+r)/2;
    
       if ((mid*x)<=m+(n-mid)*y )
        {
            l=mid+1;
            max_stud=mid;
        }
        else
        {
            r=mid-1;
            
        }
    
    }
    return max_stud;
}

int main(int argc, const char * argv[]) {
    long long n,m,x,y;
    cin>>n>>m>>x>>y;
    
    cout<<max_stud(n,m,x,y)<<endl;
    return 0;
}
