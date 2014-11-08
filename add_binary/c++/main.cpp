#include<string>
#include<iostream>
#include<algorithm>
#include<sstream>
using namespace std;

class Solution{
public:
	string addBinary(string a, string b){
		int la = a.length();
		int lb = b.length();
		int i = la - 1;
		int j = lb - 1;
		string rs;
		char last_bit = '0';
		while(i >= 0 || j >= 0){
			char ca = i >= 0 ? a[i] : '0';
			char cb = j >= 0 ? b[j] : '0';
			if(ca == '0' && cb == '0'){
				rs.append(1, last_bit);
				last_bit = '0';
			} else if(ca == '1' && cb == '1'){
				rs.append(1, last_bit);
				last_bit = '1';
			}else{
				if(last_bit == '1'){
					rs.append(1, '0');
					last_bit = '1';
				}else{
					rs.append(1, '1');
					last_bit = '0';
				}
			}
			i--;
			j--;
		}
		if (last_bit == '1'){
			rs.append(1, '1');
		}
		reverse(rs.begin(), rs.end());
		return rs;
	}
};

int main(int argc, char** args){
	Solution solution;
	cout << solution.addBinary("10", "10") << endl;
}
