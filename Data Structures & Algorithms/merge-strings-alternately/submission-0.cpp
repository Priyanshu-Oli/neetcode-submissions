class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int p1=0;
        int p2=0;
        string word;

        while(p1<word1.size()&&p2<word2.size()){
            word.push_back(word1[p1]);
            word.push_back(word2[p2]);
            p1++;
            p2++;
        }
        while(p1<word1.size()){
            word.push_back(word1[p1]);
            p1++;
        }
        while(p2<word2.size()){
            word.push_back(word2[p2]);
            p2++;
        }
        return word;
    }
};