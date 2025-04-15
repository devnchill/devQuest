//go:build ignore

package main

import "fmt"

type Message struct {
	Recipient string
	Text      string
}

func getMessageText(m Message) string {
	return fmt.Sprintf(`
To: %v
Message: %v
`, *(&m.Recipient), *(&m.Text))
}

func main() {
	msg := Message{
		Recipient: "a",
		Text:      "this is a test",
	}
	fmt.Println(getMessageText(msg))
}
