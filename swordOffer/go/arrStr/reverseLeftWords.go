package main

func reverseLeftWords(s string, n int) string {
	s += s[:n]
	return s[n:]
}
