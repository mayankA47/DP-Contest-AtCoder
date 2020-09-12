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
 
void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
int dp[101][10001][2];
string K;
int D;
//int mod = 1e9 + 7;
int findans(int sum,int i,bool r){
  if(i==K.length()){
    return sum==0?1:0;
  }
  if(dp[sum][i][r]!=-1)
    return dp[sum][i][r];
  int ans = 0;
  int maxi = r==1?K[i]-'0':9;
  for(int num=0;num<=maxi;num++){
    ans = (ans + findans((sum+num)%D, i+1, r&&(num==maxi)))%mod;
  }
  return dp[sum][i][r] = ans;
}
int32_t main()
{
    c_p_c();                    
    cin>>K>>D;
    for(int i=0;i<=D;i++)
      for(int j=0;j<=K.length();j++)
        dp[i][j][0] = dp[i][j][1] = -1;
    int ans = findans(0,0,1) - 1;
   // cout<<ans<<endl;
    if(ans<0)
      ans += mod;
    cout<<ans;



 cerr << "proc time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
    return 0;
        
}
