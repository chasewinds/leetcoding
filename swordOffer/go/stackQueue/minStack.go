package main

type node struct {
	val    int
	curMin int
}

type MinStack struct {
	stk []node
}

/** initialize your data structure here. */
func Constructor() MinStack {
	return MinStack{}
}

func (this *MinStack) Push(x int) {
	if len(this.stk) == 0 {
		this.stk = append(this.stk, node{x, x})
		return
	}
	this.stk = append(this.stk, node{x, min(x, this.stk[len(this.stk)-1].curMin)})
}

func (this *MinStack) Pop() {
	if len(this.stk) == 0 {
		return
	}
	this.stk = this.stk[:len(this.stk)-1]
}

func (this *MinStack) Top() int {
	if len(this.stk) == 0 {
		return -1
	}
	return this.stk[len(this.stk)-1].val
}

func (this *MinStack) Min() int {
	if len(this.stk) == 0 {
		return -1
	}
	return this.stk[len(this.stk)-1].curMin
}

func min(x, y int) int {
	if x > y {
		return y
	}
	return x
}

/**
 * Your MinStack object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(x);
 * obj.Pop();
 * param_3 := obj.Top();
 * param_4 := obj.Min();
 */
