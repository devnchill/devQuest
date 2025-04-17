package main

func indexOfFirstBadWord(msg []string, badWords []string) int {
	for i, message := range msg {
		for _, bw := range badWords {
			if message == bw {
				return i
			}
		}
	}
	return -1
}
