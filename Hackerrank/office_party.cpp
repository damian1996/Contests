#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'maxCut' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY radius
 *  2. INTEGER m
 */

const float  PI = 3.14159265359;

double getArea(int rad) {
    return PI * rad * rad;
}

bool possibleDivision(double piece, vector<double>& areas, int m) {
    for(int i = 0; i < areas.size() ; i++) {
        int parts = areas[i] / piece;
        m -= parts;
        if(m <= 0) return true;    
    }
    return false;
}

string maxCut(vector<int> radius, int m) {
    vector<double> areas(radius.size());
    for(int i=0; i<areas.size(); i++) {
        areas[i] = getArea(radius[i]);
    }
    double l = areas[0]/m;
    double r = *max_element(areas.begin(), areas.end());
    double mid;
    cout << "MAXI " << r << endl;
    while (r > l + 1e-4)  
    {
        mid = (l+r)/2; 
        cout << fixed << mid << endl;
        cout << fixed << l << " " << r << endl;
        if(possibleDivision(mid, areas, m)) {
            l = mid; 
        }
        else {
            r = mid;    
        }
    }

    std::stringstream ss;
    ss << std::fixed << std::setprecision(4) << l;
    return ss.str();
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string radius_count_temp;
    getline(cin, radius_count_temp);

    int radius_count = stoi(ltrim(rtrim(radius_count_temp)));

    vector<int> radius(radius_count);

    for (int i = 0; i < radius_count; i++) {
        string radius_item_temp;
        getline(cin, radius_item_temp);

        int radius_item = stoi(ltrim(rtrim(radius_item_temp)));

        radius[i] = radius_item;
    }

    string m_temp;
    getline(cin, m_temp);

    int m = stoi(ltrim(rtrim(m_temp)));

    string result = maxCut(radius, m);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
