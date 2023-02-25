process_time = []
deadlines = []

# Taking input

n = int(input())

for i in range (0, n):
    next = int(input())
    process_time.append(next)
    
for i in range (0, n):
    next = int(input())
    deadlines.append(next)
    
# Algorithm

values = []
for i in range (0, n):
    next = deadlines[i] - process_time[i] # Calculate the value
    values.append([next, i]) # Keep track of index

sorted(values, reverse=True) # Sort the list to find the optimal sequence

print(values)
