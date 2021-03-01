package main

func solve(board [][]byte) {
	if len(board) == 0 || len(board[0]) == 0 {
		return
	}

	visited := make([][]bool, len(board))
	for i := range visited {
		visited[i] = make([]bool, len(board[0]))
	}

	for i := 0; i < len(board); i++ {
		if board[i][0] == 'O' {
			dfs(board, visited, i, 0)
		}
		if board[i][len(board[0])-1] == 'O' {
			dfs(board, visited, i, len(board[0])-1)
		}
	}

	for j := 0; j < len(board[0]); j++ {
		if board[0][j] == 'O' {
			dfs(board, visited, 0, j)
		}
		if board[len(board)-1][j] == 'O' {
			dfs(board, visited, len(board)-1, j)
		}
	}

	for i := 0; i < len(board); i++ {
		for j := 0; j < len(board[0]); j++ {
			// fmt.Println(visited[i][j])
			if board[i][j] == 'O' && !visited[i][j] {
				board[i][j] = 'X'
			}
		}
	}
}

var dirs = [][]int{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}

func dfs(board [][]byte, visited [][]bool, x, y int) {
	visited[x][y] = true
	for _, dir := range dirs {
		i, j := x+dir[0], y+dir[1]
		if i >= 0 && i < len(board) && j >= 0 && j < len(board[0]) && board[i][j] == 'O' && !visited[i][j] {
			dfs(board, visited, i, j)
		}
	}
}
