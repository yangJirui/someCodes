# include<iostream>
# include<vector>

using namespace std;


void adjust_heap(vector<int>& arr, int i, int N) // adjust node i
{
    int left = 2 * i + 1;
    for (int left = 2 * i + 1; left < N; left = 2 * left + 1)
    {
        int right = left + 1;
        int j = left;
        if (right < N && arr[left] < arr[right])
            j = right;

        if (arr[i] < arr[j])
            swap(arr[i], arr[j]);
        else
            break;
    }
}

void heap_sort(vector<int>& arr)
{
    
    for (int i = arr.size() / 2 - 1; i >= 0; i--)
        adjust_heap(arr, i, arr.size());


    for (int i = arr.size() - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        adjust_heap(arr, 0, i);
    }

}

int main()
{
    vector<int> arr = { 3, 4, 6, 1, 2, 3, 9, 0 };
    heap_sort(arr);

    for (auto e : arr)
        cout << e << " ";
    cout << endl;
}