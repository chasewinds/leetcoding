package main

func lengthOfLongestSubstring(s string) int {
    if len(s) == 0 {
        return 0
    }

    l, r := 0, 0
    memo := make(map[byte]struct{})
    var res int
    for l < len(s) {
        if l != 0 {
            delete(memo, s[l - 1])
        }
        for r < len(s) {
            if _, found := memo[s[r]]; !found {
                memo[s[r]] = struct{}{}
                r++
            } else {
                break
            }
        }
        res = max(res, r - l)
        l++
    }

    return res
}

func max(x, y int) int {
    if x > y {
        return x
    }
    return y
}
