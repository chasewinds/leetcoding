package main

func validateStackSequences(pushed []int, popped []int) bool {
	if len(pushed) != len(popped) {
		return false
	}
	if len(pushed) == 0 || len(popped) == 0 {
		return true
	}

	p := 0
	q := 0
	var stk []int
	for p < len(pushed) && p < len(popped) {
		if pushed[p] == popped[q] {
			p++
			q++
		} else if len(stk) != 0 && stk[len(stk)-1] == popped[q] {
			stk = stk[:len(stk)-1]
			q++
		} else if pushed[p] != popped[q] {
			stk = append(stk, pushed[p])
			p++
		}
	}
	for len(stk) != 0 && stk[len(stk)-1] == popped[q] {
		stk = stk[:len(stk)-1]
		q++
	}
	// fmt.Println("p", p, "q", q)
	if p != q || p != len(pushed) {
		return false
	}

	return true
}
