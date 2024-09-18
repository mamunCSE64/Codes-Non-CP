#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int CheckConflict(const vector<int>& queens){
    int confilct = 0;
    for(int i = 0; i < 8; i++){
        for (int j = i + 1; j < 8; j++){
            if(queens[i]==queens[j] or abs(queens[i]-queens[j])==j-i){
                confilct++;
            }
        }
    }
    return confilct;
} 

int main() {
    srand(time(0));

    double hitemp,factor;
    cin>>hitemp>>factor;
    vector<int> queens(8),ans;  
    for (int i = 0; i < 8; i++) {
        queens[i] = rand() % 8;
    }        
    int initialConflict = CheckConflict(queens);

    while (initialConflict and hitemp > 0) {
        int queen = rand() % 8;
        int newColumn = rand() % 8;
        int oldColumn = queens[queen];
        queens[queen] = newColumn;
        int newconfilct = CheckConflict(queens);
        if (newconfilct < initialConflict or exp((initialConflict - newconfilct)/hitemp) > ((double)rand() / RAND_MAX)) {
            initialConflict = newconfilct;
        } else {
            queens[queen] = oldColumn;
        }
        hitemp*=factor;
    }
    if (initialConflict == 0) {
        cout << "Solution found : " << endl;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (queens[i] == j) {
                    cout << " Q ";
                    ans.push_back(j+1);
                }else cout << " . ";
            }
            cout << endl;
        }
    }else{
        cout << "Not found any route with confliction zero " << endl;
    }

    for(auto x: ans){
        cout << x << " ";
    }
}
