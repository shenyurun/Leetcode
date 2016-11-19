/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <queue>

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> a;
        vector<int> b;
        queue<TreeNode*> q;
        
        if(root == NULL){
            return a;
        }
        
        //int level = 0;
        int num_parent = 1;
        int num_child = 0;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* x = q.front();
            q.pop();
            b.push_back(x->val);

            if(x->left != NULL){
                q.push(x->left);
                num_child++;
            }
            if(x->right != NULL){
                q.push(x->right);
                num_child++;
            }
            
            num_parent--;
            if(num_parent == 0){
                //level++;
                a.push_back(b);
                b.clear();
                num_parent = num_child;
                num_child = 0;
            }
        }
        return a;
    }
};