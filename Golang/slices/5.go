package main

type cost struct {
	day   int
	value float64
}

func getDayCosts(costs []cost, day int) []float64 {
	res := []float64{}
	for i := range costs {
		if costs[i].day == day {
			res = append(res, costs[i].value)
		}
	}
	return res
}
