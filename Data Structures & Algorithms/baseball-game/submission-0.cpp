class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> scores;
        int sum = 0;

        for (string op : operations) {

            if (op == "+") {
                int val = scores[scores.size() - 1] +
                          scores[scores.size() - 2];

                scores.push_back(val);
                sum += val;
            }
            else if (op == "D") {
                int val = 2 * scores.back();

                scores.push_back(val);
                sum += val;
            }
            else if (op == "C") {
                sum -= scores.back();
                scores.pop_back();
            }
            else {
                int val = stoi(op);

                scores.push_back(val);
                sum += val;
            }
        }

        return sum;
    }
};