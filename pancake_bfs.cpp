#include <bits/stdc++.h>
#include <iostream> 
using namespace std;
int i, j, k, n, m;
 
int main()
{ 
    ios::sync_with_stdio(0);
    cin.tie(nullptr);   

    int n,range;
    cin>>n>>range;
    vector<int> v;
    for(i=0;i<=n;i++){
        int random_num=rand()%range+1;
        v.push_back(random_num);
    }
    cout << "First array : " << endl;
    for(auto x: v) cout << x << " ";cout << endl << endl;
    cout << "Will be sorted after reversing : " << endl;
    vector<int> result=v;
    sort(result.begin(),result.end());        
    map<vector<int>,vector<int>> index;
    map<vector<int>,int> visited;
    vector<vector<int>> ans;
    queue<vector<int>> q;

    q.push(v);       
    while(q.size()){ 
        vector<int> t=q.front(); q.pop();
        visited[t]=1;
        if(t==result){
            ans.push_back(index[t]);continue;
        }
        for(i=1;i<t.size();i++){
            vector<int> xx;
            for(j=i;j>=0;j--) xx.push_back(t[j]);
            for(j=i+1;j<t.size();j++) xx.push_back(t[j]);
            if(visited[xx]==0){
                q.push(xx),visited[xx]=1;
                index[xx]=index[t];
                index[xx].push_back(i+1);
            }else if(xx==result){
                ans.push_back(index[t]),ans.back().push_back(i+1);
            }
        }
    }        
    for(auto x: ans){
        if(x.size()==0){
            cout << 0 << endl; continue;
        }
        for(auto x: x){
            cout << x << " ";
        }
        cout << endl;
    }    
}
