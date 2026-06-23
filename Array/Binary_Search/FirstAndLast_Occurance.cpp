//Problem link:- https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/

class Solution {
public:
    int firstOccurance(vector<int>&nums, int n, int x){
        int low = 0,high=n-1;
        int ans = -1;
        while(low <= high){
            int mid = low+(high-low)/2;
            if(nums[mid] == x){
                ans = mid;
                high = mid-1;
            } 
            else if(nums[mid] < x) low = mid+1;
            else high = mid-1;
        }
        return ans;
    }
    int lastOccurance(vector<int>&nums, int n, int x){
        int low = 0, high=n-1;
        int ans = -1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(nums[mid]==x){
                ans = mid;
                low = mid+1;
            }
            else if(nums[mid] < x) low = mid+1;
            else high = mid-1;
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int first = firstOccurance(nums,n, target);
        if(first == -1)return {-1,-1};
        int last = lastOccurance(nums,n,target);
        return {first,last};
    }
};
