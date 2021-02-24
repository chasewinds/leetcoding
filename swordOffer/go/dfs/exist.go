package main

func exist(board [][]byte, word string) bool {

	if len(board) == 0 || len(board[0]) == 0 {
		return false
	}

	for i := 0; i < len(board); i++ {
		for j := 0; j < len(board[0]); j++ {
			if backtrack(board, i, j, word, 0) {
				return true
			}
		}
	}

	return false
}

func backtrack(board [][]byte, x, y int, word string, idx int) bool {

	if idx >= len(word) || board[x][y] != word[idx] {
		return false
	}
	if idx == len(word)-1 {
		return true
	}
	board[x][y] = '0'

	var ok bool
	if x-1 >= 0 && board[x-1][y] != '0' {
		ok = ok || backtrack(board, x-1, y, word, idx+1)
	}
	if x+1 < len(board) && board[x+1][y] != '0' {
		ok = ok || backtrack(board, x+1, y, word, idx+1)
	}
	if y-1 >= 0 && board[x][y-1] != '0' {
		ok = ok || backtrack(board, x, y-1, word, idx+1)
	}
	if y+1 < len(board[0]) && board[x][y+1] != '0' {
		ok = ok || backtrack(board, x, y+1, word, idx+1)
	}
	board[x][y] = word[idx]

	return ok
}
