#define NO_CHARS 26

struct TrieNode
{
    TrieNode* children[NO_CHARS];
    bool isEnd;
};

struct TrieNode* getNode()
{
    TrieNode* node = new TrieNode;
    node->isEnd = false;
    for(int i=0;i<NO_CHARS;i++)
    {
        node->children[i] = NULL; 
    }
    return node;
}

class Trie {
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = getNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* curr = root;
        for(int i=0;i<word.length();i++)
        {
            if(curr->children[word[i]-'a']==NULL)
                curr->children[word[i]-'a'] = getNode();
            
            curr = curr->children[word[i]-'a'];
        }
        curr->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* curr = root;
        for(int i=0;i<word.length();i++)
        {
            if(curr->children[word[i]-'a']==NULL)
                return false;
            
            curr = curr->children[word[i]-'a'];
        }
        if(curr->isEnd)
            return true;
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for(int i=0;i<prefix.length();i++)
        {
            if(curr->children[prefix[i]-'a']==NULL)
                return false;
            
            curr = curr->children[prefix[i]-'a'];
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
