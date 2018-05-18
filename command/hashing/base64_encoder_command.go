package hashing

import (
	"../../command"
	"encoding/base64"
	"bufio"
)

type Base64_encoder_command struct  {
	command.Stream_command
	reader bufio.Reader
	writer bufio.Writer
}

func (cmd Base64_encoder_command) SetReader(reader bufio.Reader)  {
	cmd.reader = reader
}

func (cmd Base64_encoder_command) SetWriter(writer bufio.Writer)  {
	cmd.writer = writer
}

func (cmd Base64_encoder_command) Execute() int  {
	//TODO: implement Reading/Writing for I/O
	rawString, _ := cmd.reader.ReadString('\n')
	encodedString := base64.StdEncoding.EncodeToString([]byte(rawString))
	cmd.writer.Write([]byte(encodedString))
	return 0
}
