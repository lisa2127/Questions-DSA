// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:

        // Your code goes here
        void solve(vector<vector<int>> m, vector<string> &ans, string p, int i, int j, int n){
        if(i == (n - 1) && j == (n - 1)){
            ans.push_back(p);
            return;
        }
        m[i][j] = 0;
        if(((i + 1) < n) && (m[i + 1][j] == 1))
            solve(m, ans, p + "D", (i + 1), (j), n);
        if((j > 0) && (m[i][j - 1] == 1))
            solve(m, ans, p + "L", (i), (j - 1), n);
            
        if(((j + 1) < n) && (m[i][j + 1] == 1))
            solve(m, ans, p + "R", (i), (j + 1), n);
        if((i > 0) && (m[i - 1][j] == 1))
            solve(m, ans, p + "U", (i - 1), (j), n);
       
        m[i][j] = 1;
            
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector <string> ans;
        if(m[0][0]==0)
           return ans;
        if(m[n-1][n-1]==0)
           return ans;
        solve(m, ans, "", 0, 0, n);
  
        return ans;
    }

};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends