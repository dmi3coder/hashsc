package command

import "io"

type stream_command interface {
	command
	setReader(reader io.Reader)
	setWriter(writer io.Writer)
}
