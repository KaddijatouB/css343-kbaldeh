// 210. Course Schedule II
//[Topological sort]

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        // Create the adjacency list representation of the graph
        vector<vector<int>> listQueue(numCourses);
        vector<int> InDegree(numCourses, 0);

        for(int i = 0;i < prerequisites.size(); i++){
            listQueue[prerequisites[i][1]].push_back(prerequisites[i][0]);
            InDegree[prerequisites[i][0]]++;
        }
        // Add all vertices with 0 in-InDegree to the queue
        queue<int> pq;
        for(int i = 0;i < numCourses;i++){
            if(InDegree[i] == 0){
                pq.push(i);
            }
        }
        int total = 0;
        vector<int> topologicalSorted;
        // Loop through the queue until becomes empty
        while(!pq.empty()){
            total++;
            int x = pq.front();
            pq.pop();
            topologicalSorted.push_back(x);
            // Reduce the in-InDegree of each neighbor by 1
            for(auto it:listQueue[x]){
                InDegree[it]--;
                if(InDegree[it] == 0){
                    pq.push(it);
                }
            }
        }
        // Check to see if ordering is possible  or not.
        if(topologicalSorted.size() == numCourses){
            return topologicalSorted;
        }
        else{
            return {};
        }
    }
};