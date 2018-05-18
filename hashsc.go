package main

import (
	"./handler/parser"
	"./command/hashing"
	"./command"
	"encoding/base64"
	"os"
	"bufio"
)

func main() {
	parser.Parse()
	if parser.FlagCount == 0 {
		var cmd command.Command = hashing.Base64_encoder_command{}
		if cmd_stream := cmd.(command.Stream_command); cmd_stream != nil {
			cmd_stream.SetReader(*bufio.NewReader(os.Stdin))
			cmd_stream.SetWriter(*bufio.NewWriter(os.Stdout))
		}
		cmd.Execute()
	} else {
		response := base64.StdEncoding.EncodeToString([]byte(parser.Arguments[0]))
		println(response)
	}
}
