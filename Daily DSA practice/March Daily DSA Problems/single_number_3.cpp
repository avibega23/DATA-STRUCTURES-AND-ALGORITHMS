long long XOR = 0;
         for(int i = 0;i<nums.size();i++)
         {
            XOR = XOR^nums[i];
         }
         XOR = (XOR & (XOR-1))^XOR;

        long long XOR1=0;
        long long XOR2=0;
        for(int i = 0;i<nums.size();i++)
        {
            if((nums[i]&XOR)!=0)
            {
                XOR1 = XOR1^nums[i];
            }
            else
            {
                XOR2 = XOR2^nums[i];
            }
        }
        return{(int)XOR1,(int)XOR2};