//go:build ignore

package main

import "errors"

func getUserMap(names []string, phoneNumbers []int) (map[string]user, error) {
	m := make(map[string]user)
	if len(names) != len(phoneNumbers) {
		return nil, errors.New("invalid sizes")
	}
	for i, name := range names {
		phoneNumber := phoneNumbers[i]
		m[name] = user{
			name:        name,
			phoneNumber: phoneNumber,
		}
	}
	return m, nil
}

type user struct {
	name        string
	phoneNumber int
}
