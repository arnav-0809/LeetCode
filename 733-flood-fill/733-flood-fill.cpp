class Solution {
    void sol(vector<vector<int>>& img, int sr, int sc, int nc,int c){
        if(sr<0 || sc<0 || sr>=img.size() || sc>=img[0].size())
            return;
        if(img[sr][sc]==c){
            img[sr][sc]=nc;
            sol(img,sr+1,sc,nc,c);
            sol(img,sr-1,sc,nc,c);
            sol(img,sr,sc+1,nc,c);
            sol(img,sr,sc-1,nc,c);
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& img, int sr, int sc, int nc) {
        if(img[sr][sc]!=nc)
        sol(img,sr,sc,nc,img[sr][sc]);
        return img;
    }
};