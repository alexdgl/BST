   void rotateLeft(TreeNode *& root)
    {
        if (!root || (!root -> left && !root -> right) || (!root -> right)) return;
        
        TreeNode * x = root, * y = root -> right, * T1 = x -> left, * T2 = y -> left;
        
        x -> right = T2;
        y -> left = x;
        root = y;
    }
    
    TreeNode * sortedArrayToBST(vector<int>& nums) 
    {
        if (nums.size() < 1) return NULL;
        
        TreeNode * BST = NULL, * tail;
        int size = nums.size();
        
        for (int i = 0; i < nums.size(); ++i)
        {
            if (!BST)
            {
                BST = new TreeNode(nums[i]);
                tail = BST;
            }
            else
            {
                tail -> right = new TreeNode(nums[i]);
                tail = tail -> right;
            }
        }
        
        int height = log2(size) + 1;
        int initialRotates = (size != pow(2, height) - 1) ? size - (pow(2, height - 1) - 1) : 0;
        TreeNode * init = BST;
        
        for (int i = 0; i < initialRotates; i++)
        {
            if (i == 0)
            {
                rotateLeft(BST);
                init = BST;
            }
            else
            {
                rotateLeft(init -> right);
                init = init -> right;
            }
        }
        
        int times = size - initialRotates;
        
        while (times > 1)
        {
            times /= 2;
            
            rotateLeft(BST);
            TreeNode * temp = BST;
            
            for (int j = 0; j < times - 1; j++)
            {
                rotateLeft(temp -> right);
                temp = temp -> right;
            }
            
        }
        
        return BST;
    }