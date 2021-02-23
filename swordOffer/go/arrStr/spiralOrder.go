package main

func spiralOrder(matrix [][]int) []int {

	if len(matrix) == 0 || len(matrix[0]) == 0 {
		return nil
	}

	m, n := len(matrix)-1, len(matrix[0])-1
	l, r, t, b := 0, n, 0, m
	var res []int
	for l <= r && t <= b {
		// fmt.Println("l", l, "r", r, "t", t, "b", b)
		edges := listEdges(matrix, l, r, t, b)
		res = append(res, edges...)
		l++
		r--
		t++
		b--
	}

	return res
}

func listEdges(matrix [][]int, left, right, top, bottom int) (ret []int) {
	for i := left; i <= right; i++ {
		ret = append(ret, matrix[top][i])
	}
	for i := top + 1; i <= bottom; i++ {
		ret = append(ret, matrix[i][right])
	}
	if left < right && top < bottom { // 之所以要做不带等号的判断，是因为如果left == right, top == bottom，下面的两循环其实重复了上面的循环，所以不再执行
		for i := right - 1; i > left; i-- {
			ret = append(ret, matrix[bottom][i])
		}
		for i := bottom; i > top; i-- {
			ret = append(ret, matrix[i][left])
		}
	}
	return
}
