class Solution {
public:
    
    static bool comp(vector<int> &a,vector<int> &b){
        if(a[0]==b[0]){
            return a[1]>b[1];
        }
        return a[0]<b[0];
    }
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int n=properties.size();
        int cnt=0;
        int maxi=INT_MIN;
        sort(properties.begin(),properties.end(),comp);
         for(int i=n-1;i>=0;i--){
             if(properties[i][1]<maxi){
                 cnt++;
             }
             maxi=max(maxi,properties[i][1]);
         
         }
        return cnt;
    }
    //TLE
    /*int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int cnt=0;
        int n=properties.size();
        sort(properties.begin(),properties.end());
        
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(properties[i][1]<properties[j][1] && properties[i][0]!=properties[j][0]){
                    cnt++;
                    break;
                }
            }
        }
        return cnt;*/

};