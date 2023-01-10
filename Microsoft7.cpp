class Solution {
public:
    bool dfs(int i,vector<vector<int>>& graph,vector<bool>& vis,vector<bool>& path_vis){
        if(path_vis[i])return false;
        if(vis[i])return true;
        bool ans=true;
        vis[i]=true;
        path_vis[i]=true;
        for(int j:graph[i]){
            ans&=dfs(j,graph,vis,path_vis);
        }
        path_vis[i]=false;
        return ans;
    }
    bool canFinish(int numCourses, vector<vector<int>>& p) {
        vector<bool> vis(numCourses,false),path_vis(numCourses,false);
        vector<vector<int>> graph(numCourses);
        for(int i=0;i<p.size();i++){
            graph[p[i][1]].push_back(p[i][0]);
        }
        bool ans=true;
        for(int i=0;i<numCourses;i++){
            if(!vis[i])ans&=dfs(i,graph,vis,path_vis);
        }
        return ans;
    }
};
