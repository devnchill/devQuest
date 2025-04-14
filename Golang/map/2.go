//go:build ignore

package main

import "errors"

func deleteIfNecessary(users map[string]user, name string) (deleted bool, err error) {
	if _, ok := users[name]; !ok {
		return false, errors.New("not found")
	}
	if users[name].scheduledForDeletion {
		delete(users, name)
		return true, nil
	}
	return false, nil
}

type user struct {
	name                 string
	number               int
	scheduledForDeletion bool
}
