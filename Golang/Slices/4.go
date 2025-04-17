package main

func sum(nums ...int) int {
	var sum int = 0
	for i := 0; i < len(nums); i++ {
		sum += nums[i]
	}
	return sum
}
