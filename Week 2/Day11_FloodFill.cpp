class Solution {
public:
    int x[4] = {0, 0, -1, 1};
    int y[4] = {1, -1, 0, 0};
    int vis[55][55];
    
    bool isSafe(vector<vector<int>>& image, int sr, int sc) {
        return sr >= 0 && sc >= 0 && sr < image.size() && sc < image[0].size(); 
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        vis[sr][sc] = 1;
        for(int i=0;i<4;i++) {
            if(isSafe(image, sr + x[i], sc + y[i]) && !vis[sr + x[i]][sc + y[i]] && image[sr][sc] == image[sr + x[i]][sc + y[i]]) {
            floodFill(image, sr + x[i], sc + y[i], newColor);
            }   
        }
        image[sr][sc] = newColor;
        return image;
    }
};