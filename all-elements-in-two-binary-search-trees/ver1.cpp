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
    vector<int> list1;
    vector<int> list2;
    void dfs(vector<int>& list, TreeNode* node){
        if (node->left != NULL) dfs(list, node->left);
        list.push_back(node->val);
        if (node->right != NULL) dfs(list, node->right);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        if (root1 != NULL) dfs(list1, root1);
        if (root2 != NULL) dfs(list2, root2);
        vector<int> result;
        int size1 = list1.size();
        int size2 = list2.size();
        for (int i = 0, j = 0; ;){
            if (i >= size1 && j >= size2) break;
            if (i >= size1) result.push_back(list2[j++]);
            else if (j >= size2) result.push_back(list1[i++]);
            else {
                if (list1[i] < list2[j]) result.push_back(list1[i++]);
                else result.push_back(list2[j++]);
            } 
        }
        return result;
    }
};
