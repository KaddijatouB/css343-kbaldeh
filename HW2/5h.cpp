//Implementation of the solution for leetcode problem
//[Heap/priority queue]

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Use pair data type to couple two points in the priority queue container
        priority_queue<pair<int,vector<int>>> queueList;
        // Loop through points
        for (int i = 0 ; i < points.size(); i++) {
            // compute distance for the squared Euclidean distance
            int distance = pow(points[i][0],2) + pow(points[i][1],2);
            //add points to the queue
            queueList.push({distance, {points[i][0], points[i][1]}});
            if(queueList.size() < k){
                queueList.pop();
            }
        }
        // Return the points stored in the queue
        vector<vector<int>> results;
        while (!queueList.empty()) {
            results.push_back(queueList.top().second);
            queueList.pop();
        }
        return results;
    }
};