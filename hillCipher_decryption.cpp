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
        string c,k;
        cin>>c>>k;
        ll n=sqrt(k.size());
        ll m=(c.size())/n;
        vector<vector<ll>> vc(m,vector<ll> (n)),vk(n,vector<ll> (n));
        ll index=0;
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                vk[i][j]=k[index]-'a';
                index++;
            }
        }
        index=0;
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                vc[i][j]=c[index]-'a';
                index++;
            }
        }
        if(n==2){
            ll d=(vk[0][0]*vk[1][1]-vk[0][1]*vk[1][0]);
            d%=26;
            if(d<0) d+=26;
            for(i=1;;i++){
                if((d*i)%26==1){
                    d=i;break;
                }
            }
            swap(vk[0][0],vk[1][1]);
            vk[1][0]=-vk[1][0];
            vk[0][1]=-vk[0][1];
            for(i=0;i<n;i++){
                for(j=0;j<n;j++){
                    vk[i][j]*=d;
                    vk[i][j]%=26;
                }
            }
        }else{
            ll d=vk[0][0]*(vk[1][1]*vk[2][2]-vk[2][1]*vk[1][2])-
            vk[0][1]*(vk[1][0]*vk[2][2]-vk[2][0]*vk[1][2])+
            vk[0][2]*(vk[1][0]*vk[2][1]-vk[2][0]*vk[1][1]);
            d%=26;
            if(d<0) d+=26;
            for(i=1;;i++){
                if((d*i)%26==1){
                    d=i;break;
                }
            }
            vk[0][0]=vk[1][1]*vk[2][2]-vk[2][1]*vk[1][2];
            vk[0][1]=-vk[1][0]*vk[2][2]-vk[2][0]*vk[1][2];
            vk[0][2]=vk[1][0]*vk[2][1]-vk[2][0]*vk[1][1];
            vk[1][0]=-vk[0][1]*vk[2][2]-vk[2][1]*vk[0][2];
            vk[1][1]=-vk[0][0]*vk[2][2]-vk[0][2]*vk[2][0];
            vk[1][2]=vk[0][0]*vk[2][1]-vk[0][1]*vk[2][0];
            vk[2][0]=-vk[0][1]*vk[1][2]-vk[0][2]*vk[1][1];
            vk[2][1]=vk[0][0]*vk[1][2]-vk[0][2]*vk[1][0];
            vk[2][2]=-vk[0][0]*vk[1][1]-vk[0][1]*vk[1][0];
            for(i=0;i<n;i++){
                for(j=0;j<n;j++){
                    vk[i][j]%=26;
                    if(vk[i][j]<0) vk[i][j]+=26;
                    vk[i][j]*=d;
                    vk[i][j]%=26;
                }
            }
            swap(vk[0][1],vk[1][0]);
            swap(vk[2][0],vk[0][2]);
            swap(vk[2][1],vk[1][2]);
        }
        string decryption;
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                ll sum=0;
                for(ll ind=0;ind<n;ind++){
                    sum+=vk[j][ind]*vc[i][ind]; //p=(k^-1)*c
                }
                sum%=26;
                decryption+=(sum+'a');
            }
        }
        cout << decryption nl;
    }
} 










