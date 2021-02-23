package main

// vote by mool
func majorityElement(nums []int) int {

	cur, count := nums[0], 1
	for i := 1; i < len(nums); i++ {
		if nums[i] == cur {
			count++
		} else {
			count--
		}
		if count == 0 {
			cur = nums[i]
			count++
		}
	}

	return cur
}

/*
// vote by hash
func majorityElement(nums []int) int {
    n2f := make(map[int]int)
    var maxF int
    var n int
    for i := range nums {
        n2f[nums[i]]++
        if n2f[nums[i]] > maxF {
            n = nums[i]
            maxF = n2f[nums[i]]
        }
    }

    return n
}

func max (x, y int) int {
    if x > y {
        return x
    }
    return y
}
*/
