class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        int i=0,j=0;
        vector<int>nums3;

        while(i<n && j<m){
            if(nums1[i]<nums2[j]){
                nums3.push_back(nums1[i++]);
            }else{
                nums3.push_back(nums2[j++]);

            }

        }
        while(i<n)nums3.push_back(nums1[i++]);
        while(j<m)nums3.push_back(nums2[j++]);

        int total=n+m;
        if(total % 2==1){
            return nums3[total/2];
        }
        return (nums3[total/2-1] + nums3[total/2])/2.0;
        
    }
};