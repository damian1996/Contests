/*
 * Complete the 'getMinimumUniqueSum' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

bool sanity_check(vector<int> arr) {
    for(int i=0; i<arr.size(); i++) {
        for(int j=0; j<arr.size(); j++) {
            if(i!=j) {
                if(arr[i] == arr[j])
                    return false;
            }
        }
    }
    return true;
}

int getMinimumUniqueSum(vector<int> arr) {
    sort(arr.begin(), arr.end());
    int prev = arr[0];
    std::list<int> to_upd;
    for(int i=1; i<arr.size(); i++) {
        if(arr[i] == prev) {
            to_upd.push_back(i);
        } else {
            int diff_to_fill = arr[i] - prev - 1;
            int border = min(diff_to_fill, static_cast<int>(to_upd.size()));
            for(int j=1; j <= border; j++) {
                arr[to_upd.front()] = prev + j;
                to_upd.pop_front();
            }
        }
        prev = arr[i];
    }
    int siz = to_upd.size();
    for(int i=0; i<siz; i++) {
        arr[to_upd.front()] = prev + i + 1;
        to_upd.pop_front();
    }
    //cout << sanity_check(arr) << endl;
    return std::accumulate(arr.begin(), arr.end(), 0);
}

