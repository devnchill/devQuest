package main

func getLast[T any](s []T) T {
	if len(s) == 0 {
		var val T
		return val
	}
	return s[len(s)-1]
}
