package main

import "math"

func printNumbers(n int) []int {
	total := int(math.Pow(10.0, float64(n))) - 1
	res := make([]int, total)
	for i := 1; i <= total; i++ {
		res[i-1] = i
	}
	return res
}
