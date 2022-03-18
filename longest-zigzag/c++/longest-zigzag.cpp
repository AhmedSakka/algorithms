    int result = 0;
    static const int RIGHT = 1;
    static const int LEFT = 0;
    
    void maxZigZag(TreeNode* node, int direction,int currentDistance) {
        if(node == nullptr){
            return;  
        }
        
        this->result = max(this->result, currentDistance);
        
        if(direction == RIGHT){
            maxZigZag(node->right, LEFT, currentDistance + 1);
            maxZigZag(node->left, RIGHT, 1);
        } else {
            maxZigZag(node->left, RIGHT, currentDistance + 1);
            maxZigZag(node->right, LEFT, 1);
        }
    }
    
    int longestZigZag(TreeNode* root) {
        maxZigZag(root, RIGHT, 0);
        maxZigZag(root, LEFT, 0);
        
        return this->result;
    }