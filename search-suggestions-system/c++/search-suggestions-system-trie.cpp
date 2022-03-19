class TrieNode{
public:
    map<char, TrieNode*> children;
    bool isWord;
    TrieNode(){
        this->isWord = false;
    }
};
class Trie {
private:
    TrieNode* rootNode;
    
    void dfsWithPrefix(TrieNode* node, string& word, vector<string>& results){
        if(results.size()==3) return;
        if(node->isWord){
            results.push_back(word);
        }
        
        for(char c = 'a'; c <= 'z'; c++){
            if(node->children[c]){
                word += c;
                dfsWithPrefix(node->children[c], word, results);
                word.pop_back();
            }
        }
    }
    
public:
    Trie(){
        rootNode = new TrieNode();
    }
    
    void insert(string& word){
        TrieNode* currentNode = rootNode;
        for(char& c : word){
            if(!currentNode->children[c]){
                currentNode->children[c] = new TrieNode();
            }
            currentNode = currentNode->children[c];
        }
        currentNode->isWord = true;
    }
    
    vector<string> searchWithPrefix(string& prefix){
        TrieNode* currentNode = rootNode;
        vector<string> result;
        
        for(char& c : prefix){
            if(!currentNode->children[c]) return result;
            currentNode = currentNode->children[c];
        }
        dfsWithPrefix(currentNode, prefix, result);
        return result;
    }
    
};

vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
    vector<vector<string>> result;
    string prefix="";
    Trie* trie = new Trie();
    for(string& product: products){
        trie->insert(product);
    }
    for(char& c : searchWord){
        prefix += c;
        result.push_back(trie->searchWithPrefix(prefix));
    }
                               
    return result;
}