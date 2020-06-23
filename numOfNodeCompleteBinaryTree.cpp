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
    bool check(TreeNode* root,int mid)
    {
        int temp = mid;
        string path = "";
        while(mid!=1)
        {
          if(mid%2==0)
          {
            path += "L";
          } 
          else
          {
            path += "R";
          }
          mid = mid/2;
        }
        reverse(path.begin(),path.end());
        //cout << temp << " " << path << endl;
        TreeNode* curr =  root;
        for(int i=0;i<path.size();i++)
        {
          if(path[i]=='L')
          {
            curr = curr->left;
          }
          else
          {
            curr = curr->right;
          }
          if(curr==NULL)
          {
              return false;
          } 
        }
        return true;
    }

    int getHeight(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        int leftHeight = getHeight(root->left);
        return leftHeight+1;
    }

    int countNodes(TreeNode* root)
    {
        if(!root)
            return 0;
        if(root->left==NULL && root->right==NULL)
            return 1;
        int height  = getHeight(root);
        int low = pow(2,height-1);
        int high = pow(2,height)-1 ;
        
        int mid;
        int ans = -1;
        while(low<=high)
        {
            mid = (low+high)/2;
            if(check(root,mid))
            {
                ans = mid;
                low = mid+1;
            }
            else
            {
                high = mid-1;
            }
        }
        return ans;
    }
};
