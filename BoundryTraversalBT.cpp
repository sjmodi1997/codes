#define pb push_back
vector<int> v;
void leftBoundry(TreeNode* root)
{
    if(root==NULL)
        return;
    if(root->left)
    {
        v.pb(root->val);
        leftBoundry(root->left);
    }
    else if(root->right)
    {
        v.pb(root->val);
        leftBoundry(root->right);
    }
    else // skip leaf Nodes
    {
        return;
    }
}

void leafNodes(TreeNode* root)
{
    if(root==NULL)
        return;
    if(root->left==NULL && root->right==NULL)
        v.pb(root->val);
    leafNodes(root->left);
    leafNodes(root->right);
}

void rightBoundry(TreeNode* root)
{
    if(root==NULL)
        return;
    if(root->right)
        rightBoundry(root->right);
    else if(root->left)
        rightBoundry(root->left);
    else // skip leafNodes
        return;
    v.pb(root->val);
}

vector<int> Solution::solve(TreeNode* root) {
    v.clear();
    if(root==NULL)
        return v;
    leftBoundry(root);
    leafNodes(root);
    rightBoundry(root->right);
    return v;
}
