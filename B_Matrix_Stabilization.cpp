#include <bits/stdc++.h>
#include<limits.h>
#include<algorithm>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define vll vector<long long>
#define pb push_back
#define nl "\n"
#define sp " "
#define ll long long
#define loop(i, a, b) for (ll i = (a); i < (b); ++i)
#define all(x) (x).rbegin(), (x).rend()
#define num_of_digits(n) ((ll)log10(n) + 1)
#define MAX(x) *max_element(all(x))
#define MIN(x) *min_element(all(x))
#define SUM(x) accumulate(all(x), 0LL)
#define yess cout << "YES" << endl
#define noo cout << "NO" << endl
bool odd(ll num) { return ((num & 1) == 1); }
bool even(ll num) { return ((num & 1) == 0); }
template <typename T> void prn(T x) { cout << x << "\n"; }
template <typename T> void in(T &x) { cin >> x; }
template <typename T> void in(T &x, T &y) { cin >> x >> y; }
template <typename T> void in(T &x, T &y, T &z) { cin >> x >> y >> z; }
template <typename T> void in(vector<T> &v) { for (auto &x : v) cin >> x; }
#define MOD 1000000007
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*


*/



void solve(int t) {
    int n,m; in(n,m);
    int mat[n][m];
    loop(i,0,n) loop(j,0,m) in(mat[i][j]);
    int temp[n][m];
    loop(i,0,n) loop(j,0,m) temp[i][j] = mat[i][j];

    if(n==1 && m==1) {
        cout<<mat[0][0]<<nl;
        return;
    }
    else if(n==1 && m>1) {
        loop(c,0,m){
            if(c==0) {
                if(mat[0][c]>mat[0][c+1]) temp[0][c]=mat[0][c+1];
            }
            else if(c==m-1) {
                if(mat[0][c]>mat[0][c-1]) temp[0][c]=mat[0][c-1];
            }
            else {
                int mx = max(mat[0][c-1], mat[0][c+1]);
                temp[0][c]= min(mat[0][c], mx); // <-- fix here
            }
        }
    }
    else if(m==1 && n>1) {
        loop(r,0,n){
            if(r==0) {
                if(mat[r][0]>mat[r+1][0]) temp[r][0]=mat[r+1][0];
            }
            else if(r==n-1) {
                if(mat[r][0]>mat[r-1][0]) temp[r][0]=mat[r-1][0];
            }
            else {
                int mx = max(mat[r-1][0], mat[r+1][0]);
                temp[r][0]= min(mat[r][0], mx); // <-- fix here
            }
        }
    }
    else {
        loop(r,0,n) loop(c,0,m) {
           if(r==0 && c==0){
            int mx = max(mat[r+1][c],mat[r][c+1]);
            if(mat[r][c]>mx) temp[r][c]=mx;
           }
           else if(r==0 && c==m-1){
            int mx = max(mat[r+1][c],mat[r][c-1]);
            if(mat[r][c]>mx) temp[r][c]=mx;
           }
           else if(r==n-1 && c==0){
            int mx = max(mat[r-1][c],mat[r][c+1]);
            if(mat[r][c]>mx) temp[r][c]=mx;
           }
           else if(r==n-1 && c==m-1){
            int mx = max(mat[r-1][c],mat[r][c-1]);
            if(mat[r][c]>mx) temp[r][c]=mx;
           }
           else if(r==0){
            int mx = max({mat[r][c+1],mat[r+1][c],mat[r][c-1]});
            if(mat[r][c]>mx) temp[r][c]=mx;
           }
           else if(r==n-1){
            int mx = max({mat[r][c+1],mat[r-1][c],mat[r][c-1]});
            if(mat[r][c]>mx) temp[r][c]=mx;
           }
           else if(c==0){
            int mx = max({mat[r][c+1],mat[r-1][c],mat[r+1][c]});
            if(mat[r][c]>mx) temp[r][c]=mx;
           }
           else if(c==m-1){
            int mx = max({mat[r][c-1],mat[r-1][c],mat[r+1][c]});
            if(mat[r][c]>mx) temp[r][c]=mx;
           }
           else {
               int mx = max({mat[r][c-1],mat[r-1][c],mat[r+1][c],mat[r][c+1]});
            if(mat[r][c]>mx) temp[r][c]=mx;
           }
        }
    }

    loop(i,0,n) {
        loop(j,0,m) cout<<temp[i][j]<<sp;
        cout<<nl;
    }
}






















signed main() {
  fastio();

  ll t = 1;
   in(t);
  for(int i = 1; i<=t; i++)
    solve(i);

  return 0;
}
