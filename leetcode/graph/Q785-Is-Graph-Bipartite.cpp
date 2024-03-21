class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n, 0);

        for (int start = 0; start < n; start++) {
            if (colors[start] != 0) continue;

            queue<int> q;
            q.push(start);
            colors[start] = 1;

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (int neighbor : graph[node]) {
                    if (colors[neighbor] == 0) {
                        colors[neighbor] = -colors[node];
                        q.push(neighbor);
                    }
                    else if (colors[neighbor] == colors[node])
                        return false;
                }

            }


        }

        return true;
    }
};