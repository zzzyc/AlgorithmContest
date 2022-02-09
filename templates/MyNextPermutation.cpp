/*
author: solego
create time: 2022/02/09 13:52
Coding Interviews II 38. https://leetcode-cn.com/problems/zi-fu-chuan-de-pai-lie-lcof/
*/
#include<bits/stdc++.h>
using namespace std;

template<class T>
class MyNextPermutation {
private:
	T s;
	T temp;
	int has_next;
public:
	MyNextPermutation(T s) : s(s), temp(s), has_next(0) {} 
	bool nextp(T& s) {
    	
    	if(has_next == 0) {
        	has_next = 1;
        	temp = s;
		}
    	
    	int p = (int)s.size() - 1;
    	while(p > 0 && s[p - 1] >= s[p]) p -= 1;
    	reverse(s.begin() + p, s.end());
    	
    	if(p > 0) {
    		for(int i = p; i < (int)s.size(); ++i)
    			if(s[i] > s[p - 1]) {
    				swap(s[i], s[p - 1]);
    				break;
				}
		}
    	
        if(temp == s){
			has_next = 2;
		}
		
		return has_next != 2;
    }
};

class Solution {
public:
    
    vector<string> permutation(string s) {
    	vector<string> res;
    	
        sort(s.begin(), s.end());
    	
    	MyNextPermutation<string> mnp(s);
    	do {
    		res.push_back(s);
		} while(mnp.nextp(s));
        
        return res;
    }
};



int main()
{
	Solution x;
	string s = "abc";
	auto res = x.permutation(s);
	for(auto& u : res) cout << u << "\n";

	return 0;
}

