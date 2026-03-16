class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        set<int> sums;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                
                sums.insert(grid[i][j]); 
                
                for(int k = 1; i-k >= 0 && i+k < m && j-k >= 0 && j+k < n; k++){
                    
                    int sum = 0;
                    
                    int x = i - k, y = j;
                    
                    for(int t = 0; t < k; t++) sum += grid[x+t][y+t];
                    for(int t = 0; t < k; t++) sum += grid[x+k+t][y+k-t];
                    for(int t = 0; t < k; t++) sum += grid[x+2*k-t][y-t];
                    for(int t = 0; t < k; t++) sum += grid[x+k-t][y-k+t];
                    
                    sums.insert(sum);
                }
            }
        }
        
        vector<int> ans;
        
        for(auto it = sums.rbegin(); it != sums.rend() && ans.size() < 3; it++){
            ans.push_back(*it);
        }
        
        return ans;
    }
};