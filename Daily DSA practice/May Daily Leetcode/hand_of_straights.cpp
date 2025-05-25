class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int>mpp;
        for(auto it:hand)
        {
            mpp[it]++;
        }
        for(auto it:mpp)
        {
            if(it.second>0)
            {   
                for(int i = 0;i<groupSize;i++)
                {
                    if(mpp[it.first+i]<it.second) return false;
                    mpp[it.first+i] -= it.second;
                }
            }
        }
        return true;
    }
};


//queue approach