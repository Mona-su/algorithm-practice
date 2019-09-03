# 
# 编程挑战说明：
# You are given a sorted array of positive integers and a number X. 
# Print out all pairs of numbers whose sum is equal to X. 
# Print out only unique pairs and the pairs should be in ascending order
# 输入:
# Your program should read lines of text from standard input. 
# Each line will contain a comma separated list of sorted numbers, 
# followed by a semicolon, followed by the integer X.
# 输出：
# For each line of input, print to standard output the pairs of numbers that sum to X. 
# Print the pairs in ascending order (the first number of each pair should be less 
# than or equal to the second number). If no pair exists that sums to X, print the string NULL.
# 
import sys

for line in sys.stdin:
  lists = line.split(';')
  list1 = lists[0].split(',')
  for i in range(len(list1)):
    list1[i] = int(list1[i])
  num = int(lists[1])
  left = 0
  right = len(list1) - 1
  ans = []
  while left < right:
    if list1[left] + list1[right] == num:
      ans.append(list1[left])
      ans.append(list1[right])
      left = left + 1
      right = right - 1
    elif list1[left] + list1[right] < num:
      left = left+1
    else:
      right = right - 1
    
  if len(ans) == 0:
    print("NULL")
  else:
    for i in range(len(ans) - 1):
      if i % 2 == 0:
        print(str(ans[i]), end=',')
      else:
        print(str(ans[i]), end=';')
    print(ans[len(ans)-1])