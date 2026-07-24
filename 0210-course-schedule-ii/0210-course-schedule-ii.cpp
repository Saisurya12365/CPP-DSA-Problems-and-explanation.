class Solution {
public:
    int n;
    void topoBFS(vector<int> &ans, vector<vector<int>> &adj){
        vector<int> indegree(n,0);
        for(int i=0; i<n; i++){
            for(auto neigh : adj[i]) indegree[neigh]++;
        }

        queue<int> q;
        unordered_set<int> vis;
        for(int i=0; i<n; i++){
            if(indegree[i] == 0){
                q.push(i);
                vis.insert(i);
            }
        }

        while(q.size()){
            int node = q.front(); q.pop();
            ans.push_back(node);

            for(auto neigh : adj[node]){
                if(!vis.count(neigh)){
                    indegree[neigh]--;
                    if(indegree[neigh] == 0){
                        q.push(neigh);
                        vis.insert(neigh);
                    }
                }
            }
        }
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        n = numCourses;

        vector<vector<int>> adj(n);
        for(auto v : prerequisites){
            adj[v[1]].push_back(v[0]);
        }

        vector<int> ans;
        topoBFS(ans, adj);
        if(ans.size() == n) return ans;
        return {};
    }
};