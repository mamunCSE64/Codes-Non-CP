#include <bits/stdc++.h>
#include <iostream>
#define ll long long int
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front

#define nl << endl
#define sp << " "
#define mp make_pair
#define fi first
#define se second
#define Mx LLONG_MAX
#define Mn LLONG_MIN

using namespace std;
// SJF Preemptive
int main()
{          
    int n,start=10000;
    cin>>n;
    vector<pair<int,pair<int,int>>> v; map<int,int> m;
    for(int i=1;i<=n;i++){
        int at,bt;
        cin>>at>>bt; 
        start=min(start,at);
        v.pb({at,{bt,i}});
        m[at]++;
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,
    greater<pair<int,int>>> pq;
    sort(v.begin(),v.end());   
    int ct=start,i=1;
    cout << ct sp;
    next:
    while(v[i-1].fi==ct and i<=n){
        pq.push({v[i-1].se.fi,v[i-1].se.se}),i++;
    }
    while(pq.size()){
        int time=pq.top().fi,p=pq.top().se;
        pq.pop();
        ct++,time--;
        if(!time){ cout << "P" << p sp <<  ct sp;goto next; }            
        else if(m[ct]){
            pq.push({time,p});
            cout << "P" << p sp <<  ct sp;goto next;
        }    
        else pq.push({time,p});
    }
}
