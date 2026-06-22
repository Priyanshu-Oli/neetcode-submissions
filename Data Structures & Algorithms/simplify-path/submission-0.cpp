class Solution {
public:
    string simplifyPath(string path) {
        stack<string> file;

        int len = path.size();
        int curr = 0;

        while (curr < len) {
            // skip '/'
            while (curr < len && path[curr] == '/') {
                curr++;
            }

            string filename = "";

            // extract directory name
            while (curr < len && path[curr] != '/') {
                filename += path[curr];
                curr++;
            }

            if (filename == ".." && !file.empty()) {
                file.pop();
            }
            else if ((filename == ".." && file.empty()) || filename == "" || filename == ".") {
                continue;
            }
            else {
                file.push(filename);
            }
        }

        if (file.empty()) {
            return "/";
        }

        string ans = "";

        while (!file.empty()) {
            ans = "/" + file.top() + ans;
            file.pop();
        }

        return ans;
    }
};