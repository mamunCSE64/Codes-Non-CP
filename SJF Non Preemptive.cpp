#include <bits/stdc++.h>
#include <iostream>
#define pb push_back
#define fi first
#define se second

using namespace std;
 
// SJF non Preemptime
int main()
{ 
    int n,start=10000;
    cin>>n;
    vector<pair<int,pair<int,int>>> v;
    priority_queue<pair<int,int>,vector<pair<int,int>>,
    greater<pair<int,int>>> pq;

    for(int i=1;i<=n;i++){
        int at,bt;
        cin>>at>>bt; v.pb({at,{bt,i}});
        start=min(start,at);
    }
    int ct=start,count=0;     
    cout << ct << " ";
    while(1){          
        for(int i=0;i<n;i++){
            if(v[i].fi>-1 and v[i].fi<=ct){
                pq.push({v[i].se.fi,v[i].se.se});
                v[i].fi=-1;            
            }               
        }     
        // if(pq.empty()) { cout << "- ",ct++;continue; }    
        int bt=pq.top().fi,p=pq.top().se;
        cout  << "P" << p << " ";
        ct+=bt;          
        cout << ct << " ";
        pq.pop(),count++;
        if(count==n) break;         
    }      
}
