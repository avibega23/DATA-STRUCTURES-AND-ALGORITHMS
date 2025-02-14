long long minimumSteps(string s) {
        long long sum  = 0;
        long long count = 0;
        for(int i = s.size()-1;i>=0;i--)
        {
            if(s[i]-'0'==0)
            {
                count++;
            }
            else
            {
                sum += count;
            }
        }
        return sum;
    }