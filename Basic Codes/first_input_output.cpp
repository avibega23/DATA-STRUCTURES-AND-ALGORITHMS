#include <bits/stdc++.h>
using namespace std;
class heap{
    public:
        int size;
        int arr[100];
        heap()
        {
            size = 0;
            arr[0] = -1;
        }
        void insert(int x)
        {
            size++;
            int index = size;
            arr[index] = x;

            while(index > 1)
            {
                int root = index/2;
                if(arr[root]<arr[index])
                {
                    swap(arr[root],arr[index]);
                    index = root;
                }
                else return;
            }
        }
        void deleteFromHeap()
        {
            if(size == 0) return;
            arr[1] = arr[size];
            size--;

            int i = 1;
            while(i<size)
            {
                int leftIndex = 2*i;
                int rightIndex = 2*i+1;

                if(leftIndex <= size && arr[i]<arr[leftIndex])
                {
                    swap(arr[i],arr[leftIndex]);
                    i = leftIndex;
                }
                else if(rightIndex <= size && arr[i] < arr[rightIndex])
                {
                    swap(arr[i],arr[rightIndex]);
                    i = rightIndex;
                }
                else return;
            }
        }
        void print()
        {
            for(int i = 1;i<=size;i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    heap a;
    a.insert(40);
    a.insert(33);
    a.insert(37);
    a.insert(30);
    a.insert(32);
    a.insert(31);

    a.deleteFromHeap();
    a.print();

    return 0;
}