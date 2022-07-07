// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int findSwapValues(int A[], int n, int B[], int m)
	{
	    int sum1=0;
	    int sum2=0;
	    for(int i=0;i<n;i++){
	        sum1+=A[i];
	    }
	    for(int i=0;i<m;i++){
	        sum2+=B[i];
	    }
        // Your code goes here
	int diff=abs(sum1-sum2);
	if(diff%2==1){
	    return -1;
	}
	if(sum2>sum1){
	    swap(A,B);
	    swap(n,m);
	}
	unordered_map<int,bool> mp;
	for(int i=0;i<n;i++){
	    mp[A[i]]=true;
	}
	for(int j=0;j<m;j++){
	    if(mp[B[j]+diff/2]){
	        return 1;
	    }
	}
	return -1;
	}

};

// { Driver Code Starts.

int main() 
{
   	
   	int t;
    cin >> t;
    while (t--)
    {
    	int n,m;
        cin>>n>>m;
        int a[n];
        int b[m];
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<m;i++)
            cin>>b[i];
        

        Solution ob;
        cout <<  ob.findSwapValues(a, n, b, m);
	    cout << "\n";
	     
    }
    return 0;
}





  // } Driver Code Ends