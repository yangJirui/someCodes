# include<iostream>
# include<vector>
#include <algorithm> 
using namespace std;

void merge(vector<int>& arr, int st1, int end1, int st2, int end2)
{   
	if (st1 > end1 || st1 > st2) return;
	int p1 = st1, p2 = st2;
	vector<int> tmp;
	while (p1 <= end1 && p2 <= end2)
	{
		if (arr[p1] < arr[p2])
			tmp.push_back(arr[p1++]);
		else
			tmp.push_back(arr[p2++]);
	}
	
	while (p1 <= end1)
		tmp.push_back(arr[p1++]);
	while (p2 <= end2)
		tmp.push_back(arr[p2++]);

	for (int i = 0; i < tmp.size(); i++)
		arr[st1 + i] = tmp[i];
}
//使用递归方法
void merge_sort(vector<int> &arr, int st, int end)
{

	if (st < end)
	{  
		int mid = (st + end) / 2;
		merge_sort(arr, st, mid);
		merge_sort(arr, mid + 1, end);
		merge(arr, st, mid, mid + 1, end);
	}
}

//使用循环方法
void merge_sort(vector<int> &arr)
{   
	int n = arr.size();
	
	for (int step = 2; step/2 < arr.size(); step = step * 2)
	{
		for (int i = 0; i < arr.size(); i += step)
		{
			int mid = i + step / 2 -1;
			if (mid+1<arr.size())
			merge(arr, i, mid, mid + 1, min(i+step-1, n-1));
		}

		/*int mid = arr.size() - 1 - step + step / 2 - 1;
		merge(arr, arr.size() - step, mid, mid + 1, arr.size()-1);*/
	}
}
int main() {
	vector<int> nums{ 1,4,3,2,5,6,3 };
	//merge_sort(nums, 0, 6);
	merge_sort(nums);
	//	MergeSort1(nums, 0, 6);
	for (auto x : nums)
		cout << x << " ";
	cout << endl;
	return 0;
}