def mergesort(merge_list):
    if(len(merge_list) <= 1):
        return merge_list
    half = len(merge_list)//2
# Oh how I love python.  (list slicing)++
# Copy relevant parts of original list to new sublists
    left = merge_list[:half]
    right = merge_list[half:]
    left = mergesort(left)
    right = mergesort(right)
    return merge(left, right)

def merge(left, right):
    result = []
    r, l = 0, 0
    while(l<len(left) and r<len(right)):
        if(left[l]<=right[r]):
            result.append(left[l])
            l+=1
        else:
            result.append(right[r])
            r+=1
    if(left):
        result.extend(left[l:])
    if(right):
        result.extend(right[r:])
    return result

def init():
    merge_list = [3, 92, 33, 20, 34, 95, 74, 3, 1, 20, 47, 38, 19, 11, 23, 24, 85, 872, 38, 10]
    print(merge_list)
    sort = mergesort(merge_list)
    print(sort)

init()
