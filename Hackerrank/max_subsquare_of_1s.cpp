/*
 * Complete the 'largestMatrix' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY arr as parameter.
 */

int largestMatrix(vector<vector<int>> arr) {
    int n = arr.size(), m = arr[0].size();
    vector<vector<int>> aux(n);
    for(auto& row : aux) {
        row.resize(m);
    }
    for(int i=0; i<n; i++)
        aux[i][0] = arr[i][0];
  
    for(int i=0; i<m; i++)
        aux[0][i] = arr[0][i];
    
    for(int i=1; i<n; i++) {
        for(int j=1; j<m; j++) {
            if (arr[i][j] == 1) {
                aux[i][j] = min(aux[i-1][j-1], min(aux[i-1][j], aux[i][j-1])) + 1;    
            }
            else {
                aux[i][j] = 0;
            }
        }
    }
    int result{std::numeric_limits<int>::min()};
    for(int i{0}; i < n; ++i) {
        result = std::max(result, *std::max_element(std::begin(aux[i]), std::end(aux[i])));
    }
    return result;
}

