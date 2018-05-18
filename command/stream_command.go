package command

import (
	"bufio"
)
type Stream_command interface {
	Command
	SetReader(reader bufio.Reader)
	SetWriter(writer bufio.Writer)
}
