class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        vector<int> pse(n),nse(n);
        st.push(0);
        pse[0]=-1;
        for(int i=1;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]) st.pop();
            if(st.empty()) pse[i] = -1;
            else pse[i] = st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        st.push(n-1);
        nse[n-1] = n;
        for(int i=n-2 ; i>=0 ; i--){
            while(!st.empty() && heights[st.top()]>=heights[i]) st.pop();
            if(st.empty()) nse[i] = n;
            else nse[i] = st.top();
            st.push(i);
        }
        int res = INT_MIN;
        for(int i=0 ; i<n ; i++){
            int area = (nse[i]-pse[i] - 1) * heights[i];
            res = max(res,area);
        }
        return res;
    }
};