package main

func isPalindrome(s string) bool {
    if len(s) == 0 {
        return true
    }
    s = strings.ToLower(s)
    i, j := 0, len(s) - 1
    for i < j {
        for !valid(s[i]) && i < j {
            i++
        }
        for !valid(s[j]) && i < j {
            j--
        }
        if i < j {
            if s[i] != s[j] {
                // fmt.Println("s[i]", s[i], "s[j]", s[j])
                return false
            }
            i++
            j--
        }
    }
    return true
}

func valid(b byte) bool {
    return (b >= 'a' && b <= 'z') || (b >= 'A' && b <= 'Z') || (b >= '0' && b <= '9')
}
