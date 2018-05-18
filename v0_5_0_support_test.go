package main

import (
	"github.com/DATA-DOG/godog"
)

func argument(arg1 string) error {
	return godog.ErrPending
}

func arguments(arg1, arg2 string) error {
	return godog.ErrPending
}

func flagAndPipelineInput(arg1, arg2 string) error {
	return godog.ErrPending
}

func pipelineInput(arg1 string) error {
	return godog.ErrPending
}

func iExecuteApplication() error {
	return godog.ErrPending
}

func thereShouldBeOutput(arg1 string) error {
	return godog.ErrPending
}


func thereShouldBeTwoOutputs(arg1, arg2 string) error {
	return godog.ErrPending
}

func FeatureContext(s *godog.Suite) {
	s.Step(`^"([^"]*)" argument$`, argument)
	s.Step(`^I execute application$`, iExecuteApplication)
	s.Step(`^there should be "([^"]*)" output$`, thereShouldBeOutput)
	s.Step(`^"([^"]*)", "([^"]*)" arguments$`, arguments)
	s.Step(`^"([^"]*)" pipeline input$`, pipelineInput)
	s.Step(`^there should be two outputs: "([^"]*)", "([^"]*)"$`, thereShouldBeTwoOutputs)
	s.Step(`^"([^"]*)" flag and "([^"]*)" pipeline input$`, flagAndPipelineInput)

}
