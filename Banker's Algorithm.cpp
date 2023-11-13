#include <bits/stdc++.h>
#include <iostream>
#define fi first
#define se second
#define pb push_back
using namespace std;
// Banker's Algorithm
int main()
{        
    int P,R;
    cin>>P>>R;
    vector<int> iR(R);
    for(int i=0;i<R;i++) cin>>iR[i];
    vector<int> maxN[P],allocR[P],currentRneed[P];
    for(int i=0;i<P;i++){
        for(int j=0;j<R;j++){
            int x; cin>>x; // max need
            maxN[i].pb(x);
        }
    }
    vector<int> rsum(R);     
    for(int i=0;i<P;i++){
        for(int j=0;j<R;j++){
            int x;cin>>x;
            allocR[i].pb(x); // allocated 
            rsum[j]+=x; // total allcated of j'th
        }
    } 
    for(int i=0;i<P;i++){
        for(int j=0;j<R;j++){
            int d=maxN[i][j]-allocR[i][j];
            currentRneed[i].pb(d);
        }         
    }
    vector<int> availableR(R);
    for(int i=0;i<R;i++){
        availableR[i]=iR[i]-rsum[i];
    }     
    int count=0;
    vector<int> done(P);  
    cout << "Initial Resource : " << endl;
    for(int i=0;i<R;i++) cout << iR[i] << " "; cout << endl;
    
    while(count<P){
        bool deadlock=1;
        for(int i=0;i<P;i++){
            if(done[i]==0){
                bool b=1;
                for(int j=0;j<R;j++){
                    if(currentRneed[i][j]>availableR[j]) {
                        b=0;break;
                    }
                }
                if(b){
                    for(int j=0;j<R;j++){
                        availableR[j]+=allocR[i][j];
                    }
                    done[i]=1,deadlock=0,count++;
                    cout << "Safe State : P" << i << endl;
                }                 
            }
        }
        if(deadlock==1){ cout << "DeadLock can be Created " << endl; return 0;}
    }  
    cout << "Ending Resource : " << endl;
    for(int i=0;i<R;i++) cout << availableR[i] << " "; cout << endl;
}
