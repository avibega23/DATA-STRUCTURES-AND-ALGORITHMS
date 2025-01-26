// } Driver Code Ends
class Solution {
  public:
    // Complete this function
    // Function to sort the array according to frequency of elements.
    vector<int> sortByFreq(vector<int>& arr) {
        // Your code here
        unordered_map<int,int> freq;
        for(auto it:arr) freq[it]++;
        
        auto cmp = [&freq] (int a ,int b)
        {
            if(freq[a]==freq[b]) return a<b;
            else
            {
                return freq[a]>freq[b];
            }
        };
        sort(arr.begin(),arr.end(),cmp);
        
        return arr;
        
    }
};