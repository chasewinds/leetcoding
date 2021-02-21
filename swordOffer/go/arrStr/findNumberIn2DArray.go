package main

func findNumberIn2DArray(matrix [][]int, target int) bool {
	if len(matrix) == 0 || len(matrix[0]) == 0 {
		return false
	}

	x, y := len(matrix)-1, 0
	for x >= 0 && y < len(matrix[0]) {
		if matrix[x][y] < target {
			y++
		} else if matrix[x][y] > target {
			x--
		} else {
			return true
		}
	}

	return false
}

/*
func findNumberIn2DArray(matrix [][]int, target int) bool {
    if len(matrix) == 0 || len(matrix[0]) == 0 {
        return false
    }

    return diveAndConter(matrix, target, 0, 0, len(matrix[0]) - 1, len(matrix) - 1)
}

func diveAndConter(matrix [][]int, target, left, up, right, down int) bool {
    if left < 0 || up < 0 || left >= len(matrix) || right >= len(matrix[0]) {
        return false
    }

    m1 := (up + down) / 2
    m2 := (left + right) / 2
    if mid := matrix[m1][m2]; mid == target {
        return true
    } else if mid < target {
        return diveAndConter(matrix, target, left, up, m2, m1)
    } else {
        return diveAndConter(matrix, target, m2 + 1, up, right, m1) ||
        diveAndConter(matrix, target, m2 + 1, m1 + 1, right, down) ||
        diveAndConter(matrix, target, left, m1 + 1, m2, down)
    }
}
*/
