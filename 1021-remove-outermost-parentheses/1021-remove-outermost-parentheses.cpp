class Solution {
public:
    string removeOuterParentheses(string s) {
        
        stack<char> st;
        string ans;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                if(st.size()>0){
                    ans+='(';
                }
                st.push('(');
            }
            else{
                if(st.size()>1){
                ans+=')';
                }
                st.pop();
                
            }

        }
        return ans;
    }
};