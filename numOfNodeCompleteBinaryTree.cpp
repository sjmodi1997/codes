Struct TreeNode
{
	Int val;
	Struct TreeNode *right;
	Struct TreeNode *left;
} ;

Bool check(int mid,TreeNode* root)
{
	String path = “”;
	while(mid)
  {
	  if(mid%2==0)
    {
	    Path += “L”;
	  } 
    Else
    {
      path += “R”;
    }
	}
	reverse(path.begin(),path.end());
	TreeNode* curr =  head;
	for(int i=0;i<path.size();i++)
  {
	  if(curr=NULL)
	  {
		  Return false;
    } 
    if(path[i]==”L”)
    {
	    Curr = curr->left;
    }
    Else
    {
	    Curr = curr->right;
    }	
	}
	Return true;
}

Int getHeight(TreeNode* root)
{
	if(root==NULL)
	{
		Return 0;
  }
  Int leftHeight = getHeight(root->left);
  Return leftHeight+1;
}

Int getSize(TreeNode* root)
{
	if(!root)
		Return -1;
	if(root->left==NULL && root->right==NULL)
 		Return 0;
	Int height  = getHeight(root);
	Int low = pow(2,height-1)-1;
	Int high = pow(2,height)-1 ;
	Int mid;
	Int ans = -1;
	while(low<=high)
	{
		Mid = (low+high)/2;
		if(check(root,mid))
		{
			Ans = mid;
			Low = mid+1;
		}
		Else
    {
	    High = mid-1;
    }
  }
  Return ans;
}

Int main()
{
	TreeNode *root //;
	Int size_of_tree = getSize(root);
}
