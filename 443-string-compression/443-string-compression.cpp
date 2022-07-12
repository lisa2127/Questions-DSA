class Solution {
public:
    int compress(vector<char>& chars) {
        int index=0;
        int i=0;
        while(i<chars.size()){
            int j=i;
            while(j<chars.size() && chars[i]==chars[j]){
                j++;
            }
            chars[index++]=chars[i];
            if(j-i>1){
                string c=to_string(j-i);
                for(int i=0;i<c.length();i++){
                    chars[index++]=c[i];
                }
            }
            i=j;
        }
        return index;
    }
};
 