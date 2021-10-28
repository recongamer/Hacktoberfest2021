# BINARY SEARCH
# This search is performed in a "sorted" list. Searching of key begins from the middle index.
# Element is searched in the left sublist if element at the middle index is greater than the key.
# Element is searched in the right sublist if element at the middle index is lower than the key.
# This is a recursive process.
# Finally, function returns index of element if key is present. Returns '-1' if key is absent.


# Time Complexity
# Average Case: O(logn)
# Best Case: O(1) -> When key is present at the middle index.

def binary_search(arr, low, high, x):
 
    # Check base case
    if high >= low:
 
        mid = (high + low) // 2
 
        # If element is present at the middle itself
        if arr[mid] == x:
            return mid
 
        # If element is smaller than mid, then it can only
        # be present in left subarray
        elif arr[mid] > x:
            return binary_search(arr, low, mid - 1, x)
 
        # Else the element can only be present in right subarray
        else:
            return binary_search(arr, mid + 1, high, x)
 
    else:
        # Element is not present in the array
        return -1
 
# Test array
arr = [ 2, 3, 4, 10, 40 ]
x = 10
 
# Function call
result = binary_search(arr, 0, len(arr)-1, x)
 
if result != -1:
    print("Element is present at index", str(result))
else:
    print("Element is not present in array")
