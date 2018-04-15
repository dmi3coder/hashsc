package main

import (
	"./handler/parser"
)

func main() {
	parser.Parse()
	if parser.FlagCount == 0 {
		//TODO: handle incoming stream
	} else {
		//TODO: handle flags
	}
}
