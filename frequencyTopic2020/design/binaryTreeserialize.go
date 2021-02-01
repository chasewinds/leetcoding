package main

type TreeNode struct {
	Val int
	Left *TreeNode
	Right *TreeNode
}

type Codec struct {
    temp string
}

func Constructor() Codec {
        return Codec{}
}

// Serializes a tree to a single string.
func (this *Codec) serialize(root *TreeNode) string {
	if root == nil {
		return ""
	}
	this.preOrder(root)
    // fmt.Println("order: ", this.temp)
	return this.temp
}

func (this *Codec) preOrder(root *TreeNode) {
	if root == nil {
		this.temp += "null,"
		return
	}
	this.temp += strconv.Itoa(root.Val) + ","
	this.preOrder(root.Left)
	this.preOrder(root.Right)
}

// Deserializes your encoded data to tree.
func (this *Codec) deserialize(data string) *TreeNode {
	if data == ""  {
		return nil
	}
    root, _ := buildTree(data, 0)
	return root
}

func buildTree(data string, offset int) (*TreeNode, int) {

	if offset > len(data) - 1 {
		return nil, offset
	}
	tail := offset
	for tail < len(data) - 1 && data[tail] != ',' {
		tail++
	}
	if data[offset: tail] == "null" {
		return nil, tail + 1
	}
	number, _ := strconv.Atoi(data[offset: tail])
	node := &TreeNode{Val: number}
	node.Left, tail = buildTree(data, tail + 1)
	node.Right, tail = buildTree(data, tail)

	return node, tail
}


func main() {
	c := new(Codec)

	root := &TreeNode {Val: 1, Left: &TreeNode{Val: 2}, Right: &TreeNode{Val: 3, Left: &TreeNode{Val: 4}, Right: &TreeNode{Val: 5}}}
	
	serialized := c.serialize(root)
	fmt.Println("serialized", serialized)
	deserialized := c.deserialize(serialized)
}
