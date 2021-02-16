package main

type UnionFind struct {
    parent []int
}

func (uf *UnionFind) Find(x int) int {
    // if x != uf.parent[x] {
    //     uf.parent[x] = uf.Find(uf.parent[x])
    // }
    for x != uf.parent[x] {
        uf.parent[x] = uf.parent[uf.parent[x]]
        x = uf.parent[x]
    }
    return uf.parent[x]
}

func (uf *UnionFind) Union(x, y int) {
    // rootX := uf.Find(x)
    // rootY := uf.Find(y)
    // if rootX != rootY {
    //     uf.parent[x] = rootY
    // }
    uf.parent[uf.Find(x)] = uf.Find(y)
}

func NewUnionFind() *UnionFind {
    p := make([]int, 26)
    for i := range p {
        p[i] = i
    }
    return &UnionFind {
        parent: p,
    }
}

func equationsPossible(equations []string) bool {

    uf := NewUnionFind()
    for _, e := range equations {
        if e[1:3] == "==" {
            // fmt.Println("0", int(e[0] - 'a'), "3", int(e[3] - 'a'))
            uf.Union(int(e[0] - 'a'), int(e[3] - 'a'))
        }
    }
    // for i, x := range uf.parent {
    //     fmt.Println(i, ":", x)
    // }

    for _, e := range equations {
        if e[1:3] == "!=" {
            // fmt.Println("x", e[0] - 'a', "y", e[3] - 'a')
            p1 := uf.Find(int(e[0] - 'a'))
            p2 := uf.Find(int(e[3] - 'a'))
            // fmt.Println("p1", p1, "p2", p2)
            if p1 == p2 {
                return false
            }
        }
    }

    return true
}
