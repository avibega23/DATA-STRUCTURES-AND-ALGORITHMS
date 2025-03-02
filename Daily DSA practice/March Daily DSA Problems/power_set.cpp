void helper(string s,vector<string>&data,string ans,int index)
	    {
	        if(index>s.size())
	        {
	            if(ans.size()>0)
	            data.push_back(ans);
	            return;
	        }
	        helper(s,data,ans+s[index],index+1);
	        helper(s,data,ans,index+1);
	    }
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    vector<string>data;
		    string ans = "";
		    helper(s,data,ans,0);
		    sort(data.begin(),data.end());
		    return data;
		}
};