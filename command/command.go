package command

const CMD_CONVERT_STREAM = "CMD_CONVERT_STREAM"
const CMD_ENCODE = "CMD_ENCODE"
const CMD_MULTILINE_ENCODE = "CMD_MULTILINE_ENCODE"

type command interface {
	Execute() int
}
