class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        if(n>m)
        {
            return findMedianSortedArrays(nums2,nums1);
        }
        if(n==0)
        {
            if(m%2==1)
            {
                return double(nums2[m/2]);
            }
            else
            {
                return double((nums2[m/2]+nums2[m/2-1])/double(2));
            }
        }
        int req = (m+n+1)/2;
        int low = 0;
        int high = n;
        double ans = 0.0;
        while(low<=high)
        {
            int xPart = low + (high-low)/2;
            int yPart = req-xPart;
            cout << xPart << " " << yPart << endl;
            int maxXLeft, maxYLeft, minXRight, minYRight;
            if(xPart>0)
                maxXLeft = nums1[xPart-1];
            else
                maxXLeft = INT_MIN; 
            
            if(xPart<n)
                minXRight = nums1[xPart];
            else
                minXRight = INT_MAX;
            
            if(yPart>0)
                maxYLeft = nums2[yPart-1];
            else
                maxYLeft = INT_MIN; 
            
            if(yPart<m)
                minYRight = nums2[yPart];
            else
                minYRight = INT_MAX;
            
            if(maxXLeft<=minYRight && maxYLeft<=minXRight) //found
            {
                if((m+n)%2==1) //odd total length
                {
                    ans = (double)max(maxXLeft,maxYLeft);
                }
                else
                {
                    ans = (double)((max(maxXLeft,maxYLeft)+min(minXRight,minYRight))/(double)2);
                }
                return ans;
            }
            else if(maxXLeft>minYRight)
            {
                high = xPart-1;
            }
            else
            {
                low = xPart+1;
            }
        }
        return ans;
    }
};
