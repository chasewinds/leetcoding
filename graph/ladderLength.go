package main

// runtime 50.91%, memo 7.28%
func ladderLength(beginWord string, endWord string, wordList []string) int {

    var in bool
    for _, word := range wordList {
        if word == endWord {
            in = true
            break
        }
    }
    if !in {
        return 0
    }

    wordList = append(wordList, endWord)
    s2i := make(map[string][]int)
    for id, word := range wordList {
        for i := range word {
            sub := byteSub(word, i, '*')
            if _, found := s2i[sub]; !found {
                s2i[sub] = []int{id}
            } else {
                s2i[sub] = append(s2i[sub], id)
            }
        }
    }

    var q []string
    for i := range beginWord {
        sub := byteSub(beginWord, i, '*')
        q = append(q, sub)
    }

    res := 1
    visited := make(map[string]struct{})
    for len(q) > 0 {
        qsize := len(q)
        res++
        for i := 0; i < qsize; i++ {
            top := q[0]
            q = q[1:]
            if _, found := visited[top]; found {
                continue
            }
            visited[top] = struct{}{}
            if ids, found := s2i[top]; found {
                for _, id := range ids {
                    if id == len(wordList) - 1 {
                        return res
                    }
                    w := wordList[id]
                    for j := range w {
                        sub := byteSub(w, j, '*')
                        q = append(q, sub)
                    }
                }
            }
        }
    }

    return 0
}

func byteSub(s string, ri int, r byte) string {
  rr := []byte(s)
  rr[ri] = r
  return string(rr)
}
