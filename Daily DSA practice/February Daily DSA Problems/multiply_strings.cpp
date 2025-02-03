class Solution {
public:
    string multiply(string num1, string num2) {
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        vector<int>ans((num1.size()+num2.size()),0);

        int n = num1.size();
        int m = num2.size();

        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                int digit = (num1[i]-'0') * (num2[j]-'0');

                ans[i+j] += digit;
                ans[i+j+1] += ans[i+j] /10;
                ans[i+j] = ans[i+j]%10;
            }
        }
        string result = "";
        reverse(ans.begin(),ans.end());
        int index = 0;
        while(index < ans.size()&&ans[index]==0)
        {
            index++;
        }
        while(index < ans.size()) result += ans[index++]+'0';

        if(result.empty()) return "0";
        return result;
    }
};