#!/usr/bin/env python

class Solution:
    # @param A, a list of integers
    # @param target, an integer to be searched
    # @return a list of length 2, [index1, index2]
    def searchRange(self, A, target):
        start, end = 0, len(A) - 1
        while start <= end:
            middle = (start + end) / 2
            if A[middle] > target:
                end = middle - 1
            elif A[middle] < target:
                start = middle + 1
            else:
                range_start  = range_end = middle
                while A[range_start] == target:
                    range_start -= 1
                    if range_start < 0:
                        break
                while A[range_end] == target:
                    range_end += 1
                    if range_end > len(A) - 1:
                        break
                rs = []
                rs.append(range_start + 1)
                rs.append(range_end - 1)
                return rs
        return [-1, -1]

if __name__ == "__main__":
    solution = Solution()
    print solution.searchRange([1], 1)
