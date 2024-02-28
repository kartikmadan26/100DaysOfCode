// Question
// 513. Find Bottom Left Tree Value
// Given the root of a binary tree, return the leftmost value in the last row of the tree.

// Example 1:
// Input: root = [2,1,3]
// Output: 1

// Example 2:
// Input: root = [1,2,3,4,null,5,6,null,null,7]
// Output: 7
 
// Constraints:
// The number of nodes in the tree is in the range [1, 104].
// -231 <= Node.val <= 231 - 1
// Solution
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            root=q.front(); // get the value before pop coz pop will not return anyy val
            q.pop();
            if (root->right) {
                q.push(root->right);
            }
            if(root->left) q.push(root->left);
        }
        return root->val;
        
    }
};
