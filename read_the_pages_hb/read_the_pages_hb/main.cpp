//
//  main.cpp
//  read_the_pages_hb
//
//  Created by Ankit Garg on 21/06/18.
//  Copyright © 2018 Ankit Garg. All rights reserved.
//

#include <iostream>
using namespace std;
#include <vector>


long long sum_pages(long long start,long long end,vector<long long> a)
{
    long long sum=0;
    for (long long i=start;i<(end);i++)
    {
        sum+=a[i];
    
    }
    
    return sum;

}
bool can_read(long long n,long long m,vector<long long> books,long long  mid,long long sum_max)
{
    long long sum=0;
 
    long long ctr=0;
    
    for (long long i=0;i<n+1;i++)
    {
        if (sum>mid)
        {   ctr++;
            //cout<<" sum10:"<<sum<<endl;
            sum=books[i-1];
        }
        if (sum==mid)
        {
            ctr++;
           // cout<<" sum11:"<<sum<<endl;
            sum=0;
        }
        if(i!=n)
        {
            sum+=books[i];}
       
        
    }
    // cout<<" sum2:"<<sum<<endl;
    if (sum>0)
    {
        ctr++;
        
        //cout<<"incremented 2"<<endl;
    }
   // cout<<"ctr:"<<ctr<<"   m :"<<m;
    if (ctr<=m )
    {
        return true;
    }
    
    

    return false;
}

long long read_pages(long long n,long long m,vector<long long> books)
{
    long long max_pages=-1;
    long long l=books[n-1];
    long long sum_max=sum_pages(0,n,books);
    long long r=sum_max;
    long long mid=(l+r)/2;
    //cout<<"  r:"<<r<<"  l:"<<l<<endl;
    while(r>=l)
    {
    
        mid=(l+r)/2;
        //cout<<"   l:"<<l<<"   r:"<<r<<"   mid:"<<mid<<endl;

        

        
        if (can_read(n,m,books,mid,sum_max))
        {
            r=mid-1;
            max_pages=mid;
            
            //cout<<"\n-----true-----"<<endl;
        
        }
        else
        {
            l=mid+1;
            //cout<<"\n----false------"<<endl;

        }
        
    
    }
    
    

    


    return max_pages;
}


int main() {
    
    long long n;
    cin>>n;
    long long m;
    cin>>m;
    
    vector<long long> books(n);
   
    
    for(long long i=0;i<n;i++)
    {
    
        cin>>books[i];
    }
    cout<<read_pages(n,m,books)<<endl;
    
    
    
    return 0;
}
