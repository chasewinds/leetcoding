package main

import "strings"

/*
func replaceSpace(s string) string {
	if s == "" {
		return ""
	}

	var res string
	for i := range s {
		if s[i] == ' ' {
			res += "%20"
		} else {
			res += string([]byte{s[i]})
		}
	}

	return res
}
*/

func replaceSpace(s string) string {

	var b strings.Builder
	for i := range s {
		if s[i] == ' ' {
			b.WriteString("%20")
		} else {
			b.WriteByte(s[i])
		}
	}

	return b.String()
}
