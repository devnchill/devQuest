package main

import (
	"fmt"
)

func logMessages(chEmails, chSms chan string) {
	for {
		select {
		case valEmail, ok := <-chEmails:
			if !ok {
				return
			}
			logEmail(valEmail)
		case valSms, ok := <-chSms:
			if !ok {
				return
			}
			logSms(valSms)
		}
	}
}

func logSms(sms string) {
	fmt.Println("SMS:", sms)
}

func logEmail(email string) {
	fmt.Println("Email:", email)
}
