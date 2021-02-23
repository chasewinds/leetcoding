package main

// 两个指针都从头部开始遍历，要hendle很多特殊情况，丑哭了
/*
func exchange(nums []int) []int {

	if len(nums) == 0 {
		return nil
	}

	l, r := 0, 1
	for r < len(nums) && l <= r {
		for r < len(nums) && nums[r]%2 == 0 {
			r++
		}
		for l < len(nums) && nums[l]%2 == 1 && l <= r {
			l++
		}
		// now l is ou and r is ji
		if r < len(nums) && l < len(nums) && l <= r && nums[r]%2 == 1 { // ugly to cry
			// fmt.Println("nums[l]", nums[l], "nums[r]", nums[r])
			nums[l], nums[r] = nums[r], nums[l]
		}
		r++
	}

	return nums
}
*/

// 一个指针从头遍历，一个指针从尾遍历，美观而没有复杂的边界判断
func exchange(nums []int) []int {

	if len(nums) == 0 {
		return nil
	}

	s, e := 0, len(nums)-1
	for s < e {
		for s < e && nums[s]%2 == 1 {
			s++
		}
		for e > s && nums[e]%2 == 0 {
			e--
		}
		nums[s], nums[e] = nums[e], nums[s]
	}

	return nums
}
