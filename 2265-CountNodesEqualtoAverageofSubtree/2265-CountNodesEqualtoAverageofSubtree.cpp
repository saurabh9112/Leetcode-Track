// Last updated: 9/10/2026, 12:23:22 AM
1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
8 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
9 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
10 * };
11 */
12class Solution {
13public:
14    int count = 0;
15    
16    pair<int, int> postOrder(TreeNode* root) {
17        if (root == NULL) {
18            return {0, 0};
19        }
20        
21        // First iterate over left and right subtrees.
22        pair<int, int> left = postOrder(root->left);
23        pair<int, int> right = postOrder(root->right);
24        
25        int nodeSum = left.first + right.first + root->val;
26        int nodeCount = left.second + right.second + 1;
27
28        // Check if the average of the subtree is equal to the node value.
29        if (root->val == nodeSum / (nodeCount)) {
30            count++;
31        }
32        
33        // Return the sum of nodes and the count in the subtree.
34        return {nodeSum, nodeCount};
35    }
36    
37    int averageOfSubtree(TreeNode* root) {
38        postOrder(root);
39        return count;
40    }
41};