class Solution {
public:
    unordered_map<string,vector<pair<string,double>>> graph;  //global declare

    double DFS(string src , string dest , unordered_set<string>&visited)
    {
        if(graph.find(src) == graph.end())   //edge condition 
        {
            return -1.0;
        }

        if(src == dest)
        {
            return 1;
        }

        visited.insert(src);

        for(auto node : graph[src])   //check for its respective node
        {
            if(visited.find(node.first) != visited.end())
            {
                continue;
            }

            double res = DFS(node.first , dest , visited);

            if(res != -1)
            {
                return res * node.second;
            }
        }

        return -1;
    }
        

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {

        int n = equations.size();

        for(int i =0 ;i<n;i++)
        {
            string a = equations[i][0];  //first element of equation vector
            string b = equations[i][1];  // second element of equation  vector
            double val = values[i];   //corresponding value to elements 

            graph[a].push_back({b,val});    //push it into graph
            graph[b].push_back({a,(1/val)});  // in opposite dir.
        }
          
        vector<double>result;   //to store result

        for(auto query : queries)    //iterate for every value
        {
            unordered_set<string>visited;
            result.push_back(DFS(query[0],query[1],visited));
        }

        return result;
    }
};