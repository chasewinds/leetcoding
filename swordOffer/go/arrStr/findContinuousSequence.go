package main

func findContinuousSequence(target int) [][]int {

	if target == 1 {
		return nil
	}

	p1, p2 := 1, 2
	var res [][]int
	for p1 < p2 {
		if sum := getSum(p1, p2); sum > target {
			p1++
		} else if sum < target {
			p2++
		} else {
			res = append(res, rangeBetween(p1, p2))
			p2++
		}
	}
	return res
}

func rangeBetween(x, y int) (ret []int) {
	for i := x; i <= y; i++ {
		ret = append(ret, i)
	}
	return
}

func getSum(x, y int) int { return (x + y) * (y - x + 1) / 2 }
