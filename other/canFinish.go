package main

// build graph using pure id
func ladderLength(beginWord string, endWord string, wordList []string) int {

	word2id := make(map[string]int)
	virtual2id := make(map[string]int)
	id := 1
	for _, word := range wordList {
		word2id[word] = id
		id++
		for i := range word {
			virtual := replaceStr(word, i, '*')
			if _, found := virtual2id[virtual]; !found {
				virtual2id[virtual] = id
				id++
			}
		}
	}
	if _, found := word2id[endWord]; !found {
		return 0
	}
	word2id[endWord] = id
	id++

	// graph, id-id conn is most effective
	graph := make([][]int, id)
	for _, word := range wordList {
		for i := range word {
			wid := word2id[word]
			vid := virtual2id[replaceStr(word, i, '*')]
			graph[wid] = append(graph[wid], vid)
			graph[vid] = append(graph[vid], wid)
		}
	}

	var q []int
	for i := range beginWord {
		if id, found := virtual2id[replaceStr(beginWord, i, '*')]; found {
			q = append(q, id)
		}
	}

	target := make(map[int]struct{})
	for i := range endWord {
		target[virtual2id[replaceStr(endWord, i, '*')]] = struct{}{}
	}
	visited := make([]bool, id)

	res := 1
	for len(q) > 0 {
		qsize := len(q)
		res++
		for i := 0; i < qsize; i++ {
			top := q[0]
			q = q[1:]
			visited[top] = true
			if _, found := target[top]; found {
				return res/2 + 1
			}
			for _, id := range graph[top] {
				if !visited[id] {
					q = append(q, id)
				}
			}
		}
	}

	return 0
}

func replaceStr(s string, i int, b byte) string {
	bs := []byte(s)
	bs[i] = b
	return string(bs)
}

/*
func canFinish(numCourses int, prerequisites [][]int) bool {
	var (
		edges  = make([][]int, numCourses)
		degree = make([]int, numCourses)
		count  int
	)

	for _, p := range prerequisites {
		from, to := p[0], p[1]
		edges[from] = append(edges[from], to)
		degree[to]++
	}

	var q []int
	for i := range edges {
		if degree[i] == 0 {
			q = append(q, i)
		}
	}

	for len(q) != 0 {
		qsize := len(q)
		for i := 0; i < qsize; i++ {
			top := q[0]
			q = q[1:]
			count++
			for _, p := range edges[top] {
				degree[p]--
				if degree[p] == 0 {
					q = append(q, p)
				}
			}
		}
	}

	return count >= numCourses
}
*/
