func longestPalindrome(s string) string {
    n := len(s)
    dp := make([][]int, n)
    for i := 0; i < n; i++ {
        dp[i] = make([]int, n)
    }

    var ans string
    for l := 0; l < n; l++ {
        for i := 0; i < n - l; i++ {
            j := l + i
            switch {
            case l == 0:
                dp[i][j] = 1
            case l == 1:
                if s[i] == s[j] {
                    dp[i][j] = 1
                }
            default:
                if s[i] == s[j] {
                    dp[i][j] = dp[i + 1][j - 1]
                }
            }
            if dp[i][j] == 1 && l + 1 > len(ans) {
                ans = s[i: i + l + 1]
            }
        }
    }
    return ans
}

/*
func longestPalindrome(s string) string {
    var res string
    for i := 0; i < len(s); i++ {
        p1 := searchBiDirection(i, i, s)
        p2 := searchBiDirection(i, i + 1, s)
        if (len(p1) > len(res)) {
            res = p1
        }
        if (len(p2) > len(res)) {
            res = p2
        }
    }
    return res
}

func searchBiDirection(i int, j int, s string) string {
    for i >= 0 && j < len(s) && s[i] == s[j] {
        i--;
        j++;
    }
    return s[i + 1: j]
}
*/
