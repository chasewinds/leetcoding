package main

func twoSum(nums []int, target int) []int {
	if len(nums) == 1 {
		return nil
	}

	p1, p2 := 0, len(nums)-1
	for p1 < p2 {
		sum := nums[p1] + nums[p2]
		if target > sum {
			p1++
		} else if target < sum {
			p2--
		} else {
			return []int{nums[p1], nums[p2]}
		}
	}
	return nil
}

/*
func twoSum(nums []int, target int) []int {
	n2i := make(map[int]int)
	for i := range nums {
		n2i[nums[i]] = i
	}
	for i := range nums {
		part := target - nums[i]
		if idx, found := n2i[part]; found && idx != i {
			return []int{nums[idx], nums[i]}
		}
	}

	return nil
}
*/

/*
// TLE的烂解法，原因：双指针设计有问题
func twoSum(nums []int, target int) []int {
    if len(nums) == 1 {
        return nil
    }

    p1, p2 := 0, 1
    for p1 < len(nums) {
        for p2 < len(nums) && nums[p1] + nums[p2] < target {
            p2++
        }
        if p2 == len(nums) {
            p1++
            p2 = p1 + 1
            continue
        }
        if nums[p1] + nums[p2] == target {
            return []int{nums[p1], nums[p2]}
        }
        for p1 < p2 && nums[p1] + nums[p2] > target {
            p1++
        }
        if nums[p1] + nums[p2] == target {
            return []int{nums[p1], nums[p2]}
        }
    }
    return nil
}
*/
