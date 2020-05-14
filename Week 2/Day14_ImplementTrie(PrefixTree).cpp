class TrieNode {
    public: 
    bool eow;
    TrieNode* a[26];
    TrieNode() {
        for(int i=0;i<26;i++) {
            a[i] = NULL;
        }
        eow = false;
    }
};

class Trie {
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* node = root, *newNode;
        for(int i=0;i<word.size();i++) {
            int x = word[i]-'a';
            if(node->a[x] == NULL) {
                newNode = new TrieNode();
                node->a[x] = newNode;
            }
            node = node->a[x];
        }
        node->eow = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* node = root;
        for(int i=0;i<word.size();i++) {
            int x = word[i]-'a';
            if(node->a[x] == NULL) {
                return false;
            }
            node = node->a[x];
        }
        return node->eow ? true : false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for(int i=0;i<prefix.size();i++) {
            int x = prefix[i]-'a';
            if(node->a[x] == NULL) {
                return false;
            }
            node = node->a[x];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */