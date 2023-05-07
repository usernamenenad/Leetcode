class Solution:
    def __init__(self) -> None:
        pass
    def longest_palindrome(self, s: str) -> str:
        if len(s) == 0: 
            return "EMPTY STRING"
        if len(s) == 1:
            return s
    
        start = 0
        end = len(s) - 1
        sol = s[0]
        
        while True:
            if start >= end:
                break
            
            while start != end and s[start] != s[end]:
                end -= 1

            if start == end:
                start += 1
                end = len(s) - 1
                continue
            
            temp_start = start 
            temp_end = end
            last_end = end

            while temp_start < temp_end:
                temp_start += 1
                temp_end -= 1
                if s[temp_start] != s[temp_end]:
                    temp_start = start
                    last_end -= 1
                    temp_end = last_end

            if temp_start >= temp_end:
                if len(sol) > last_end - start + 1:
                    start += 1
                    end = len(s) - 1
                    continue
            
                sol = s[start:last_end+1]
                start += len(sol)
                continue

            start += 1

        return sol

if __name__ == "__main__":
    solution = Solution()
    print("The longest palindrome: {palindrome}".format(palindrome=solution.longest_palindrome("yabadabadoo")))
