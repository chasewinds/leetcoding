package main

func addStrings(num1 string, num2 string) string {

    if len(num1) == 0 {
        return num2
    }
    if len(num2) == 0 {
        return num1
    }

    p1 := len(num1) - 1
    p2 := len(num2) - 1
    up := 0
    var res string
    for p1 >= 0 || p2 >= 0 || up > 0 {
        sum := up
        if p1 >= 0 {
            sum += int(num1[p1] - '0')
            p1--
        }
        if p2 >= 0 {
            sum += int(num2[p2] - '0')
            p2--
        }
        if sum >= 10 {
            up = sum / 10
            sum %= 10
        } else {
            up = 0
        }
        res = string([]byte{byte(sum + '0')}) + res
    }

    return res
}
