
def reverse_number(num):
  # Reverse the number
  reverse = str(num)[::-1]
  # Return the number
  return int(reverse)

## Example usage:
print(reverse_number(1223)) # Output: 3221
print(reverse_number(987654321)) # Output: 123456789



In my opinion response 1 is better as it got the idea about the query correctly. 
here the question was about reversing an integer, it was trying to reverse an integer with slicing operation, though 
slicing operation works on a sequence that is a string or a list . so there was an error and i fixed it in the comment 
other than that this response full fill the requerements accurately 

on the other hand response 2 is negating the number correctly while that was not relevant to the question 