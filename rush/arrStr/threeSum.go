package main

 func threeSum(nums []int) [][]int {

     if len(nums) < 3 {
         return [][]int{}
     }

     sort.Ints(nums)
     n2i := make(map[int]int)
     for i, v := range nums {
         n2i[v] = i
     }

     var res [][]int
     for i := range nums {
         if i != 0 && nums[i] == nums[i - 1] {
             continue
         }
         for j := i + 1; j < len(nums); j++ {
             if j != i + 1 && nums[j] == nums[j - 1] {
                 continue
             }
             remain := -(nums[i] + nums[j])
             if idx, found := n2i[remain]; found && idx > j {
                 res = append(res, []int{nums[i], nums[j], nums[idx]})
             }
         }
     }

     return res
 }
