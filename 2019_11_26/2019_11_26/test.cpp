#if 0
//������ջʵ��һ������
class Solution
{
public:
	//Ĭ������ȫ����stack1�У�������ֱ��ѹջ
	void push(int node) {
		stack1.push(node);
	}
	//��ʱstack2Ϊ��ջ��ר��������ջ����
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

//��ֵ�������η�
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