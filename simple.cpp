#include <iostream>
#include <algorithm>
#include <iterator>
#include <stack>
#include <set>
using namespace std;

void package(int *arr, int start, int end);
void print();
void updateSet();

set<stack<int> > res;
stack<int> st;
int t;
int sum = 0;

int main()
{
		
		int size;
		int *arr;
		cout << "Please enter the size of the bag: ";
		cin >> t;
		cout << "Please enter the number of stuff ";
		cin >> size;
		cout << "Please enter the size of these stuff: ";

		arr = new int[size];
		for (int i = 0; i < size; ++i)
			cin >> arr[i];

		sort(arr, arr + size);
		print();

		return 0;

}

void package(int *arr, int start, int end)
{
	if (start <= end && sum == t)
	{
		updateSet();
		return;
	}
	else if ( start == end && sum != t || sum > t)
		return;

	for (int i = start + 1; i <= end; ++i)
	{
		//递归前先把第一个元素压入栈内
		st.push(arr[i - 1]);
		sum += arr[i - 1];
		//递归后面的元素（从第二个开始）
		package(arr, i, end);
		//递归后将第一个元素弹出
		sum -= st.top();
		st.pop();
	}	
}

void updateSet()
{
	res.insert(st);
}

void print()
{
	if (res.empty())
	{
		cout << "No solution." << endl;
		return;
	}

	for (set<stack<int> >::iterator it = res.begin(); it != res.end(); ++it)
	{	
		stack<int> temp(*it);
		cout << "(";
	
		while (temp.size() > 1) {
			cout << temp.top() << ", ";
			temp.pop();
		}
		cout << temp.top();
		temp.pop();

		cout << ")" << endl;
	}
}