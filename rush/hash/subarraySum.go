package main

/*
func subarraySum(nums []int, k int) int {
    
    if len(nums) == 0 {
        return 0
    }

    var res int
    for i := 0; i < len(nums); i++ {
        sum := nums[i]
        for j := i + 1; j < len(nums); j++ {
            sum += nums[j]
            if sum == k {
                res++
            }
        }
    }

    return res
}
*/

func subarraySum(nums []int, k int) int {

    if len(nums) == 0 {
        return 0
    }

    record := map[int]int{0: 1}
    var pre, res int
    for i := range nums {
        pre += nums[i]
        if f, found := record[pre - k]; found {
            res += f
        }
        record[pre]++ // why !found record[pre] = 1 !ac?
    }

    return res
}
