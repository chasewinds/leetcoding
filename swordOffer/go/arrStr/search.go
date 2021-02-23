package main

func search(nums []int, target int) int {
	if len(nums) == 0 {
		return len(nums)
	}
	left, right := 0, len(nums)-1
	for left <= right {
		mid := (left + right) / 2
		if nums[mid] == target {
			return calcNum(nums, mid)
		} else if nums[mid] > target {
			right = mid - 1
		} else {
			left = mid + 1
		}
	}

	return 0
}

func calcNum(nums []int, idx int) int {
	l, r := idx, idx
	for l >= 0 && nums[l] == nums[idx] {
		l--
	}
	for r < len(nums) && nums[r] == nums[idx] {
		r++
	}
	count := r - l - 1
	if l == 0 && nums[l] == nums[idx] {
		count++
	}
	if r == len(nums)-1 && nums[r] == nums[idx] {
		count++
	}
	return count
}
