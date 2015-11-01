/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> mystk;
        vector<int> arr;
        //mystk.push(root);
        TreeNode *cur = root;
        while(!mystk.empty() || cur != NULL){
            if(cur != NULL){
                mystk.push(cur);
                cur = cur -> left;
            }else{
                cur = mystk.top();
                mystk.pop();
                arr.push_back(cur -> val);
                cur = cur -> right;
            }
            if(arr.size() >= k ) return arr[k-1];
        }//end while
        return arr[k-1];
    }
};
