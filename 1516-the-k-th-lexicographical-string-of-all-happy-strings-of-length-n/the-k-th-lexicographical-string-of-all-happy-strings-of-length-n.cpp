class Solution {
public:
    void solve(int n, string curr, vector<string>& res){
        if(curr.size() == n){
            res.push_back(curr);
            return;
        }

        for(char c : {'a','b','c'}){
            if(curr.empty() || curr.back() != c){
                solve(n, curr + c, res);
            }
        }
    }

    string getHappyString(int n, int k) {
        vector<string> res;
        solve(n, "", res);

        if(k > res.size()) return "";
        return res[k-1];
    }
};