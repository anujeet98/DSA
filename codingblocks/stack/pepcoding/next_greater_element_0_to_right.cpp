//time=O(n) as push and pop is only once
//https://www.pepcoding.com/resources/online-java-foundation/stacks-and-queues/next-greater-element-official/ojquestion#!



#include <bits/stdc++.h>




using namespace std;
void display(vector<int>a) {
  for (int i = 0; i < a.size(); i++)
  {
    cout << a[i] << endl;
  }
}
vector<int> solve(vector<int>arr)
{
  stack<int>st;

  for (int i = arr.size() - 1; i >= 0; i--) {
    while (!st.empty() and st.top() < arr[i]) {
      st.pop();
    }

    int curr = arr[i];
    if (!st.empty()) {
      arr[i] = st.top();
    }
    else {
      arr[i] = -1;
    }
    st.push(curr);

  }

  return arr;
}
int main(int argc, char** argv)
{
  int n;
  cin >> n;
  vector<int>arr(n, 0);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  vector<int>nge(n, 0);
  nge = solve(arr);
  display(nge);
  return 0;
}