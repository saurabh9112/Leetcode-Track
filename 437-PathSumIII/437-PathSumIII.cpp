// Last updated: 8/19/2025, 7:22:43 PM
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
    void solve(TreeNode* root, int targetSum, int &ans, long long currSum) {
        if (!root) return;

        currSum += root->val;
        if (currSum == targetSum) ans++;

        solve(root->left, targetSum, ans, currSum);
        solve(root->right, targetSum, ans, currSum);
    }

    void dfs(TreeNode* root, int targetSum, int &ans) {
        if (!root) return;
        solve(root, targetSum, ans, 0); 
        dfs(root->left, targetSum, ans);  
        dfs(root->right, targetSum, ans); 
    }

    int pathSum(TreeNode* root, int targetSum) {
        int ans = 0;
        dfs(root, targetSum, ans);
        return ans;
    }
};
