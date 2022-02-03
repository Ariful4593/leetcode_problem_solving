# def findDuplicate(nums):
#     seen = {}
#     for num in nums:
#         if num in seen:
#             print(num)
#             return num
#         seen[num] = True        

# # findDuplicate([3,1,3,4,2])
# print(findDuplicate([3,1,10,4,5,6,5,2]))

def test2(nums):
    tortuise = nums[0]
    hare = nums[0]
    while True:
        tortuise = nums[tortuise]
        hare = nums[nums[hare]]
        if tortuise == hare:
            break
    
    ptr1 = nums[0]
    ptr2 = tortuise
    while ptr1 != ptr2:
        ptr1 = nums[ptr1]
        ptr2 = nums[ptr2]
    return ptr1

print(test2([3,1,10,4,5,6,5,2]))