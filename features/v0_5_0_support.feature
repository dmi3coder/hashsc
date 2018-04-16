#noinspection CucumberUndefinedStep
Feature: support version v0.5.0
  In order to save user experience for previous users
  hashsc needs to support v0.5.0 full command compatibility

  Scenario: call hashsc with one arg
    Given "test" argument
    When I execute application
    Then there should be "dGVzdA==" output

  Scenario: call hashsc with two args "encode test"
    Given "encode", "test" arguments
    When I execute application
    Then there should be "dGVzdA==" output

  Scenario: call hashsc with two args "decode GVzdA=="
    Given "decode", "GVzdA==" arguments
    When I execute application
    Then there should be "test" output

  Scenario: call hashsc without args through pipe
    Given "test" pipeline input
    When I execute application
    Then there should be "dGVzdA==" output

  Scenario Outline: call hashsc with --ml flag and argument "test1\ntest2"
    Given <arg1>, <arg2> arguments
    When I execute application
    Then there should be two outputs: "dGVzdDE=", "dGVzdDI="

    Examples:
      | arg1 | arg2 |
      | "--ml" | "test1\ntest2" |
      |"test1\ntest2" | "--ml" |

  Scenario: call hashsc with --ml flag without args through pipe
    Given "--ml" flag and "test1\ntest2" pipeline input
    When I execute application
    Then there should be two outputs: "dGVzdDE=", "dGVzdDI="

