package main

/*
// runtime 100.00%, memo 45.65% (rec)
func numIslands(grid [][]byte) int {

    if len(grid) == 0 || len(grid[0]) == 0 {
        return 0
    }

    var bfs func(grid [][]byte, i, j int)
    bfs = func(grid [][]byte, i, j int) {
        grid[i][j] = '0'
        if i - 1 >= 0 && grid[i - 1][j] == '1' {
            bfs(grid, i - 1, j)
        }
        if j - 1 >= 0 && grid[i][j - 1] == '1' {
            bfs(grid, i, j - 1)
        }
        if i + 1 < len(grid) && grid[i + 1][j] == '1' {
            bfs(grid, i + 1, j)
        }
        if j + 1 < len(grid[0]) && grid[i][j + 1] == '1' {
            bfs(grid, i, j + 1)
        }
    }

    var res int
    for i := 0; i < len(grid); i++ {
        for j := 0; j < len(grid[0]); j++ {
            if grid[i][j] == '1' {
                res++
                bfs(grid, i, j)
            }
        }
    }

    return res
}
*/

// 不带秩的并查集, 比带秩的合并稍微查一丢丢
type UnionFind struct {
    parent []int
    nums int
}

func (uf *UnionFind) Find(x int) int {
    if x != uf.parent[x] {
        return uf.Find(uf.parent[x])
    }
    return x
}

func (uf *UnionFind) Union(x, y int) {
    rootX := uf.Find(x)
    rootY := uf.Find(y)
    if rootX != rootY {
        uf.parent[rootY] = rootX
        uf.nums--
    }
}

func (uf *UnionFind) Nums() int {
    return uf.nums
}

func NewUnionFind(grid [][]byte) *UnionFind {
    size := len(grid) * len(grid[0])
    p := make([]int, size)
    var count int
    for i := 0; i < len(grid); i++ {
        for j := 0; j < len(grid[0]); j++ {
            idx := i * len(grid[0]) + j
            p[idx] = idx
            if grid[i][j] == '1' {
                count++
            }
        }
    }
    return &UnionFind{
        parent: p,
        nums: count,
    }
}

func numIslands(grid [][]byte) int {

    if len(grid) == 0 || len(grid[0]) == 0 {
        return 0
    }

    uf := NewUnionFind(grid)
    for i := 0; i < len(grid); i++ {
        for j := 0; j < len(grid[0]); j++ {
            if grid[i][j] == '1' {
                idx := i * len(grid[0]) + j
                if i - 1 >= 0 && grid[i - 1][j] == '1' {
                    uf.Union(idx, (i - 1) * len(grid[0]) + j)
                }
                if j - 1 >= 0 && grid[i][j - 1] == '1' {
                    uf.Union(idx, i * len(grid[0]) + j - 1)
                }
                if i + 1 < len(grid) && grid[i + 1][j] == '1' {
                    uf.Union(idx, (i + 1) * len(grid[0]) + j)
                }
                if j + 1 < len(grid[0]) && grid[i][j + 1] == '1' {
                    uf.Union(idx, i * len(grid[0]) + j + 1)
                }
            }
        }
    }

    return uf.Nums()
}
