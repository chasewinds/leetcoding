func lengthOfLongestSubstring(s string) int {
    if s == "" {
        return 0
    }

    i := 0
    res := 1
    for i < len(s) {
        memo := map[byte]struct{}{s[i]: struct{}{}}
        for j := i + 1; j < len(s); j++ {
            if _, found := memo[s[j]]; found {
                break
            }
            memo[s[j]] = struct{}{}
            if j - i + 1 > res {
                res = j - i + 1
            }
        }
        i++
    }
    return res
}