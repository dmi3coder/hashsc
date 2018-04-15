package parser

import (
	flag "github.com/ogier/pflag"
)

var (
	FlagMultiline bool
	FlagCount int
)

func Parse() {
	flag.BoolVarP(&FlagMultiline, "multiline", "m", false, "Parse input into multiple elements with delimiter")
	flag.Parse()
	FlagCount = flag.NFlag()

}
