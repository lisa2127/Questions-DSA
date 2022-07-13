class Solution {
public:
    bool search(vector<int>& A, int target) {
        int l=0;
        int h=A.size()-1;
        int key=target;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(A[mid]==key){
                return true;
            }
            if(A[l]==A[mid] && A[mid]==A[h]){
                l++;
                h--;
            }
            else if(A[l]<=A[mid]){
                if(A[l]<=key && key<=A[mid]){
                    h=mid-1;
                }
                else{
                    l=mid+1;
                }
            }
            else{
                if(A[mid]<=key && key<=A[h]){
                    l=mid+1;
                }
                else{
                    h=mid-1;
                }
            }
        }
        return false;
    }
};