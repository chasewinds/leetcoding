package main

func maxScoreSightseeingPair(A []int) int {

    mx := A[0]
    var res int
    for j := 1; j < len(A); j++ {
        res = max(res, A[j] - j + mx)
        mx = max(mx, A[j] + j)
    }

    return res
}

func max(x, y int) int {
    if x > y {
        return x
    }
    return y
}
