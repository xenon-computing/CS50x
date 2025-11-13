import subprocess
from argparse import ArgumentParser

# Creating a parser for command parsing
cmd_parser = ArgumentParser(
        description="Command-Line utility for testing Binary File with test cases")

cmd_parser.add_argument("-b", "--bin",
                        help="Flag to input binary file for testing",
                        type=str)

cmd_parser.parse_args()
