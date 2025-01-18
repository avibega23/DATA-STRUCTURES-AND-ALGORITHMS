class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int i = 0;
        int j = 0;
        int n = (n1 + n2);
        int index1 = n / 2;
        int index2 = index1 - 1;
        int el1 = -1;
        int el2 = -1;
        int cnt = 0;
        while (i < n1 && j < n2)
        {
            if (nums1[i] < nums2[j])
            {
                if (cnt == index1)
                    el1 = nums1[i];
                if (cnt == index2)
                    el2 = nums1[i];
                cnt++;
                i++;
            }
            else
            {
                if (cnt == index1)
                    el1 = nums2[j];
                if (cnt == index2)
                    el2 = nums2[j];
                cnt++;
                j++;
            }
        }
        while (i < n1)
        {
            if (cnt == index1)
                el1 = nums1[i];
            if (cnt == index2)
                el2 = nums1[i];
            cnt++;
            i++;
        }
        while (j < n2)
        {
            if (cnt == index2)
                el2 = nums2[j];
            if (cnt == index1)
                el1 = nums2[j];
            cnt++;
            j++;
        }
        if (n % 2 == 1)
        {
            return el1;
        }
        else
            return ((double)el1 + (double)el2) / 2;
    }
};