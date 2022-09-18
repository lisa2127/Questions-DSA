class Solution {
public:
    struct node{
        node* children[26]={NULL};
        int count=0;
    };
    node* root=new node();
    void insert(string s){
        node* curr=root;
        for(int i=0;i<s.size();i++){
            int index=s[i]-'a';
            if(curr->children[index]==NULL){
                curr->children[index]=new node();
            }
            curr=curr->children[index];
            curr->count++;
        }
    }
    int find(node* curr,string &s){
        int ans=0;
        for(auto &ch:s){
            if(curr->children[ch-'a']!=NULL){
                curr=curr->children[ch-'a'];
                ans+=curr->count;
            }
        }
        return ans;
    }
    vector<int> sumPrefixScores(vector<string>& words) {
        //TLE
        /*unordered_map<string,int> mp;
        for(int i=0;i<words.size();i++){
            string temp=words[i];
            string comb="";
            for(int j=0;j<words[i].size();j++){
                comb+=words[i][j];
                mp[comb]++;
            }
        }
        vector<int> ans;
        for(int i=0;i<words.size();i++){
            int cnt=0;
            string comb="";
            for(int j=0;j<words[i].size();j++){
                comb+=words[i][j];
                cnt+=mp[comb];
            }
            ans.push_back(cnt);
        }
        return ans;*/
        for(int i=0;i<words.size();i++){
            insert(words[i]);
        }
        vector<int> ans;
        for(int i=0;i<words.size();i++){
            node* curr=root;
            int value=find(curr,words[i]);
            ans.push_back(value);
        }
        return ans;
    }
};