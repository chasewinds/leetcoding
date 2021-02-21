package main

func subarraysDivByK(A []int, K int) int {
    if len(A) == 0 {
        return 0
    }

    dp := make([][]int, len(A))
    for i := range dp {
        dp[i] = make([]int, len(A))
        dp[i][0] = A[i]
    }

    var res int
    for i := 0; i < len(A); i++ {
        for j := i + 1; j < len(A); j++ {
            dp[i][j] = dp[i][j - 1]
            if dp[i][j] % K == 0 {
                res++
            }
        }
    }

    return res
}


