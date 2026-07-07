class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        unordered_map<char, int> count;

        // Count frequency of each task
        for (char task : tasks)
            count[task]++;

        // Max Heap
        priority_queue<int> maxHeap;

        for (auto it : count)
            maxHeap.push(it.second);

        int time = 0;

        // {remainingCount, availableTime}
        queue<pair<int, int>> q;

        while (!maxHeap.empty() || !q.empty()) {

            time++;

            // Execute the task with maximum frequency
            if (!maxHeap.empty()) {

                int cnt = maxHeap.top();
                maxHeap.pop();

                cnt--;

                // Still remaining, put into cooldown queue
                if (cnt > 0) {
                    q.push({cnt, time + n});
                }
            }

            // Cooldown finished
            if (!q.empty() && q.front().second == time) {
                maxHeap.push(q.front().first);
                q.pop();
            }
        }

        return time;
    }
};