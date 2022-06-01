# About

Implements Minesweeper.

# Architecture

THe software is designed into the following components:
* MineMap - Contains the view data to be used by an interface
* Grid - Contains the data about the location of the bombs

The **MineSweeper** object consists of both *MineMap* and *Grid* object.
It expects *actions* upon which it changes the **MineMap**'s view based 
on the *Grid* data.

## Interface
Currently only the CLI interface is implemented.

The CLI interface consists of the **MineSweeper** object.
It parses the input from the terminal and converts the input into
the *actions* of **MineSweeper**.

This allows multiple types of interfaces without changing the logic of the game.
