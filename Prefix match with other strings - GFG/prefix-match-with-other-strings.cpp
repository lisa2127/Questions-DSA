// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++

class Solution{   
public:
bool match(string str1,string str2,int k){
    if(str1.substr(0,k)==str2.substr(0,k)){
        return true;
    }
    else{
        return false;
    }
}
    int klengthpref(string arr[], int n, int k, string str){    
        
        int count=0;
        for(int i=0;i<n;i++){
            if(match(arr[i],str,k)){
                count++;
            }
        }
        return count;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string arr[n];
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>arr[i];
            
        }
        int k;
        cin>>k;
        string str;
        cin>>str;
        
        Solution ob;
        cout << ob.klengthpref(arr, n, k, str) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends