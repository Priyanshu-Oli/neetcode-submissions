class Solution {
public:
    vector<vector<string>> partition(string s) {
          vector<vector<string>>res;
          vector<string>tempSub;

          func(0,s,tempSub, res);

          return res;
    }
    void func(int index , string s, vector<string>&tempSub, vector<vector<string>>&res){
        if(index == s.size()){
            res.push_back(tempSub);
            return;
        }

        for(int i = index; i<s.size();i++){
            if(isPalin(s,index,i)){
                tempSub.push_back(s.substr(index, i-index+1));

                func(i+1, s,tempSub,res);

                tempSub.pop_back();
            }
        }
    }


    bool isPalin(string s, int start, int end){
        while(start<=end){
            if(s[start++]!=s[end--]){
                return false;
            }
        }
        return true;
    }
};