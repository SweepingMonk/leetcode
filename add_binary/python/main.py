#!/usr/bin/env python
# encoding: utf8

class Solution:
    def addBinary(self, a, b):
        la, lb = len(a), len(b)
        rs = []
        i, j = la - 1, lb - 1
        last_bit = '0'
        while i >= 0 or j >= 0:
            ca = a[i] if i >= 0 else "0"
            cb = b[j] if j >= 0 else "0"
            if ca == '0' and cb == '0':
                rs.append(last_bit)
                last_bit = '0'
            elif ca == '1' and cb == '1':
                rs.append(last_bit)
                last_bit = '1'
            else:
                if last_bit == "1":
                    rs.append("0")
                    last_bit = "1"
                else:
                    rs.append("1")
                    last_bit = "0"
            i -= 1
            j -= 1
        
        if last_bit == "1":
            rs.append("1")
        return "".join(reversed(rs))


if __name__ == "__main__":
    solution = Solution()
    rs = solution.addBinary("10", "100")
    print rs
            
