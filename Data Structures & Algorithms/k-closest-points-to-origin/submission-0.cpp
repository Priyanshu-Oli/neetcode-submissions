class Solution {
public:
    int distance(int x, int y) {
        return x * x + y * y;
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>> heap;
        for (int i = 0; i < points.size(); i++) {
            int dist = distance(points[i][0], points[i][1]);
            if (heap.size() < k) {
                heap.push({dist, i});
            } else if (dist < heap.top().first) {
                heap.pop();
                heap.push({dist, i});
            }
        }
        vector<vector<int>> ans;
        while (!heap.empty()) {
            ans.push_back(points[heap.top().second]);
            heap.pop();
        }
        return ans;
    }
};