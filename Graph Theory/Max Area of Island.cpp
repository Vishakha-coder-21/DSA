class Solution {
public:
    int dfs(vector<vector<int>>& g, int i, int j){
        if(i<0||j<0||i==g.size()||j==g[0].size()||!g[i][j]) return 0;
        g[i][j]=0;
        return 1+dfs(g,i+1,j)+dfs(g,i-1,j)+dfs(g,i,j+1)+dfs(g,i,j-1);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[0].size();j++)
                if(grid[i][j])
                    ans=max(ans,dfs(grid,i,j));
        return ans;
    }
};
