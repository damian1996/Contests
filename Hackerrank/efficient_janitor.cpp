
int efficientJanitor(vector<float> weight) {
    sort(begin(weight), end(weight));
    int trips = 0;
    float maxi = 3.0;
    for(int i=0, j=weight.size()-1; i <= j; ) {
        float mass = weight[j--];
        while(mass < maxi && i <= j) {
            mass += weight[i++];
        }
        trips++;
    }
    return trips;
}
