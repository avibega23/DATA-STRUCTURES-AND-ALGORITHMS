#include <bits/stdc++.h>
using namespace std;
void heapify(int arr[],int n,int i)
{
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if(left < n && arr[left]>arr[largest])
        largest = left;
    if(right < n && arr[right]>arr[largest])
        largest = right;

    if(largest != i)
    {
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0;i<n;i++)
    {
        cin >> arr[i];
    }
    for(int i = n/2;i>=0;i--)
    {
        heapify(arr,n,i);
    }
    for(int i = 0;i<n;i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}