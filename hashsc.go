package main

import "os"

func main() {
	args := os.Args
	for e := range args {
		println(args[e])
	}
}
