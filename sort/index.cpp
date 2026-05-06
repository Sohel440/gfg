#include <bits/stdc++.h>
using namespace std;

// 4 1 3 2 5

void sec_sort(vector<int> &a)
{
    int n = a.size();
    for (int i = 0; i < n - 1; i++)
    {

        int si = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[si])
            {
                swap(a[j], a[si]);
            }
        }
    }
}
// 4 1 3 2 5
void bub_sort(vector<int> &a)
{
    int n = a.size();

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
            }
        }
    }
}
// 1 , 4,  3 2 5
void insert_Sort(vector<int> &a)
{

    int n = a.size();
    for (int i = 1; i < n; i++)
    {
        int curr = a[i];
        int prev = i;

        while (prev > 0 && a[prev - 1] > curr)
        {
            a[prev] = a[prev - 1];
            prev--;
        }
        a[prev] = curr;
    }
}

int pivot(vector<int> &a, int l, int r)
{
    int idx = l - 1, pivot = a[r];
    for (int j = l; j < r; j++)
    {
        if (a[j] <= pivot)
        {
            idx++;
            swap(a[idx], a[j]);
        }
    }
    idx++;
    swap(a[r], a[idx]);
    return idx;
}
void quickSort(int l, int r, vector<int> &a)
{
    if (l >= r)
        return;
    int n = a.size();
    int p = pivot(a, l, r);
    quickSort(l, p - 1, a);
    quickSort(p + 1, r, a);
}

void Print(vector<int> &a)
{
    for (auto t : a)
    {
        cout << t << " ";
    }
    cout << endl;
}

void merge(int l, int m, int r, vector<int> &a)
{

    int i = l, j = m + 1;

    vector<int> left, right;

    while (i <= m)
    {
        left.push_back(a[i++]);
    }
    while (j <= r)
    {
        right.push_back(a[j++]);
    }

    i = 0;
    j = 0;
    // vector<int> ans;
    vector<int> ans;

    while (i < left.size() && j < right.size())
    {
        if (left[i] < right[j])
        {
            ans.push_back(left[i++]);
        }
        else
        {
            ans.push_back(right[j++]);
        }
    }

     while(i < left.size()) {
        ans.push_back(left[i++]);
    }
    while(j < right.size()) {
        ans.push_back(right[j++]);
    }
    int ind = 0;
    for (int i = l; i <= r; i++)
    {
        a[i] = ans[i - l];
    }
}
void mergeSort(int l, int r, vector<int> &a)
{
      if(l >= r) return;
    int n = a.size();
    int mid = (l + r) / 2;
    mergeSort(l, mid, a);
    mergeSort(mid + 1, r, a);
    merge(l, mid, r, a);
}

int main()
{
    // std::time_t now = std::time(nullptr);
    // std::cout << std::ctime(&now);
    vector<int> a = {4, 1, 3, 2, 5, 1, -2, 0};
    // bub_sort(a);
    // sec_sort(a);
    // insert_Sort(a);
    // quickSort(0, 7, a);
    mergeSort(0, 7, a);
    Print(a);
    std::time_t end = std::time(nullptr);
    std::cout << std::ctime(&end);
    return 0;
}