package main

import "strings"

func addBoldTag(s string, dict []string) string {
	mask := make([]bool, len(s))
	end := 0
	for i := 0; i < len(s); i++ {
		for _, word := range dict {
			if i+len(word) <= len(s) && s[i:i+len(word)] == word {
				end = max(end, i+len(word))
			}
		}
		mask[i] = end > i
	}

	var ans strings.Builder
	for i := 0; i < len(s); i++ {
		if mask[i] && (i == 0 || !mask[i-1]) {
			ans.WriteString("<b>")
		}
		ans.WriteByte(s[i])
		if mask[i] && (i == len(s)-1 || !mask[i+1]) {
			ans.WriteString("</b>")
		}
	}

	return ans.String()
}

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}
