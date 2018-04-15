package main

import (
	"./handler/parser"
	"encoding/base64"
)

func main() {
	parser.Parse()
	if parser.FlagCount == 0 {
		//TODO: handle incoming stream
	} else {
		response := base64.StdEncoding.EncodeToString([]byte(parser.Arguments[0]))
		println(response)
	}
}
