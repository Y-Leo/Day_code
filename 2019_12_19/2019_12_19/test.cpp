#include<iostream>
#include<stack>
using namespace std;

//°üº¬minº¯ÊýµÄÕ»
class Solution {
public:
	void push(int value) {
		st.push(value);
		if (st_min.empty())
			st_min.push(value);
		if (st_min.top() > value)
			st_min.push(value);
	}
	void pop() {
		if (st.top() == st_min.top())
			st_min.pop();
		st.pop();
	}
	int top() {
		return st.top();
	}
	int min() {
		return st_min.top();
	}
private:
	stack<int>  st;
	stack<int>  st_min;
};


int main()
{
	Solution A;
	for (int i = 0; i < 10; ++i)
	{
		A.push(i);
	}
	cout << A.min() << endl;
	return 0;
}