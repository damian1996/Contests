#include <bits/stdc++.h>
using namespace std;

int getIntSize(int number) {
    if(number == 0) return 0;
    int res = getIntSize(number/10); 
    return res + 1;
}

int allNine(int number) {
    if(number % 10 != 9) return false;
    if(number/10 == 0) return true;
    bool res = allNine(number/10);
    return res;   
}

vector<char> getVecToCompare(int N, vector<char>& org, int zeroes, int addition) {
    int i = 0;
    vector<char> toCompare(N);
    for(; i < org.size() && i < N; i++) {
        toCompare[i] = org[i];
    }
    for(; (i < org.size() + zeroes) && i < N; i++) {
        toCompare[i] = '0';
    }
    int sizeAddition = getIntSize(addition);
    vector<char> helper;
    for(int j=i; (j < org.size() + zeroes + sizeAddition); j++) {
        helper.push_back((addition % 10) + '0');
        addition /= 10; 
    }
    
    std::reverse(helper.begin(), helper.end());
    for(int j=0; i < N; j++, i++)
        toCompare[i] = helper[j];
    return toCompare;
}

int getNumberCharToCompare(int origI, int origPrev, int zeroesPrev, int additionPrev) {
    if(origI <= origPrev + zeroesPrev + additionPrev)  
        return origI;
    return origPrev + zeroesPrev + additionPrev;
}

int main() {
    std::ios::sync_with_stdio(false);
    int n, number, t, rest;
    cin >> n;
    vector<int> vec(n);
    vector<vector<char>> orig(n);
    vector<int> zeroes(n), addition(n);
    for(int i=0; i<n; i++) {
        cin >> vec[i];
        number = vec[i];
        while(number > 0) {
            rest = number%10;
            number = number/10;
            orig[i].push_back(rest + '0');
        }
        std::reverse(orig[i].begin(), orig[i].end());
    }
    zeroes[0] = 0;
    addition[0] = 0;
    long long result = 0;
    for(int i=1; i<n; i++) {
        int sizPrevToCompare = getNumberCharToCompare(orig[i].size(), orig[i-1].size(), zeroes[i-1], getIntSize(addition[i-1]));
        vector<char> toCompare = getVecToCompare(sizPrevToCompare, orig[i-1], zeroes[i-1], addition[i-1]);
        int state = -1, prevSize = orig[i-1].size() + zeroes[i-1] + getIntSize(addition[i-1]);
        if(orig[i].size() > prevSize) {
            addition[i] = 0;
            zeroes[i] = 0; 
            continue;
        }
        for(int j=0; j<sizPrevToCompare; j++) {
            if(orig[i][j] > toCompare[j]) {
                state = 1; break;
            } else if(orig[i][j] < toCompare[j]) {
                state = 0; break;
            }
        }
        addition[i] = 0;
        if(state == 0) { // oryginalny jest mniejszy
            zeroes[i] = orig[i-1].size() + zeroes[i-1] + getIntSize(addition[i-1]) - orig[i].size() + 1;
        } 
        else if(state == 1) { // oryginalny jest wiekszy, 
            zeroes[i] = orig[i-1].size() + zeroes[i-1] + getIntSize(addition[i-1]) - orig[i].size();
        } 
        else {
            if(orig[i].size() < prevSize) 
            {
                if(sizPrevToCompare < orig[i-1].size()) { // trzeba dopelnic np. dla 989 i 9, trzeba uzupelnic o 89
                    if(addition[i-1] == 0 && zeroes[i-1] == 0) {
                        string sss(orig[i-1].begin()+sizPrevToCompare, orig[i-1].end());
                        int grr = std::stoi(sss);
                        if(allNine(grr)) {
                            zeroes[i] = orig[i-1].size() - sizPrevToCompare + 1;
                            addition[i] = 0;
                        } else {
                            zeroes[i] = 0;
                            addition[i] = grr + 1;
                        }
                    }
                    else if(addition[i-1] == 0 && zeroes[i-1] != 0) {
                        zeroes[i] = zeroes[i-1] - 1 + orig[i-1].size() - sizPrevToCompare;
                        addition[i] = 1;
                    }
                    else if(addition[i-1] != 0 && zeroes[i-1] == 0) {
                        string sss(orig[i-1].begin()+sizPrevToCompare, orig[i-1].end());
                        std::to_string(addition[i-1]);
                        string super = sss + std::to_string(addition[i-1]);
                        int grr = std::stoi(sss);
                        if(allNine(grr+1)) {
                            zeroes[i] = super.size() + 1;
                            addition[i] = 0;
                        } else {
                            addition[i] = grr + 1;
                            zeroes[i] = 0;
                        }
                    }
                    else {
                        for(int kk=sizPrevToCompare; kk<orig[i-1].size(); kk++) // oj, tutaj bedzie wiecej roboty
                            orig[i].push_back(orig[i-1][kk]);

                        result += orig[i-1].size() + sizPrevToCompare;

                        if(allNine(addition[i-1] + 1)) {
                            addition[i] = addition[i-1] + 1;
                            zeroes[i] = zeroes[i-1] - 1; 
                        } else {
                            addition[i] = addition[i-1] + 1;
                            zeroes[i] = zeroes[i-1];
                        }
                    }
                    result += getIntSize(addition[i]);
                }
                else 
                {
                    if(addition[i-1] == 0 && zeroes[i-1] == 0) {
                        zeroes[i] = 1;                      
                    } 
                    else if(addition[i-1] == 0 && zeroes[i-1] != 0) {
                        zeroes[i] = zeroes[i-1] - 1;
                        addition[i] = 1;
                    } 
                    else if(addition[i-1] != 0 && zeroes[i-1] == 0) {
                        if(allNine(addition[i-1])) {
                            zeroes[i] = zeroes[i-1] + getIntSize(addition[i-1]) + 1;
                            addition[i] = 0;
                        } else {
                            zeroes[i] = 0;
                            addition[i] = addition[i-1] + 1;
                        }
                    } 
                    else {
                        if(allNine(addition[i-1])) {
                            addition[i] = addition[i-1] + 1;
                            zeroes[i] = zeroes[i-1] - 1;
                        } 
                        else {
                            addition[i] = addition[i-1] + 1;
                            zeroes[i] = zeroes[i-1];
                        }
                    }
                    result += getIntSize(addition[i]);
                }
            } 
            else if(orig[i].size() == prevSize) {
                vector<char> final_test = getVecToCompare(prevSize, orig[i-1], zeroes[i-1], addition[i-1]);
                int state = 0;
                for(int lol=0; lol<prevSize; lol++) {
                    if(final_test[lol] > orig[i][lol]) {
                        state = -1; break;
                    }
                    if(final_test[lol] < orig[i][lol]) {
                        state = 1; break;
                    }
                }
                if(state == -1) {
                    zeroes[i] = zeroes[i-1] + 1;   
                } else if(state == 0) {
                    zeroes[i] = zeroes[i-1] + 1; // samo 1?
                } else {
                    zeroes[i] = 0;
                }
            } 
            else {
                zeroes[i] = 0;
            }
        }
        result += zeroes[i];
    }
    cout << result << endl;
    return 0;
}
