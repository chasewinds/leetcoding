package main

type CQueue struct {
	in  []int
	out []int
}

func Constructor() CQueue {
	return CQueue{}
}

func (this *CQueue) AppendTail(value int) {
	this.in = append(this.in, value)
}

func (this *CQueue) DeleteHead() int {

	if len(this.in) == 0 && len(this.out) == 0 {
		return -1
	}
	if len(this.out) == 0 {
		for len(this.in) > 0 {
			top := this.in[len(this.in)-1]
			this.out = append(this.out, top)
			this.in = this.in[:len(this.in)-1]
		}
	}

	head := this.out[len(this.out)-1]
	this.out = this.out[:len(this.out)-1]
	return head
}

/**
 * Your CQueue object will be instantiated and called as such:
 * obj := Constructor();
 * obj.AppendTail(value);
 * param_2 := obj.DeleteHead();
 */
