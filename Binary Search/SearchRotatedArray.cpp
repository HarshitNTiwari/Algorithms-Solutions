/*
Author: Harshit Tiwari
Date: 12-08-2022
https://leetcode.com/problems/search-in-rotated-sorted-array/
*/


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0; int high = nums.size()-1;
        while(low <= high){
            int mid = (low + high)/2;
            if(nums[mid] == target)
                return mid;
            if(nums[mid] > nums[high]){
                if(target < nums[mid] && target >=nums[low])
                    high = mid-1;
                else
                    low = mid+1;
            }
            else if(nums[mid] < nums[low]){
                if(target > nums[mid] && target <= nums[high])
                    low = mid+1;
                else
                    high = mid-1;
            }
            else{
                if(target < nums[mid])
                    high = mid-1;
                else
                    low = mid+1;
            }
        }
        return -1;
    }
};