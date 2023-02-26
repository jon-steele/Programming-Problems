# https://leetcode.com/problems/longest-increasing-subsequence/
class Solution(object):
    def lengthOfLIS(self, nums):

        list = nums
        longest_subsequence = []
            
        # Loop through each element
        for i in range(0, len(list)):

            maximum = 0 # The element we use to compare options
            
            # Loop backwards, and consider each element prior
            for j in range(i - 1, -1, -1):
                
                # If the element is smaller, and better than our max, we include it
                if (list[j] < list[i] and longest_subsequence[j] > maximum):
                    maximum = longest_subsequence[j]
            
            # Assign the value to this element
            longest_subsequence.append(maximum + 1)

        return(max(longest_subsequence))