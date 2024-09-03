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
    for(auto x: v) cout << x << " ";cout << endl << endl;;
    vector<int> result=v;
    sort(result.begin(),result.end());        
    map<vector<int>,vector<int>> path;
    map<vector<int>,int> visited;
    vector<vector<int>> ans;
    stack<vector<int>> s;

    s.push(v);       
    while(s.size()){ 
        vector<int> t=s.top(); s.pop();
        if(t==result){
            visited[result]=1;
            ans.push_back(path[result]);
            continue;
        }
        for(i=1;i<t.size();i++){
            vector<int> tmp;
            for(j=i;j>=0;j--) tmp.push_back(t[j]);
            for(j=i+1;j<t.size();j++) tmp.push_back(t[j]);
            if(visited[tmp]==0){
                visited[tmp]=1;
                path[tmp]=path[t];
                path[tmp].push_back(i+1);
                if(tmp==result) ans.push_back(path[tmp]);
                else s.push(tmp);
            }else if(tmp==result){
                path[result]=path[t]; path[result].push_back(i+1);
                ans.push_back(path[result]);
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
