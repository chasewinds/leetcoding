package main

func constructArr(a []int) []int {
	if len(a) == 0 {
		return nil
	}

	pre := make([]int, len(a))
	pre[0] = 1
	for i := 1; i < len(a); i++ {
		pre[i] = pre[i-1] * a[i-1]
	}

	tail := make([]int, len(a))
	tail[len(a)-1] = 1
	for i := len(a) - 2; i > -1; i-- {
		tail[i] = tail[i+1] * a[i+1]
	}

	res := make([]int, len(a))
	for i := 0; i < len(a); i++ {
		res[i] = pre[i] * tail[i]
	}

	return res
}
