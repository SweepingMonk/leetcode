#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
		int start = 0;
		int end = n - 1;
		int middle;
		vector<int> rs;
		while(start <= end){
			middle = (start + end) / 2;
			if(A[middle] > target){
				end = middle - 1;
			} else if(A[middle] < target){
				start = middle + 1;
			} else{
				int range_start = middle;
				int range_end = middle;
				while(A[range_start] >= target) {
					range_start--;
					if(range_start < 0) break;
				}
				while(A[range_end] <= target){
					range_end++;
					if(range_end > n - 1) break;
				} 
				rs.push_back(range_start + 1);
				rs.push_back(range_end - 1);
				return rs;
			}
		}
		rs.push_back(-1);
		rs.push_back(-1);
		return rs;
    }
};

int main(int argc, char** args){
	int a[] = {0, 0, 1, 1, 1, 2, 2, 2, 3, 3, 4, 4, 4, 4, 5};
	Solution solution;
	vector<int> rs = solution.searchRange(a, sizeof(a)/sizeof(int), 0);
	for(vector<int>::const_iterator i = rs.begin(); i != rs.end(); ++i){
		cout << *i;
	}
	cout << endl;
}

