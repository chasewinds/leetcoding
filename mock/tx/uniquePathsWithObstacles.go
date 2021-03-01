package main

func uniquePathsWithObstacles(obstacleGrid [][]int) int {
	if obstacleGrid[0][0] == 1 || obstacleGrid[len(obstacleGrid)-1][len(obstacleGrid[0])-1] == 1 {
		return 0
	}
	return walk(obstacleGrid, 0, 0)
}

var dirs = [][]int{{1, 0}, {0, 1}}

func walk(grid [][]int, x, y int) int {

	if x == len(grid)-1 && y == len(grid[0])-1 {
		return 1
	}

	var ret int
	for _, dir := range dirs {
		i, j := x+dir[0], y+dir[1]
		if i >= 0 && i < len(grid) && j >= 0 && j < len(grid[0]) && grid[i][j] == 0 {
			ret += walk(grid, i, j)
		}
	}

	return ret
}
