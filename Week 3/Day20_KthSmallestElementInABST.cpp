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
    void rec(TreeNode* root, int& i, int& k) {
        if(!root) {
            return;
        }
        rec(root->left, i, k);
        i++;
        if(i == k) {
            k = root->val;
            return;
        }
        rec(root->right, i, k);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        int c = 0;
        rec(root, c, k);
        return k;
    }
};