int dirs[2][2] = {{0, 1}, {1, 0}};
int global_cnt = 1;

void BFS(int i, int j, int d, int h, int w, vector<vector<int>>& floodfill, vector<string>& pic) {
    int ii = i + dirs[d][0], jj = j + dirs[d][1];
    if(pic[i][j] == pic[ii][jj]) {
        floodfill[ii][jj] = floodfill[i][j];
    } else {
        if(floodfill[ii][jj] == 0) {
            global_cnt++;
        }
    }
    for(int k=0; k<2; k++) {
        if (ii + dirs[k][0] < h && jj + dirs[k][1] < w) {
            BFS(ii, jj, k, h, w, floodfill, pic);            
        }
    }
}

int strokesRequired(vector<string> picture) {
    int h = picture.size();
    int w = picture[0].size();
    vector<vector<int>> floodfill(h);
    for(int i=0; i<h; i++) floodfill[i].resize(w);
    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            floodfill[i][j] = 0;
        }
    }
    floodfill[0][0] = 1;
    for(int i=0; i<2; i++) {
        BFS(0, 0, i, h, w, floodfill, picture);
    }
    cout << global_cnt << endl;
    return global_cnt;
}