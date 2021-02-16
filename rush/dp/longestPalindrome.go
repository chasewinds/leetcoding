package main

/*
func longestPalindrome(s string) string {

    if s == "" {
        return ""
    }

    var res string
    for i := range s {
        p1, p2 := searchBi(s, i, i) // have center
        if p2 - p1 + 1 > len(res) {
            res = s[p1: p2 + 1] // why p2 + 1 ?
        }

        p1, p2 = searchBi(s, i, i + 1) // don't have center
        if p2 - p1 + 1 > len(res) {
            res = s[p1: p2 + 1]
        }
    }

    return res
}

func searchBi(s string, p1, p2 int) (int, int) {

    for p1 >= 0 && p2 < len(s) && s[p1] == s[p2] {
        p1--
        p2++
    }

    return p1 + 1, p2 - 1
}
*/

func longestPalindrome(s string) string {
    if s == "" || len(s) == 1 {
        return s
    }

    dp := make([][]int, len(s))
    for i := range dp {
        dp[i] = make([]int, len(s))
    }

    res := string(s[0])
    for i := len(s) - 1; i >= 0; i-- { // 一定要注意循环顺序，如果i从零开始，dp[i + 1][j - 1]中的i + 1没有计算过，不ok
        for j := i; j < len(s); j++ {
            switch j - i {
            case 0:
                dp[i][j] = 1
            case 1:
                if s[i] == s[j] {
                    dp[i][j] = 1
                }
            default:
                if s[i] == s[j] {
                    dp[i][j] = dp[i + 1][j - 1]
                }
            }
            // fmt.Println("i", i, "j", j)
            if dp[i][j] == 1 && j - i + 1 > len(res) {
                res = s[i: j + 1]
            }
        }
    }

    return res
}

func reverse(s string) string {
    scopy := s
    runes := []rune(scopy)
    for i, j := 0, len(runes) - 1; i < j; i, j = i + 1, j - 1 {
        runes[i], runes[j] = runes[j], runes[i]
    }
    return string(runes)
}
