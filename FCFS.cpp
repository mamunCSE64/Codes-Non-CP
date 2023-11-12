#include <bits/stdc++.h>
#include <iostream>
#define fi first
#define se second

using namespace std;
// FCFS
int main()
{ 
    priority_queue<pair<pair<int,int>,int>,
    vector<pair<pair<int,int>,int>>,greater<pair<pair<int,int>,int>>> pq;
    int process;
    cin>>process;
    for(int i=1;i<=process;i++){
        int at,bt;
        cin>>at>>bt;
        pq.push({{at,bt},i});
    }
    int time=0;
    cout << time << " ";
    while(pq.size()){
        cout << "P" << pq.top().se << " ";
        time+=pq.top().fi.se;
        cout << time << " ";
        pq.pop();
    }
}
