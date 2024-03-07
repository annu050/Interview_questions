class Solution {
public:
    bool solution(int s, vector<int> adj[], vector<bool>& visited1, vector<bool>& visited2) {
        visited1[s] = true;
        visited2[s] = true;
        vector<int> temp = adj[s];
        for (auto x : temp) {
            if (!visited1[x]) {
                if (solution(x, adj, visited1, visited2)) {
                    return true;
                }
            } else if (visited2[x]) {
                return true;
            }
        }
        visited2[s] = false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for (auto p : prerequisites) {
            adj[p[1]].push_back(p[0]);
        }
        vector<bool> visited1(numCourses, false);
        vector<bool> visited2(numCourses, false);
        for (int i = 0; i < numCourses; ++i) {
            if (!visited1[i] && solution(i, adj, visited1, visited2)) {
                return false;
            }
        }
        return true;
    }
};
