class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int gradient;
        bool inf = 0;
        if(coordinates[0][1] - coordinates[1][1] == 0) {
            inf = 1; 
        } else {
            gradient = (coordinates[0][0] - coordinates[1][0]) / (coordinates[0][1] - coordinates[1][1]); 
        }
        
        for(int i=1;i<coordinates.size()-1;i++) {
            if(coordinates[i][1] - coordinates[i+1][1] == 0) {
                if(!inf) {
                    return 0;   
                }
            } else if(gradient != (coordinates[i][0] - coordinates[i+1][0]) / (coordinates[i][1] - coordinates[i+1][1])) {
                    return 0;
            }
        }
        return 1; 
    }
};