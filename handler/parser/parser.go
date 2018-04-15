package parser

import (
	flag "github.com/ogier/pflag"
)

var (
	FlagMultiline bool
	FlagCount int
	Arguments []string
)

func Parse() {
	flag.BoolVarP(&FlagMultiline, "multiline", "m", false, "Parse input into multiple elements with delimiter")
	//TODO: Handle stripper functionality
	flag.Parse()
	FlagCount = flag.NFlag()
	Arguments = flag.Args()
}
