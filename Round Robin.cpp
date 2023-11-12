#include <bits/stdc++.h>
#include <iostream>
#define fi first
#define se second
#define pb push_back
using namespace std;
// Round Robin
int main()
{          
    int n,qtime,ct=10000;
    cin>>n>>qtime;
    vector<pair<int,int>> v;
    for(int i=1;i<=n;i++){
        int at,bt;
        cin>>at>>bt;
        v.pb({at,bt});
        ct=min(ct,at);
    }
    queue<pair<int,int>> q;
    for(int i=1;i<=n;i++){
        if(v[i-1].fi==ct){
            q.push({v[i-1].se,i});
            v[i-1].fi=-1;
        }
    }
    cout << ct << " ";
    while(q.size()){
        int x=q.front().fi,p=q.front().se;
        q.pop();
        cout << "P" << p << " ";
        if(x<=qtime) ct+=x,x=0;
        else x-=qtime,ct+=qtime;
        cout << ct << " ";
        for(int i=1;i<=n;i++){
            if(v[i-1].fi<=ct and v[i-1].fi!=-1){
                q.push({v[i-1].se,i});
                v[i-1].fi=-1;
            }
        }
        if(x) q.push({x,p});
    }
}
