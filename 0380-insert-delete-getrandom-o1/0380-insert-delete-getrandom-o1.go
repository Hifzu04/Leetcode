type RandomizedSet struct {
	nums []int
	mp   map[int]int // value -> index
}

func Constructor() RandomizedSet {
	return RandomizedSet{
		nums: []int{},
		mp:   make(map[int]int),
	}
}

func (this *RandomizedSet) Insert(val int) bool {
	if _, exists := this.mp[val]; exists {
		return false
	}

	this.nums = append(this.nums, val)
	this.mp[val] = len(this.nums) - 1
	return true
}

func (this *RandomizedSet) Remove(val int) bool {
	index, exists := this.mp[val]
	if !exists {
		return false
	}

	last := this.nums[len(this.nums)-1]

	// Move last element to removed position
	this.nums[index] = last
	this.mp[last] = index

	// Remove last element
	this.nums = this.nums[:len(this.nums)-1]
	delete(this.mp, val)

	return true
}

func (this *RandomizedSet) GetRandom() int {
	index := rand.Intn(len(this.nums))
	return this.nums[index]
}