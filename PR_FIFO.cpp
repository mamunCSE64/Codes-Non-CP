#include <bits/stdc++.h>
#include <iostream>
#define fi first
#define se second
#define pb push_back
using namespace std;
// PR_FIFO
int main()
{          
    string s;
    cin>>s;
    vector<int> frame(3,-1);
    int x=0,mis=0,hit=0;
    for(int i=0;i<s.size();i++){
        int v=(s[i]-'0');
        int find=0;
        for(int j=0;j<3;j++){
            if(frame[j]==v){
                find=1;break;
            }
        }
        if(find) hit++;
        else{
            mis++;
            int mt=0,ind;
            for(int j=0;j<3;j++){
                if(frame[j]==-1){
                    mt=1,ind=j;break;
                }
            }
            if(mt) frame[ind]=v;
            else{
                frame[x]=v;
                x=(x+1)%3;
            }
        }
    }
    cout << hit << " " << mis << endl;
}
