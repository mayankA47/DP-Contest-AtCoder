//IN THE NAME OF LORD
#include<bits/stdc++.h>
using namespace std;
 
#define ff              first
#define ss              second
#define int              long long 
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define vvi             vector<vector<int>>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             9e18
#define ALL(a)          a.begin(),a.end()
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define from(i,n)       for(int i=0;i<(int)n;i++)
#define from_j(i,j,n)   for(int i=j;i<(int)n;i++)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
 
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
 
int md = 1e9+7;
int mul(int a,int b){
    return ((a*b)%md+md)%md;
} 
int add(int a,int b){
    return ((a+b)%md+md)%md;
} 
void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
int n,k;
vvi matmul(vvi a,vvi b,int d){
    vvi c(d,vi(d,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            //c[i][j]=0;
            for(int k=0;k<n;k++)
               // cout<<"mul "<<a[i][k]<<" and "<<b[j][k]<<endl;
                c[i][j] = add(c[i][j],mul(a[i][k],b[k][j]));
        }
    }
    return c;
}
vvi power(vvi a,int N){
    if(N==1)
        return a;
    vvi b = power(a,N/2);
    vvi c;
    if(N&1)
        c = matmul(matmul(b,b,n),a,n);
    else
        c = matmul(b,b,n);
    return c;

}
int32_t main()
{
    c_p_c();
    cin>>n>>k;
    vvi a(n,vi(n));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>a[i][j];
    
    vvi b = power(a,k);
 //   cout<<b.size()<<endl;
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            ans = add(ans,b[i][j]);
        
    }
    cout<<ans;

 cerr << "proc time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
    return 0;
        
}
