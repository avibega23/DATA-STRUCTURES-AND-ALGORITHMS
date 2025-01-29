int index = -1;
        for(int i = 0;i<haystack.size();i++)
        {
            if(haystack[i]==needle[0])
            {
                index = i;
                int j = i; int k = 0;int count = 0;
                while(j<haystack.size()&&k<needle.size())
                {
                    if(haystack[j]==needle[k])
                    {
                        count++;
                        k++;
                        j++;
                    }
                    else 
                    {
                        count = 0;
                        index = -1;
                        break;
                    }
                }
                if(count==needle.size())
                {
                    return index;
                }
            }
        }
        return -1;
    }