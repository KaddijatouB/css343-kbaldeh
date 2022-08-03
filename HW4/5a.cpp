// 1584. Min Cost to Connect All Points
// Union find

//Create a class for Union find
class UF{
public:
    //Arrays to store root and position of each node.
    vector<int>parent;
    vector<int>size;
    // Declaration of class methods.
    UF(int ArraySize);
    int Find(int key);
    bool Union(int p, int q);
};

//implementation of union find  class methods.
//UF constructor that takes in size of array.
UF::UF(int ArraySize){
    //initialize each array to size
    parent = vector<int>(ArraySize);
    size = vector<int>(ArraySize);
    for (int i = 0; i < ArraySize; ++i) {
        parent[i] = i;
    }
}
// Find method function to find the union of node.
int UF::Find(int key){
    //look for the root
    if (parent[key] != key) {
        parent[key] = Find(parent[key]);
    }
    //return root
    return parent[key];
}
// Union method function to merge nodes as union.
bool UF::Union(int p, int q){
    //search for nodes
    int rootP = Find(p);
    int rootQ = Find(q);
    // if both nodes are equal, return false.
    if(rootP == rootQ){
        return false;
    }
    else if(size[rootP] > size[rootQ]){
        parent[rootQ]= rootP;
    }else{
        parent[rootP]= rootQ;
    }
    return true;
}
// minCostConnectPoints
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int num = points.size();
        int minCost = 0;
        int count = 0;
        //pair array
        vector<pair<int, pair<int, int>>> edges;
        // loop to create an edge to all other coordinate points.
        for(int i = 0; i < num; ++i){
            for (int j = i + 1; j < num; ++j){
                // compute weight
                int weight = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                // add edges weight to array
                edges.push_back({ weight, { i, j }});
            }
        }
        // sort edges
        sort(edges.begin(), edges.end());
        // call union find for points size
        UF uf(num);
        // loop through edges
        for (int i = 0; i < edges.size() && count < num - 1; ++i) {
            int first = edges[i].second.first;
            int second = edges[i].second.second;
            int weight = edges[i].first;
            // merge the pair of edges
            if (uf.Union(first, second)) {
                //compute minimum cost
                minCost += weight;
                //increase count
                count++;
            }
        }
        //return minimum cost
        return minCost;
    }
};