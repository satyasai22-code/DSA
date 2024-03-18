#include <bits/stdc++.h>

using namespace std;

//ordered_set start
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
  
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
//ordered_set end

void dbg_out() { cerr << endl; }

#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

bool isSafe(vector<vector<char>>& arr, int row, int col){
    if(arr[row][col] == '*') return false;
    for(int i=0;i<8;i++)
        if(arr[row][i] == 'q' or arr[i][col] == 'q') return false;
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--){
        if(arr[i][j] == 'q') return false;
    }
    for (int i = row, j = col; i < 8 && j >= 0; i++, j--){
        if(arr[i][j] == 'q') return false;
    }
    for (int i = row, j = col; i < 8 && j < 8; i++, j++){
        if(arr[i][j] == 'q') return false;
    }
    for (int i = row, j = col; i >=0  && j <8 ; i--, j++){
        if(arr[i][j] == 'q') return false;
    }
    return true;
}



bool helper(vector<vector<char>>& arr, int row, int col, ll& ans){
    if(row == 8) return true;
    for(int j = col;j<8;j++){
        if(isSafe(arr, row, j) ){
            arr[row][j] = 'q';
            if(helper(arr, row + 1, 0, ans)) ans++;
            arr[row][j] = '.';
        }
    }
    return false;
}

void solve() {
    const int numRows = 8;
    const int numCols = 8;
    vector<vector<char>> grid(numRows, vector<char>(numCols));

    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            char c;
            cin >> c;
            grid[i][j] = c;
            // cout<<c;
        }
        // cout<<"\n";
    }
    // return;
    ll ans = 0;
    helper(grid, 0, 0, ans);
    cout<<ans;
    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
        cout<<"\n";
    }
}

