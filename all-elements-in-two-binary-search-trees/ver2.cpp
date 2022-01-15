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
    vector<int> res;
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2) return res;
        while(root1 && root2){
            while(getNext(root1)){
                // cout << root1->val << endl;
                root1 = root1->left;
            }
                
            while(getNext(root2)){
                // cout << root2->val << endl;
                root2 = root2->left;
            }

            if(root1->val < root2->val){
                // cout << root1->val << endl;
                res.emplace_back(root1->val);
                root1 = root1->right;
            }
            else{
                // cout << root2->val << endl;
                res.emplace_back(root2->val);
                root2 = root2->right;
            }
        }
        while(root1)
        {
            while(getNext(root1))
                root1 = root1->left;
            res.emplace_back(root1->val);
            root1 = root1->right;
        }
        while(root2)
        {
            while(getNext(root2))
                root2 = root2->left;
            res.emplace_back(root2->val);
            root2 = root2->right;
        }
        return res;
    }


    // find the biggest node of left subtree of the input root -> leaf
    // leaf->right = next node to be visited during dfs <- input root
    // becasue the same root will be check twice during dfs
    // so, the leaf will be found twice during the procedure: 
    //      first time: add leaf->right
    //      second time: clear leaf->right, remove left subtree -> finish visiting this node
    TreeNode* getNext(TreeNode* root)
    {
        if(root->left)
        {
            TreeNode* cur = root->left;
            while(cur->right && cur->right != root)
                cur = cur->right;
            if(cur->right == root)
            {
                cur->right = nullptr;
                root->left = nullptr;
                return nullptr;
            }
            else 
                cur->right = root;
            return cur;
        }
        else
            return nullptr;
    }
};
