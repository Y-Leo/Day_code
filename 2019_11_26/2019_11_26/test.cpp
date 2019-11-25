#if 0
//用两个栈实现一个队列
class Solution
{
public:
	//默认数据全放在stack1中，新数据直接压栈
	void push(int node) {
		stack1.push(node);
	}
	//此时stack2为空栈，专门用来出栈操作
	int pop() {
		if (stack2.empty())
		{
			while (!stack1.empty())
			{
				stack2.push(stack1.top());
				stack1.pop();
			}
		}
		int del = stack2.top();
		stack2.pop();
		return del;
	}

private:
	stack<int> stack1;
	stack<int> stack2;
};
#endif

//数值的整数次方
class Solution {
public:
	double Power(double base, int exponent) {
		if (exponent == 0)
			return 1;
		else if (exponent == 1)
			return base;
		double tmp;
		if (exponent > 1)
			tmp = base * Power(base, exponent - 1);
		if (exponent < 0)
			tmp = (1 / base)*Power(base, exponent + 1);
		return tmp;
	}
};