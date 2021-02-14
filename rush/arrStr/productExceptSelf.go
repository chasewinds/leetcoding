package main

func productExceptSelf(nums []int) []int {

    if len(nums) == 0 {
        return []int{}
    }

    f := make([]int, len(nums))
    f[0] = 1
    for i := 1; i < len(nums); i++ {
        f[i] = nums[i - 1] * f[i - 1]
    }

    e := make([]int, len(nums))
    e[len(e) - 1] = 1
    for i := len(e) - 2; i >= 0; i-- {
        e[i] = nums[i + 1] * e[i + 1]
    }

    res := make([]int, len(nums))
    for i := 0; i < len(nums); i++ {
        res[i] = f[i] * e[i]
    }

    return res
}
