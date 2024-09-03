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
    for(i=1;i<=n;i++) {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> dis(1, range);
        int random_num = dis(gen);
        v.push_back(random_num);
    }  
    cout << "First array : " << endl;
    for(auto x: v) cout << x << " ";cout << endl << endl;
    vector<int> result=v;
    sort(result.begin(),result.end());        
    map<vector<int>,vector<int>> index;
    map<vector<int>,int> visited;
    vector<vector<int>> ans;
    queue<vector<int>> q;
    q.push(v);       
    while(q.size()){ 
        vector<int> t=q.front(); q.pop();   
        if(t==result){
            visited[result]=1;
            ans.push_back(index[result]);
            continue;
        }
        for(i=1;i<t.size();i++){
            vector<int> xx;
            for(j=i;j>=0;j--) xx.push_back(t[j]);
            for(j=i+1;j<t.size();j++) xx.push_back(t[j]);
            if(visited[xx]==0){
                visited[xx]=1;
                index[xx]=index[t];
                index[xx].push_back(i+1);
                if(xx==result) ans.push_back(index[xx]);
                else q.push(xx);
            }else if(xx==result){
                index[result]=index[t]; index[result].push_back(i+1);
                ans.push_back(index[result]);
            }
        }
    }        
    cout << "Will be sorted after reversing to follow any step -> " << endl;
    for(auto x: ans){
        cout << "Steps : ";
        if(x.size()==0){
            cout << 0 << endl; 
        }else{
            for(auto x: x){
                cout << x << " ";
            }
        }
        cout << endl;
    }    
}
