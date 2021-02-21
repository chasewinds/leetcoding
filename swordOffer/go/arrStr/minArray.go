package main

func minArray(numbers []int) int {
	if len(numbers) == 0 {
		return 0
	}

	left, right := 0, len(numbers)-1
	// end := numbers[len(numbers) - 1] 要想清楚为什么每次比较的是numbers[right]而不是end？
	for left < right {
		mid := (left + right) / 2
		if numbers[mid] > numbers[right] {
			left = mid + 1
		} else if numbers[mid] < numbers[right] {
			right = mid
		} else {
			right-- // 数组是不减的，如果最后的几个数都一样
		}
	}
	if numbers[left] < numbers[right] {
		return numbers[left]
	}

	return numbers[right]
}
