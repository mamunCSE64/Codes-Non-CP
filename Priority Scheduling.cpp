#include <bits/stdc++.h>
#include <iostream>
#define fi first
#define se second

using namespace std;
// Priority Scheduling,Non Preemptive
int main()
{          
    int n;
    cin>>n;
    priority_queue<pair<pair<int,int>,int>,
    vector<pair<pair<int,int>,int>>,greater<pair<pair<int,int>,int>>> pq;
    for(int i=1;i<=n;i++){
        int bt,priority;
        cin>>bt>>priority;
        pq.push({{priority,bt},i});
    }
    int ct=0;
    cout << ct << " ";
    while(pq.size()){
        cout << "P" << pq.top().se << " ";
        ct+=pq.top().fi.se;
        cout << ct << " ";
        pq.pop();
    }
}
