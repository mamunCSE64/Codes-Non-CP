#include <bits/stdc++.h>
#include <iostream>
#define fi first
#define se second
#define pb push_back
using namespace std;
// PR_Optimal Page Replacement
int main()
{          
    string s;
    cin>>s; 
    int n=s.size();
    vector<int> frame(3,-1);
    int hit=0,mis=0;
    for(int i=0;i<n;i++){
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
                int f0,f1,f2;
                f0=f1=f2=n;
                for(int j=i+1;j<n;j++){
                    if(frame[0]==(s[j]-'0')){
                        if(f0==n) f0=j;
                    }
                    else if(frame[1]==(s[j]-'0')){
                        if(f1==n) f1=j;
                    }
                    else if(frame[2]==(s[j]-'0')){
                        if(f2==n) f2=j;
                    }
                }
                if(f0>=f1 and f0>=f2){
                    frame[0]=v;
                }
                else if(f1>=f0 and f1>=f2){
                    frame[1]=v;
                }
                if(f2>=f1 and f2>=f0){
                    frame[2]=v;
                }
            }
        }
    }
    cout << hit << " " << mis << endl;
}
