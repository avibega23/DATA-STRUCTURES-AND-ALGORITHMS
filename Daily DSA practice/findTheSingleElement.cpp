int getSingleElement(vector<int> &arr)
{
    // Write your code here.
    for (int i = 0; i < arr.size(); i++)
    {
        if (i == 0 && arr[i + 1] != arr[i])
            return arr[i];
        else if (i == arr.size() - 1 && arr[i] != arr[i - 1])
            return arr[i];
        else
        {
            if (arr[i] != arr[i + 1] && arr[i - 1] != arr[i])
                return arr[i];
        }
    }
    return 0;
}