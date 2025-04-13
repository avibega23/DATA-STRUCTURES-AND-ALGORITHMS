class Solution {
    public:
        bool lemonadeChange(vector<int>& bills)
        {
            int five = 0,ten = 0,fifteen = 0,twenty = 0;
            for(int i = 0;i<bills.size();i++)
            {
                if(bills[i]==5)five++;
                else if(bills[i]==10)
                {
                    if(five==0) return false;
                    else
                    {
                        five--;
                        ten++;
                    }
                }
                else if(bills[i]==15)
                {
                    if(ten >= 1)
                    {
                        ten--;
                        fifteen++;
                    }
                    else if(five >= 2)
                    {
                        five -= 2;
                        fifteen++;
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    if(ten >= 1 && five >= 1)
                    {
                        ten--;
                        five--;
                        twenty++;
                    }
                    else if(five >= 3)
                    {
                        five -= 3;
                        twenty++;
                    }
                    else return false;
                }
            }
            return true;
        }
    };