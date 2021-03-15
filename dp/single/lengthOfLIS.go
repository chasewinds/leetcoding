package main

func lengthOfLIS(nums []int) int {
    l := len(nums)
    dp := make([]int, l)
    var res int
    for i := 0; i < l; i++ {
        dp[i] = 1
        for j := 0; j < i; j++ {
            if nums[j] < nums[i] {
                dp[i] = max(dp[i], dp[j] + 1)
            }
        }
        res = max(res, dp[i])
    }

    return res
}

func max(x, y int) int {
    if x > y {
        return x
    }
    return y
}

/*
func lengthOfLIS(nums []int) int {
    dp := make([]int, len(nums))
    for i := range dp {
        dp[i] = -1
    }
    back := nums[len(nums) - 1]
    var res int
    for i := range nums {
        if nums[i] < back {
            res = max(dp[i], f(i, back, dp, nums) + 1)
        }
    }

    return res
}

func f (i, tail int, dp, nums []int) int {
    if i < 0 {
        return 0
    }
    if dp[i] != -1 {
        return dp[i]
    }
    var res int
    for x := 0; x < i; x++ {
        if nums[x] < tail {
            res = max(res, f(x - 1, nums[x], dp, nums) + 1)
        }
    }
    dp[i] = res
    return dp[i]
}

func max(x, y int) int {
    if x > y {
        return x
    }
    return y
}
*/
