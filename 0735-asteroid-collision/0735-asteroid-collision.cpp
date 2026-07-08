class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        vector<int> st;

        for (int i = 0; i < ast.size(); i++) {

            if (ast[i] > 0) {
                st.push_back(ast[i]);
            }
            else {
                while (!st.empty() &&
                       st.back() > 0 &&
                       st.back() < abs(ast[i])) {
                    st.pop_back();
                }

                if (!st.empty() &&
                    st.back() > 0 &&
                    st.back() == abs(ast[i])) {
                    st.pop_back();
                }
                else if (st.empty() || st.back() < 0) {
                    st.push_back(ast[i]);
                }
            }
        }

        return st;
    }
};