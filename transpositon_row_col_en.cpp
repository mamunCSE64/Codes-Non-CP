#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define gcd __gcd
#define int_string to_string
#define string_int stoi
#define mn(v) *min_element(v.begin(), v.end())
#define mx(v) *max_element(v.begin(), v.end())
#define index_character s.find('character')
#define countxchar count(s.begin(), s.end(), 'x')
#define index_ofX_vector find(v.begin(), v.end(), x) - v.begin()
#define point cout << fixed << setprecision(10)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define n1 cout << "-1" << endl
#define ok cout << "ok" nl
#define sorted is_sorted(v.begin(), v.end())
#define nl << endl
#define sp << " "
#define mp make_pair
#define fi first
#define se second
#define inf LLONG_MAX
#define mod %1000000007
// ordered_set
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;   
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
// bitsize-> ll size=log2(n)+1 (last set bit=size-1;/ /Last bit->__lg(value); )
// first bit-> name._Find_First()
// next bit after x-> name._Find_next()
// freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
// BesidesDuplicateCharacterEraseInString s.erase(unique(s.begin(), s.end()), s.end());
// Upper/lower-> transform(s.begin(), s.end(), s.begin(), ::toupper/tolower);

ll i, j, k, n, m;
ll N = 2e6+5,e=1e9;
double pi=acos(-1);
bool cmp(pair<ll,ll> a,pair<ll,ll> b){
    if(a.fi==b.fi) return (a.se>b.se); return (a.fi>b.fi);}

//
// Don't get stuck on a single approach for long, think of multiple ways
// You will destroy your dream if you stay in your comfort zone
// **********************|| Main Code ||********************************
//
 
//  g++ test.cpp -o a && ./a
//  g++ -o a test.cpp && ./a
//  g++ -o a test.cpp && a.e
 

int main()
{ 
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    // point;
    ll test = 1; 
    // cin >> test;    
    again: 
    while (test--)
    {   
        string p; cin>>p;
        int n; cin>>n;
        vector<ll> v(n+1);
        for(i=1;i<=n;i++){
            int x; cin>>x;
            v[x]=i;
        }
        ll m=p.size();
        ll d=(m+n-1)/n;
        vector<vector<char>> rac(d,vector<char>(n+1));
        int ind=0;
        for(i=0;i<d;i++){
            for(j=1;j<=n;j++){
                if(ind<m) rac[i][j]=p[ind++];
                else rac[i][j]='@';
            }
        }
        for(i=0;i<d;i++){
            for(j=1;j<=n;j++){
                cout << rac[i][j] sp;
            }
            cout nl;
        }
        string encryption;
        cout nl << "encryption : " nl nl;
        for(i=1;i<=n;i++){
            for(j=0;j<d;j++){
                encryption+=rac[j][v[i]];
            }
        }
        cout << encryption nl;
    }
} 










