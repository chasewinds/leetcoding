package main

func maxSubArray(nums []int) int {
	dp := make([]int, len(nums))
	dp[0] = nums[0]
	res := nums[0]
	for i := 1; i < len(nums); i++ {
		if dp[i-1] > 0 {
			dp[i] = dp[i-1] + nums[i]
		} else {
			dp[i] = nums[i]
		}
		res = max(res, dp[i])
	}

	return res
}

/*
O(n2) solution with prefix sum
func maxSubArray(nums []int) int {
	pre := make([]int, len(nums))
	pre[0] = nums[0]
	for i := 1; i < len(nums); i++ {
		pre[i] = pre[i-1] + nums[i]
	}

	res := nums[0]
	for i := 0; i < len(nums); i++ {
		res = max(res, pre[i])
		for j := i + 1; j < len(nums); j++ {
			sum := pre[j] - pre[i]
			res = max(res, sum)
		}
	}

	return res
}
*/

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}
