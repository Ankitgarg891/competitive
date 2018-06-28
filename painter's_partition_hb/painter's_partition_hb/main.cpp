//
//  main.cpp
//  painter's_partition_hb
//
//  Created by Ankit Garg on 25/06/18.
//  Copyright © 2018 Ankit Garg. All rights reserved.
//

#include <iostream>
using namespace std;
#include <vector>
#define ll long long
ll sum_boards(long long start,long long end,vector<long long> a)
{
    long long sum=0;
    for (ll i=start;i<(end);i++)
    {
        sum+=a[i];
        
    }
    
    return sum;
    
}

bool can_paint(ll k,ll n, vector<ll> boards, ll mid,ll sum_all)
{
    
    ll ctr=0;
    ll sum=0;
    
    for(ll i=0;i<n+1;i++)
    {
        if (sum>mid)
        {
            sum=boards[i-1];
            ctr++;
        }
        if (sum==mid)
        {
            ctr++;
            sum=0;
            
        }
        sum+=boards[i];
        
    }
    
    
    if (sum>0)
    {
        ctr++;
    }
    
    
    
    
    cout<<"mid:"<<mid<<"    ctr:"<<ctr<<"   k:"<<k<<endl;
    
    
    if (ctr<=k)
    {
        cout<<"true"<<endl;
        
        return true;
    }
    
    
    cout<<"false"<<endl;
    return false;
    
    
}
ll min_time(ll k,ll n,vector<ll> boards)
{

    ll time=INT_MAX;
    
    
    ll l=*max_element(boards.begin(), boards.end());
    
    
    ll sum_all=sum_boards(0, n, boards);
    ll r=sum_all;
    
    while (r>=l)
    {
        ll mid=(l+r)/2;
        cout<<"l:"<<l<<"    r:"<<r<<"   mid:"<<mid<<endl;
        if (can_paint(k,n,boards,mid,sum_all))
        {
            r=mid-1;
            time=mid;
            
        }
        else
        {
        
            l=mid+1;
        }
        
    
    }
    return time;
}

int main()

{
    ll k;  //no of painters
    ll n;  //no of boards
    cin>>k>>n;
    vector<ll> boards(n);
    for(ll i=0;i<n;i++)
    {
        
        cin>>boards[i];
    }
    
    
    //sort(boards.begin(), boards.end());
    
    boards.push_back(0);
    
    
    cout<<min_time(k,n,boards);
    
    return 0;
}
