package main

func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {

    if len(nums1) == 0 && len(nums2) == 0 {
        return 0
    }
    if len(nums1) > len(nums2) {
        return findMedianSortedArrays(nums2, nums1)
    }

    total := (len(nums1) + len(nums2) + 1) / 2
    left, right := 0, len(nums1)
    for left < right {
        mid := (left + right + 1) / 2
        p := total - mid
        if nums1[mid - 1] > nums2[p] {
            right = mid - 1
        } else  {
            left = mid
        }
    }

    var n1left, n1right, n2left, n2right int
    p1, p2 := left, total - left
    intMin, intMax := math.MinInt64, math.MaxInt64
    if p1 == 0 {
        n1left = intMin
    } else {
        n1left = nums1[p1 - 1]
    }
    if p2 == 0 {
        n2left = intMin
    } else {
        n2left = nums2[p2 - 1]
    }

    if p1 == len(nums1) {
        n1right = intMax
    } else {
        n2right = nums1[p1]
    }
    if p2 == len(nums2) {
        n2right = intMax
    } else {
        n2right = nums2[p2]
    }

    fmt.Println("x", n1left, n1right, n2left, n2right)

    if (len(nums1) + len(nums2)) % 2 == 0 {
        return float64(min(n1right, n2right) + max(n1left, n2left)) / 2.0
    }
    return float64(max(n1left, n2left))
}

func max(x, y int) int {
    if x > y {
        return x
    }
    return y
}

func min(x, y int) int {
    if x < y {
        return x
    }
    return y
}
