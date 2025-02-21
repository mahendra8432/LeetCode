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
class FindElements {
public:
TreeNode*root;
void func(TreeNode*node){
    if(node==NULL){
        return;
    }
    if(node->left!=NULL){
        node->left->val=2*node->val+1;
        func(node->left);
    }
    if(node->right!=NULL){
        node->right->val=2*node->val+2;
        func(node->right);
    }
}
bool funct(TreeNode*node,int target){
    if(node==NULL){
        return false;
    }
    if(node->val==target){
        return true;
    }
    bool lh=funct(node->left,target);
    bool rh=funct(node->right,target);
    return lh ||rh;
}
    FindElements(TreeNode* root) {
        this->root=root;
        this->root->val=0;
        func(root);
    }
    bool find(int target) {
        return funct(root,target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */