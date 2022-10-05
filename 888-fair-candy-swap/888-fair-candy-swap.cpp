class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        vector<int> ans;
        int sumA=0,sumB=0;
        for(int i=0;i<aliceSizes.size();i++){
            sumA+=aliceSizes[i];
        }
        for(int i=0;i<bobSizes.size();i++){
            sumB+=bobSizes[i];
        }
        int d=(sumA-sumB)/2;
        unordered_set<int> s;
        for(int i=0;i<bobSizes.size();i++){
            s.insert(bobSizes[i]+d);
        }
        for(int i = 0; i < aliceSizes.size(); i++){
			if(s.find(aliceSizes[i]) != s.end()){    
				ans.push_back(aliceSizes[i]); 
                ans.push_back(aliceSizes[i] - d);
                return ans;
			}
		}
        return ans;
    }
};