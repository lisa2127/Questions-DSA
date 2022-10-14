/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m,vector<int>(n,-1));
        int x=0,y=0;
        int topRow=-1,bottomRow=m,leftCol=-1,rightCol=n;
        int right=true,down=false,left=false;
        while(head){
            ans[x][y]=head->val;
            head=head->next;
            if(right){
                if(y+1==rightCol){
                    right=false;
                    down=true;
                    topRow++;
                    x++;
                }
                else{
                    y++;
                }
            }
            else if(down){
                if(x+1==bottomRow){
                    down=false;
                    left=true;
                    rightCol--;
                    y--;
                }
                else{
                    x++;
                }
            }
            else if(left){
                if(y-1==leftCol){
                    left=false;
                    bottomRow--;
                    x--;
                }
                else{
                    y--;
                }
            }
            else{
               if(x-1==topRow){
                    leftCol++;
                    right=true;
                    y++;
                }
                else{
                    x--;
                } 
            }
        }
        return ans;
    }
};