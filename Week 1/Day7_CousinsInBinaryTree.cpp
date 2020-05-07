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
    int find(TreeNode* rootp, TreeNode* root, TreeNode** parent, int d, int x) {
        if(!root) {
            return 0;
        }
        if(root->val == x) {
            *parent = rootp;
            return d;
        }
        return max(find(root, root->left, parent, d+1, x), find(root, root->right, parent, d+1, x));
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        TreeNode** parent = new TreeNode*[2];
        parent[0] = parent[1] = NULL;
        int d1 = 0, d2 = 0;
        d1 = find(NULL, root, &parent[0], 0, x);
        d2 = find(NULL, root, &parent[1], 0, y);
        if(d1 == d2 && parent[0] != parent[1]) {
            return 1;
        }
        return 0;
    }
};