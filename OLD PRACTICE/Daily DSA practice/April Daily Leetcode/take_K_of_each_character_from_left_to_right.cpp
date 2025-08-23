class Solution {
    public:
        int takeCharacters(string s, int k) {
            vector<int>arr(3,0);
            for(char ch:s)
            {
                arr[ch-'a']++;
            }
            int minCnt = 0;
            if(arr[0]>=k && arr[1]>=k && arr[2]>=k) minCnt = arr[0]+arr[1]+arr[2];
            else return -1;
            int cnt = minCnt;
            int n = s.size();
            int i = 0,j = 0;
    
            while(j<n)
            {
                arr[s[j]-'a']--;
                cnt--;
                while(arr[0]<k||arr[1]<k||arr[2]<k)
                {
                    arr[s[i]-'a']++;
                    i++;
                    cnt++;
                }   
                minCnt = min(minCnt,cnt);
                j++;
            }
            return minCnt;
        }  
    };