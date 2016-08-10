#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> vals;
        vals.resize(numRows);

        for(int i = 0; i < numRows; i++) {
        	vals[i].resize(i + 1);
        	vals[i][0] = 1;
        	vals[i][i] = 1;
        	for(int j = 1; j < i; j++) {
        		vals[i][j] = vals[i-1][j-1] + vals[i-1][j];
        	}
        }
        return vals;
    }
};

int main() {
	Solution solution;
	vector<vector<int>> vals = solution.generate(5);
	for(int i = 0; i < vals.size(); i++) {
		for(int j = 0; j < vals[i].size(); j++) {
			cout << vals[i][j] << " ";
		}
		cout << endl;
	}
}