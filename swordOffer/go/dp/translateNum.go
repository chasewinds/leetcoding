package main

import "strconv"

func translateNum(num int) int {
	s := strconv.Itoa(num)
	if len(s) == 1 {
		return 1
	}

	p, q, r := 0, 0, 1
	for i := 0; i < len(s); i++ {
		p, q, r = q, r, 0
		r += q
		if i == 0 {
			continue
		}
		if x := s[i-1 : i+1]; x >= "10" && x <= "25" {
			r += p
		}
	}

	return r
}
