class Node {
public:
    Node* links[26];
    bool isEnd;

    Node() {
        isEnd = false;

        for(int i = 0; i < 26; i++) {
            links[i] = nullptr;
        }
    }
};


class WordDictionary {
private:
    Node* root;

    bool searchHelper(string &word, int index, Node* curr) {

        if(index == word.size()) {
            return curr->isEnd;
        }

        char ch = word[index];

        // Normal character
        if(ch != '.') {

            int i = ch - 'a';

            if(curr->links[i] == nullptr) {
                return false;
            }

            return searchHelper(word, index + 1, curr->links[i]);
        }

        // '.' means any character
        for(int i = 0; i < 26; i++) {

            if(curr->links[i] != nullptr) {

                if(searchHelper(word, index + 1, curr->links[i])) {
                    return true;
                }
            }
        }

        return false;
    }

public:

    WordDictionary() {
        root = new Node();
    }

    void addWord(string word) {

        Node* curr = root;

        for(char ch : word) {

            int index = ch - 'a';

            if(curr->links[index] == nullptr) {
                curr->links[index] = new Node();
            }

            curr = curr->links[index];
        }

        curr->isEnd = true;
    }

    bool search(string word) {
        return searchHelper(word, 0, root);
    }
};