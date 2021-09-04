class Solution {
public:
    vector<vector<int>> graph;
    vector<int> sol,node_count;
    // calculate node_nums and dist value of child node
    void postorder(int node, int parent_node) {
        node_count[node] = 1; // self node count
        for(int &child_node : graph[node]){
            if(child_node==parent_node) continue;
            postorder(child_node,node);
            node_count[node]+=node_count[child_node];
            sol[node]+=sol[child_node]+node_count[child_node];
        }
    }
    // calculate final dist val while traversiong node using (precalculated dist value of child_node)
    void preorder(int node, int parent_node){
        for(int &child_node : graph[node]){
            if(child_node==parent_node) continue;
            sol[child_node]=sol[node]+graph.size()-2*node_count[child_node];
            preorder(child_node, node);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        //1. init variable
        graph = vector<vector<int>>(n);
        sol = vector<int>(n,0);
        node_count = vector<int>(n,0);
        //2. make graph
        for(vector<int> &edge : edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        //3. postorder (to get dist, node_count of child)
        postorder(0,0);
        //4. preorder (to get final dist value using precalculated dist of child)
        preorder(0,0);
        return sol;
    }
};