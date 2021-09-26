#include<iostream>
#include<string>
#include<stack>
using namespace std;
int prec(char s) {
	if (s == '^')
		return 3;
	else if (s == '*' || s == '/')
		return 2;
	else if (s == '+' || s == '-')
		return 1;
	else
		return -1;
}
void post(string exp)
{
	string result;
	stack<char>st;
	for (int i = 0; i < exp.length(); i++) {
		char s = exp[i];
		if (isalnum(s))

			result += s;


		else if (s == '(')
			st.push(s);
		else if (s == ')')
		{
			while (st.top() != '(')
			{
				result += st.top();
				st.pop();
			}
			st.pop();

		}
		else
		{
			while (!st.empty() && prec(exp[i]) <= prec(st.top()))
			{
				result += st.top();
				st.pop();

			}
			st.push(s);

		}


	}
	while (!st.empty()) {
		result += st.top();
		st.pop();
	}
	cout << result << '\n';

}



int main() {
	string exp;
	//cout << "enter the expression";
	exp = "(a+b)*c";

	post(exp);


	return 0;
}

