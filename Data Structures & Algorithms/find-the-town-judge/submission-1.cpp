class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>incoming(n+1);
        vector<int>outgoing(n+1);
        for(int i=0;i<trust.size();i++){
            int a = trust[i][0];
            int b = trust[i][1];
            incoming[b]++;
            outgoing[a]++;
        }
        for(int i =1; i <=n;i++){
            if(outgoing[i]==0 &&incoming[i]==n-1){
                return i;
            }
        }
        return -1;
    }
};