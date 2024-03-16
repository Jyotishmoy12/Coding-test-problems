Given two binary trees, explain how you would create a diff such that if you have that diff and either of the trees you should be able to generate the other binary tree. 
Implement a function which takes TreeNode tree1, TreeNode tree2 and returns that diff.

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1 == NULL and root2 == NULL) return NULL;
        if(root2==NULL) return root1;
        if(root1==NULL) return root2;
        root1->val = root1->val - root2->val;
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);
        return root1;
    }
};
