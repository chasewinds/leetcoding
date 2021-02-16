package main

func maxProfit(prices []int) int {

    profit := 0
    lowest := math.MaxInt64
    for i := 0; i < len(prices); i++ {
        lowest = min(lowest, prices[i])
        profit = max(profit, prices[i] - lowest)
    }

    return profit
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
