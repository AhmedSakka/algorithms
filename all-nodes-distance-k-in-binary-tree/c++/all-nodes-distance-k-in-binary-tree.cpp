    void dfs(map<TreeNode*, TreeNode*>& parentsMap, TreeNode* node, TreeNode* parent){
        if(node != nullptr){
            parentsMap[node] = parent;
            dfs(parentsMap, node->left, node);
            dfs(parentsMap, node->right, node);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> result;
        map<TreeNode*, TreeNode*> parentsMap;
        map<TreeNode*, bool> seenMap;
        dfs(parentsMap, root, nullptr);
        
        queue<TreeNode*> bfsQueue;
        
        bfsQueue.push(nullptr);
        bfsQueue.push(target);
        seenMap[target] = true;
        
        int distance = 0; 
        
        while(!bfsQueue.empty()){
            TreeNode* currentNode = bfsQueue.front();
            bfsQueue.pop();
            if(currentNode == nullptr){
                if(distance == k){
                    while(!bfsQueue.empty()){
                        result.push_back(bfsQueue.front()->val);
                        bfsQueue.pop();
                    }
                    return result;
                }
                bfsQueue.push(nullptr);
                distance++;
            } else {
                if(currentNode->left != nullptr && !seenMap[currentNode->left]){
                    seenMap[currentNode->left] = true;
                    bfsQueue.push(currentNode->left);
                }
                if(currentNode->right != nullptr && !seenMap[currentNode->right]){
                    seenMap[currentNode->right] = true;
                    bfsQueue.push(currentNode->right);
                }
                if(parentsMap[currentNode] != nullptr && !seenMap[parentsMap[currentNode]]){
                    seenMap[parentsMap[currentNode]] = true;
                    bfsQueue.push(parentsMap[currentNode]);
                }
            }
        }
        
        return {};
    }