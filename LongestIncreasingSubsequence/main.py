# https://leetcode.com/problems/longest-increasing-subsequence/

list = []
longest_subsequence = []

n = int(input())
for i in range (0, n):
    next = int(input())
    list.append(next)
    
# Loop through each element
for i in range(0, n):

    max = 0 # The element we use to compare options
    
    # Loop backwards, and consider each element prior
    for j in range(i - 1, -1, -1):
        
        # If the element is smaller, and better than our max, we include it
        if (list[j] <= list[i] and longest_subsequence[j] > max):
            max = longest_subsequence[j]
    
    # Assign the value to this element
    longest_subsequence.append(max + 1)
    
print(longest_subsequence)