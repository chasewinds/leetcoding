package main

func movingCount(m int, n int, k int) int {
	if k == 0 {
		return 1
	}

	visited := make([][]bool, m)
	for i := range visited {
		visited[i] = make([]bool, n)
	}

	res := dfs(visited, 0, 0, k)
	return res
}

func dfs(visited [][]bool, x, y, k int) int {
	if !valid(x, y, k) {
		return 0
	}
	visited[x][y] = true
	res := 1
	if x+1 < len(visited) && !visited[x+1][y] {
		res += dfs(visited, x+1, y, k)
	}
	if y+1 < len(visited[0]) && !visited[x][y+1] {
		res += dfs(visited, x, y+1, k)
	}
	return res
}

func valid(x, y, k int) bool {
	var sum int
	for x > 0 {
		sum += x % 10
		x /= 10
	}
	for y > 0 {
		sum += y % 10
		y /= 10
	}
	if k >= sum {
		return true
	}
	return false
}
