class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int area = 0;
        stack<int> st;
        int n = heights.size();
        int i = 0;
        while(i<n)
        {
            if(st.empty() || heights[i]>=heights[st.top()])
            {
                st.push(i);
                i++;
            }
            else
            {
                int tp = st.top();
                st.pop();
                int tmpArea = 0;
                if(st.empty())
                    tmpArea = (i*heights[tp]);
                else
                    tmpArea = heights[tp]*(i-st.top()-1);
                area = max(area,tmpArea);
            }
        }

        while(!st.empty())
        {
            int tp = st.top();
            st.pop();
            int tmpArea = 0;
            if(st.empty())
                tmpArea = (i*heights[tp]);
            else
                tmpArea = heights[tp]*(i-st.top()-1);
            area = max(area,tmpArea);
        }
        return area;
    }
};
