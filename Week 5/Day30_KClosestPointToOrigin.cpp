class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        sort(points.begin(), points.end(), [](vector<int> a, vector<int> b) {
            return (a[0]*a[0] + a[1]*a[1]) < (b[0]*b[0] + b[1]*b[1]);
        });
        vector<vector<int>> v;
        for(int i=0;i<K;i++) {
            vector<int> x({points[i][0], points[i][1]});
            v.push_back(x);
        }
        return v;
    }
};