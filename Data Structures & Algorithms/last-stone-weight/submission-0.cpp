class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxh;

        for (auto stone : stones) {
            maxh.push(stone);
        }
        while (maxh.size() > 1) {
            int first = maxh.top();
            maxh.pop();
            int second = maxh.top();
            maxh.pop();
            if (first != second) {
                maxh.push(first - second);
            }
        }
        return maxh.empty() ? 0 : maxh.top();
    }
};