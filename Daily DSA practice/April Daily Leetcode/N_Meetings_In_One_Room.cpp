//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    static bool cmp(pair<int,int>p1,pair<int,int>p2)
    {
        if(p1.second == p2.second)
        {
            return p1.first > p2.first;
        }
        return p1.second < p2.second; 
    }
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        vector<pair<int,int>>pairs(start.size());
        for(int i = 0;i<pairs.size();i++)
        {
            pairs[i] = {start[i],end[i]};
        }
        
        sort(pairs.begin(),pairs.end(),cmp);
        
        int currTime = -1;
        int cnt = 0;
        
        for(int i = 0;i<pairs.size();i++)
        {
            if(currTime < pairs[i].first)
            {
                cnt++;
                currTime = pairs[i].second;
            }
        }
        return cnt;
        
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> start;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            start.push_back(num);
        }

        vector<int> end;
        getline(cin, input);
        stringstream s22(input);
        while (s22 >> num) {
            end.push_back(num);
        }

        Solution ob;
        int ans = ob.maxMeetings(start, end);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends