class Trie {
public:
    struct Node {
        Node* child[26];
        bool isEnd;

        Node() {
            isEnd = false;
            for (int i = 0; i < 26; i++)
                child[i] = nullptr;
        }
    };

    Node* root;

    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* curr = root;

        for (char ch : word) {
            int idx = ch - 'a';

            if (curr->child[idx] == nullptr)
                curr->child[idx] = new Node();

            curr = curr->child[idx];
        }

        curr->isEnd = true;
    }
    
    bool search(string word) {
        Node* curr = root;

        for (char ch : word) {
            int idx = ch - 'a';

            if (curr->child[idx] == nullptr)
                return false;

            curr = curr->child[idx];
        }

        return curr->isEnd;
    }
    
    bool startsWith(string prefix) {
        Node* curr = root;

        for (char ch : prefix) {
            int idx = ch - 'a';

            if (curr->child[idx] == nullptr)
                return false;

            curr = curr->child[idx];
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