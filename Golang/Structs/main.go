package main

import "fmt"

func main() {
	// auth := authenticationInfo{
	// 	username: "test",
	// 	password: "23",
	// }
	// fmt.Println(auth.getBasicAuth())
}

type messageToSend struct {
	message   string
	sender    user
	recipient user
}

type user struct {
	name   string
	number int
}

func canSendMessage(mToSend messageToSend) bool {
	return mToSend.sender.name != "" &&
		mToSend.sender.number != 0 &&
		mToSend.recipient.name != "" &&
		mToSend.recipient.number != 0
}

type sender struct {
	user
	rateLimit int
}

type authenticationInfo struct {
	username string
	password string
}

func (a authenticationInfo) getBasicAuth() string {
	return fmt.Sprintf("Authorization: Basic %s:%s", a.username, a.password)
}

type contact struct {
	userID       string
	sendingLimit int32
	age          int32
}

type perms struct {
	canSend         bool
	canReceive      bool
	canManage       bool
	permissionLevel int
}
