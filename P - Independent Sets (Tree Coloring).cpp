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
int add(int a,int b){
    return ((a*b)%md+md)%md;
} 
int mul(int a,int b){
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
vi g[100005];
int dp[100005][2];
int n;
int color(int src,int par,int c){
    if(dp[src][c]!=-1)
        return dp[src][c];
    dp[src][c]=1;
    for(int i:g[src]){
        if(i==par)
            continue;
        if(c==1)
            dp[src][c] = add(dp[src][c],color(i,src,0));
        else
            dp[src][c] = add(dp[src][c],mul(color(i,src,1),color(i,src,0)));
    }
    
    return dp[src][c];
}
int32_t main()
{
    c_p_c();
    cin>>n;

    for(int i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
       
    }
    for(int i=0;i<=n;i++)
        dp[i][0]=dp[i][1]=-1;
    int start=1;
    cout<<mul(color(start,0,0),color(start,0,1));
    

 cerr << "proc time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
    return 0;
        
}
