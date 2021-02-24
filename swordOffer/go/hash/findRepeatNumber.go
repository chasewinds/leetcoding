package main

func findRepeatNumber(nums []int) int {
	set := make(map[int]struct{})
	for i := range nums {
		if _, found := set[nums[i]]; found {
			return nums[i]
		}
		set[nums[i]] = struct{}{}
	}
	return -1
}
