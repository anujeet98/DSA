#include<iostream>
#include<stack>

using namespace std;

void stock_span(int stock_prices[], int n, int span[]) {
	stack<int> stk;

	stk.push(0);  //index for first element =0
	span[0] = 1; //span of first element is always 1

	//for remaining n-1
	for (int i = 1; i <= n - 1; i++) {
		int current_price = stock_prices[i];
		while (!stk.empty() and stock_prices[stk.top()] <= current_price) {
			stk.pop();
		}

		if (stk.empty())
			span[i] = i + 1;
		else
			span[i] = i - stk.top();

		//push the current value and update the span
		stk.push(i);
	}
}


int main(int argc, char const *argv[])
{
	int stock_prices[] = {100, 80, 60, 70, 60, 75, 85};
	int n = sizeof(stock_prices) / sizeof(stock_prices[0]);

	int span[10000] = {};
	stock_span(stock_prices, n, span);

	for (int i = 0; i < n; i++) {
		cout << span[i] << endl;
	}

	return 0;
}

