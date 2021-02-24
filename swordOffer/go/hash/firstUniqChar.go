package main

func firstUniqChar(s string) byte {
	b2f := make(map[byte]int)
	for i := range s {
		b2f[s[i]]++
	}
	for i := range s {
		f := b2f[s[i]]
		if f == 1 {
			return s[i]
		}
	}

	return ' '
}
