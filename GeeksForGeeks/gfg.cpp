#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() 
{
	int N, X, Y, t;
	cin >> t;
	for(int tt=0; tt<t; tt++)
	{
        cin >> N >> X >> Y;
        vector<int> A(N);
        vector<int> B(N);
        vector<int> tips(N);
        for(auto& el : tips) el = 0;
        for(auto& el : A) cin >> el;
        for(auto& el : B) cin >> el;
        tips[0] = max(A[0], B[0]);
        if(A[0] < B[0]) Y--;
        else X--;
        for(int i=1; i<N; i++)
        {
            cout << "tips[" << i-1 << "] = " << tips[i-1] << "  " << X << " " << Y << endl;
	        if(A[i] >= B[i])
            {
                if(X) {
                    X--;
                    tips[i] = tips[i-1] + A[i];   
                }
                else {
                    int diff = A[i] - B[i], toSwap = -1;
                    for(int j=0; j<i; j++)
	                {   
	                    int diff2 = A[j] - B[j];
	                    if(A[i] >= B[i] && diff > diff2) 
	                    {
	                        diff = diff2;
	                        toSwap = j;
	                    }
	                }      
	                tips[i] = (toSwap == -1) ? (tips[i-1] + B[i]) : (tips[i-1] + A[i] - A[toSwap] + B[toSwap]);
                }
            }
            else {
                if(Y) {
                    Y--;
                    tips[i] = tips[i-1] + B[i];   
                }
                else {
                    int diff = B[i] - A[i], toSwap = -1;
                    for(int j=0; j<i; j++)
	                {   
	                    int diff2 = B[j] - A[j];
	                    if(A[i] < B[i] && diff > diff2) 
	                    {
	                        diff = diff2;
	                        toSwap = j;
	                    }
	                }      
	                tips[i] = (toSwap == -1) ? (tips[i-1] + A[i]) : (tips[i-1] + B[i] - B[toSwap] + A[toSwap]);
                }
            }
        }
        cout << tips[N-1] << endl;
	}
	return 0;
}
