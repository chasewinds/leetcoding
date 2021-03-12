package main

func uniquePathsWithObstacles(obstacleGrid [][]int) int {
	dp := make([][]int, len(obstacleGrid))
	for i := range dp {
		dp[i] = make([]int, len(obstacleGrid[0]))
	}
	dp[0][0] = 1

	for i := 0; i < len(obstacleGrid); i++ {
		for j := 0; j < len(obstacleGrid[0]); j++ {
			if obstacleGrid[i][j] == 1 {
				dp[i][j] = 0
				continue
			}
			if x, y := i, j-1; y >= 0 {
				dp[i][j] += dp[x][y]
			}
			if x, y := i-1, j; x >= 0 {
				dp[i][j] += dp[x][y]
			}
		}
	}
	// for i := 0; i < len(dp); i++ {
	//     for j := 0; j < len(dp[0]); j++ {
	//         fmt.Println(dp[i][j], " ")
	//     }
	//     fmt.Println()
	// }

	return dp[len(dp)-1][len(dp[0])-1]
}

/* TLE
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
*/
