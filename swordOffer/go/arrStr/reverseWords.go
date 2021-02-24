package main

func reverseWords(s string) string {

	if s == "" {
		return ""
	}

	p := 0
	for ; p < len(s) && s[p] == ' '; p++ {
	}
	e := len(s) - 1
	for ; e > p && s[e] == ' '; e-- {
	}

	var ret []byte
	i := e
	for i >= p {
		j := i
		for ; j >= p && s[j] != ' '; j-- {
		}
		for x := j + 1; x <= i; x++ {
			ret = append(ret, s[x])
		}
		for j >= p && s[j] == ' ' {
			j--
		}
		if j >= p {
			// fmt.Println("j, p", j, p)
			ret = append(ret, ' ')
		}
		i = j
	}

	return string(ret)
}
