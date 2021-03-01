package main

func longestIncreasingPath(matrix [][]int) int {
	if len(matrix) == 0 || len(matrix[0]) == 0 {
		return 0
	}
	var res int
	memo := make([][]int, len(matrix))
	for i := range memo {
		memo[i] = make([]int, len(matrix[0]))
	}
	for i := 0; i < len(matrix); i++ {
		for j := 0; j < len(matrix[0]); j++ {
			res = max(res, dfs(matrix, memo, i, j))
		}
	}

	return res
}

func dfs(matrix, memo [][]int, x, y int) int {
	if memo[x][y] != 0 {
		return memo[x][y]
	}
	memo[x][y]++
	var nmax int
	p := matrix[x][y]
	if x-1 >= 0 && matrix[x-1][y] > p {
		nmax = max(nmax, dfs(matrix, memo, x-1, y))
	}
	if x+1 < len(matrix) && matrix[x+1][y] > p {
		nmax = max(nmax, dfs(matrix, memo, x+1, y))
	}
	if y-1 >= 0 && matrix[x][y-1] > p {
		nmax = max(nmax, dfs(matrix, memo, x, y-1))
	}
	if y+1 < len(matrix[0]) && matrix[x][y+1] > p {
		nmax = max(nmax, dfs(matrix, memo, x, y+1))
	}
	memo[x][y] = nmax + 1
	return memo[x][y]
}

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}
