// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {  
       int currsum=0;
       int ans=0;
       int maxans=0;
       map<int,int> mp;
       mp[0]=-1;
       for(int i=0;i<n;i++){
           currsum+=A[i];
           if(mp.find(currsum)!=mp.end()){
               ans+=i-mp[currsum];
               maxans=max(ans,maxans);
               ans=0;
           }else{
           mp[currsum]=i;
           }
       }
       
       if(maxans){
           return maxans;
       }
       return 0;
   
        // Your code here
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}


  // } Driver Code Ends