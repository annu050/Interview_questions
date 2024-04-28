class Solution {
public:
    long root_res = 0;
    int N;
    vector<int> count;
//parent ka ans mein se child ka nikaalne mein kya kya changes honge use observe kro
    //then chidl ans=parent-childanditsnodes+leftoutnodes;
    int dfs(unordered_map<int,vector<int>> &graph, int curr, int prev, int curr_doorie) {
        int total = 1; // as including child itself
        root_res += curr_doorie;
        for (auto &child : graph[curr]) {
            if (child == prev) continue;
            total += dfs(graph, child, curr, curr_doorie + 1);
        }
        count[curr] = total;
        return total;
    }

    void dfs(unordered_map<int,vector<int>> &graph, int parent, int prev, vector<int> &res) {
        for (auto &child : graph[parent]) {
            if (child == prev) continue;
            res[child] = res[parent] - count[child] + (N - count[child]);
            dfs(graph, child, parent, res);
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> graph;
        // so we need parent nodes sum of distances and count of subtree nodes including child defined above
        N = n;
        count.resize(n, 0);
        for (auto e : edges) {
            int u = e[0];
            int v = e[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        dfs(graph, 0, -1, 0); // count of root node and also -1 for prev node i.e parent pe waapas na aaye while calling
        vector<int> res(n, 0);
        res[0] = root_res;
        dfs(graph, 0, -1, res); // baaki nodes ka result add 
        return res;
    }
};