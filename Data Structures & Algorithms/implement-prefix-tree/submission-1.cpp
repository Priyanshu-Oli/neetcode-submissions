class PrefixTree {
private:
    struct Node {
        Node* children[26];
        bool end;

        Node() {
            end = false;
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    };

    Node* root;

public:
    PrefixTree() {
        root = new Node();
    }

    void insert(string word) {
        Node* curr = root;

        for (char ch : word) {
            int idx = ch - 'a';

            if (curr->children[idx] == nullptr) {
                curr->children[idx] = new Node();
            }

            curr = curr->children[idx];
        }

        curr->end = true;
    }

    bool search(string word) {
        Node* curr = root;

        for (char ch : word) {
            int idx = ch - 'a';

            if (curr->children[idx] == nullptr) {
                return false;
            }

            curr = curr->children[idx];
        }

        return curr->end;
    }

    bool startsWith(string prefix) {
        Node* curr = root;

        for (char ch : prefix) {
            int idx = ch - 'a';

            if (curr->children[idx] == nullptr) {
                return false;
            }

            curr = curr->children[idx];
        }

        return true;
    }
};