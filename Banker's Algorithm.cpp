#include <bits/stdc++.h>
#include <iostream>
#define fi first
#define se second
#define pb push_back
using namespace std;

int main()
{        
    int P,R;
    cin>>P>>R;
    vector<int> iR(R);
    for(int i=0;i<R;i++) cin>>iR[i];
    vector<int> maxN[P],allocR[P],currentR[P],available[P];
    for(int i=0;i<P;i++){
        for(int j=0;j<R;j++){
            int x; cin>>x; 
            maxN[i].pb(x);
        }
    }
    vector<int> r(R);     
    for(int i=0;i<P;i++){
        for(int j=0;j<R;j++){
            int x;cin>>x;
            allocR[i].pb(x);
            r[j]+=x;
        }
    } 
    for(int i=0;i<P;i++){
        for(int j=0;j<R;j++){
            int d=maxN[i][j]-allocR[i][j];
            currentR[i].pb(d);
        }         
    }
    vector<int> nR(R);
    for(int i=0;i<R;i++){
        nR[i]=iR[i]-r[i];
    }     
    int count=0;
    vector<int> done(P,0);  
    cout << "Initial Resource : " << endl;
    for(int i=0;i<R;i++) cout << iR[i] << " "; cout << endl;
    while(count<P){
        bool deadlock=0;
        for(int i=0;i<P;i++){
            if(done[i]==0){
                bool b=1;
                for(int j=0;j<R;j++){
                    if(currentR[i][j]>nR[j]) {
                        b=0;break;
                    }
                }
                if(b){
                    for(int j=0;j<R;j++){
                        nR[j]+=allocR[i][j];
                    }
                    done[i]=1,deadlock=1,count++;
                    cout << "Safe State : P " << i << endl;
                }                 
            }
        }
        if(deadlock==0){ cout << "DeadLock Created " << endl; return 0;}
    }  
    cout << "Ending Resource : " << endl;
    for(int i=0;i<R;i++) cout << nR[i] << " "; cout << endl;
}
