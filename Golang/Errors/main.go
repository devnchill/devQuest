package main

import (
	"errors"
	"fmt"
)

func main() {
	// fmt.Printf("%v", nil)
	// fmt.Print(getSMSErrorString(32, "AK"))
}

func sendSMSToCouple(msgToCustomer, msgToSpouse string) (int, error) {
	cost1, err1 := sendSMS(msgToCustomer)
	if err1 != nil {
		return 0, err1
	}
	cost2, err2 := sendSMS(msgToSpouse)
	if err2 != nil {
		return 0, err2
	}
	return cost1 + cost2, nil
}

func sendSMS(message string) (int, error) {
	const maxTextLen = 25
	const costPerChar = 2
	if len(message) > maxTextLen {
		return 0, fmt.Errorf("can't send texts over %v characters", maxTextLen)
	}
	return costPerChar * len(message), nil
}

func getSMSErrorString(cost float64, recipient string) string {
	return fmt.Sprintf("SMS that costs $%v to be sent to '%v' can not be sent", cost, recipient)
}

// type divideError struct {
// 	dividend float64
// }

// func (e divideError) Error() string {
// 	return fmt.Sprintf("can not divide %v by zero", e.dividend)
// }

func divide(dividend, divisor float64) (float64, error) {
	if divisor == 0 {
		err := errors.New("no dividing by 0")
		return 0, err
	}
	return dividend / divisor, nil
}

func maxMessages(thresh int) int {
	cost := 0
	var i int
	for i = 0; cost <= thresh; i++ {
		cost += 100 + i
	}
	return i - 1
}

func fizzbuzz() {
	i := 0
	for i = 0; i < 100; i++ {
		if i%3 == 0 {
			fmt.Println("fizz")
		}
		if i%5 == 0 {
			fmt.Println("buzz")
		}
		if i%3 == 0 && i%5 == 0 {
			fmt.Println("fizzbuzz")
		}
		fmt.Println(i)
	}
}
