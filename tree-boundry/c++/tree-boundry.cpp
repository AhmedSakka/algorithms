    bool isLeaf(TreeNode* node){
        return node->left == nullptr && node->right == nullptr;
    }
    
    void getLeaves(vector<int>& result, TreeNode* node){
        if(isLeaf(node)){
            result.push_back(node->val);
        } else {
            if(node->left != nullptr){
                getLeaves(result, node->left);
            }  
            if(node->right != nullptr){
                getLeaves(result, node->right);
            }
        }
    }
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> result;
        
        TreeNode* node = root->left;
        result.push_back(root->val);
        if(isLeaf(root)) return result;
        
        while(node != nullptr){
            if(!isLeaf(node)){
                result.push_back(node->val);
            }
            if(node->left != nullptr){
                node = node->left;
            } else {
                node = node->right;
            }
        }
        
        getLeaves(result, root);
        
        stack<int> rightBoundry;
        node = root->right;
        while(node != nullptr){
            if(!isLeaf(node)){
                rightBoundry.push(node->val);
            }
            if(node->right != nullptr){
                node = node->right;
            } else {
                node = node->left;
            }
        }
        
        while(!rightBoundry.empty()){
            result.push_back(rightBoundry.top());
            rightBoundry.pop();
        }
        return result;
    }