//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    void solve(vector<vector<int>>&mat,string a,vector<string>&ans,int row,int col,int n)
    {
        if(row==n-1 && col == n-1)
        {
            ans.push_back(a);
            return;
        }
        
        if(row+1 < n && mat[row+1][col]==1)
        {
            mat[row][col] = -1;
            solve(mat,a+"D",ans,row+1,col,n);
            mat[row][col] = 1;
        }
        if(col-1 >= 0 && mat[row][col-1]==1)
        {
            mat[row][col] = -1;
            solve(mat,a+"L",ans,row,col-1,n);
            mat[row][col] = 1;
        }
        if(col+1 < n && mat[row][col+1]==1)
        {
            mat[row][col] = -1;
            solve(mat,a+"R",ans,row,col+1,n);
            mat[row][col] = 1;
        }
        if(row-1 >= 0 && mat[row-1][col]==1)
        {
            mat[row][col] = -1;
            solve(mat,a+"U",ans,row-1,col,n);
            mat[row][col] = 1;
        }
        
    }
    vector<string> findPath(vector<vector<int>> &mat) {
        vector<string>ans;
        // code here
        if(mat[0][0]==1)solve(mat,"",ans,0,0,mat.size());
        return ans;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        vector<vector<int>> mat;
        string innerArray;
        bool isInsideArray = false;

        for (char c : input) {
            if (c == '[') {
                if (isInsideArray) {
                    innerArray.clear();
                }
                isInsideArray = true;
            } else if (c == ']') {
                if (isInsideArray && !innerArray.empty()) {
                    vector<int> row;
                    stringstream ss(innerArray);
                    int num;

                    while (ss >> num) {
                        row.push_back(num);
                        if (ss.peek() == ',')
                            ss.ignore();
                        while (isspace(ss.peek()))
                            ss.ignore();
                    }

                    mat.push_back(row);
                    innerArray.clear();
                }
                isInsideArray = false;
            } else if (isInsideArray) {
                if (!isspace(c)) {
                    innerArray += c;
                }
            }
        }

        Solution obj;
        vector<string> result = obj.findPath(mat);
        sort(result.begin(), result.end());

        if (result.empty())
            cout << "[]";
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends