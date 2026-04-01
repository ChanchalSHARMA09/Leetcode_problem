class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();

        vector<int> idx(n);
        for (int i = 0; i < n; i++) idx[i] = i;

      
        sort(idx.begin(), idx.end(), [&](int a, int b){
            return positions[a] < positions[b];
        });

        stack<int> st; 

        for (int id : idx) {
            if (directions[id] == 'R') {
                st.push(id);
            } else {
               
                while (!st.empty() && healths[id] > 0) {
                    int j = st.top();

                    if (healths[j] < healths[id]) {
                        st.pop();
                        healths[id]--;        
                        healths[j] = 0;
                    }
                    else if (healths[j] > healths[id]) {
                        healths[j]--;       
                        healths[id] = 0;
                    }
                    else {
                        
                        st.pop();
                        healths[id] = 0;
                        healths[j] = 0;
                    }
                }
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (healths[i] > 0)
                ans.push_back(healths[i]);
        }

        return ans;
    }
};