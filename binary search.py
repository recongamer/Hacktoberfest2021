# BINARY SEARCH
# This search is performed in a "sorted" list. Searching of key begins from the middle index.
# Element is searched in the left sublist if element at the middle index is greater than the key.
# Element is searched in the right sublist if element at the middle index is lower than the key.
# This is a recursive process.
# Finally, function returns index of element if key is present. Returns '-1' if key is absent.


# Time Complexity
# Average Case: O(logn)
# Best Case: O(1) -> When key is present at the middle index.

def binarySearch(sortedList, key, start, end):
    '''Returns index of key present in the sorted list. Returns -1 if key not found.'''
    if start <= end:
        middleIndex = (start + end) // 2
        middleElement = sortedList[middleIndex]

        if middleElement == key:
            return middleIndex
        elif middleElement < key:
            location = binarySearch(sortedList, key, middleIndex + 1, end)
        else:
            location = binarySearch(sortedList, key, start, middleIndex - 1)

        return location

    return -1


myList = [10, 25, 35, 50, 80, 100, 150, 500, 750, 999]
target = 25
location = binarySearch(myList, target, 0, len(myList) - 1)
print(f'Element found at index {location}.')
