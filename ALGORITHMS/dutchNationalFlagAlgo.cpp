void dutchNationalFlagAlgo(vector<int>& a) {
    int low = 0, mid = 0, high = (int)a.size() - 1;

    while (mid <= high) {
        if (a[mid] == 0) {
            swap(a[low++], a[mid++]);   // 0-zone grows
        } else if (a[mid] == 1) {
            mid++;                      // 1 stays in middle
        } else { // a[mid] == 2
            swap(a[mid], a[high--]);    // 2 goes to end; don't mid++
        }
    }
}