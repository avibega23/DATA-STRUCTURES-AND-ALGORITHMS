class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size()-1;
        int j = b.size()-1;
        int count = 0;
        string ans = "";
        while(i>=0||j>=0||count)
        {
            int sum = count;
            if(i>=0)
            {
                sum+= a[i]-'0';
                i--;
            }
            if(j>=0)
            {
                sum+= b[j]-'0';
                j--;
            }

            ans += (sum%2) + '0';
            count = sum/2;
            
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};