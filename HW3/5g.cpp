//
// Created by Kaddijatou Baldeh on 7/20/22.
//

class Solution
{
public:
    int flag = 0;

    void helper( int i, list<int>* adj, stack<int>& Stack, vector<bool> &visited, vector<bool>& recStack)
    {
        visited[i] = true;
        recStack[i] = true;
        for(auto it = adj[i].begin(); it != adj[i].end(); it++)
        {
            if(!visited[*it])
                helper(*it,adj,Stack,visited, recStack);

//          if the node is visited and is still a part of recursion stack then there is a cycle.
            else if(visited[*it] && recStack[*it])
            {
                flag = 1;
                return;
            }
        }
        recStack[i] = false;
        Stack.push(i);
    }


    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
    {
        int n = prerequisites.size();
        vector<int> res;

//      no prerequisites
        if(n == 0)
        {
            for(int i = 0; i < numCourses; i++)
                res.push_back(i);
            return res;
        }

        list<int>* adj = new list<int>[numCourses];
        stack<int> Stack;
        vector<bool>visited(n,false);
        vector<bool> recStack(n,false);

//      making the directed graph using adjacency list
        for(int i = 0; i < n; i++)
        {
            int st = prerequisites[i][1];
            int fi = prerequisites[i][0];
            adj[st].push_back(fi);
        }

//      doing topological sort if acyclic or if cycle found return {}
        for(int i = 0; i < numCourses; i++)
        {
            if(!visited[i])
                helper(i,adj,Stack,visited,recStack);
            if(flag == 1)
                return {};
        }
        while(!Stack.empty())
        {
            res.push_back(Stack.top());
            Stack.pop();
        }

//      removing the dynamically alloted memory
        delete[] adj;

//      returning the answer;
        return res;
    }
};