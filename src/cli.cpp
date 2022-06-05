#include "cli.hpp"
#include <cctype>
#include <sstream>

const std::map<std::string, MineSweeper::actions> CLI::commands_actions = {
	{"select",MineSweeper::actions::CELL_SELECT},
	{"flag",MineSweeper::actions::FLAG},
	{"question",MineSweeper::actions::QUESTION},
	{"clear",MineSweeper::actions::QUESTION}
};

CLI::CLI(int x, int y, int max_bombs) : game(x, y, max_bombs){ }

void CLI::run() {
	std::string command;
	while( game.is_game_over() == false) {
		show_board();
		std::cout << "Enter Command: " << std::endl;

		getline(std::cin, command);

		std::vector<std::string> toks = tokenize(command);

		if (valid_input(toks)) {
			// Parse input to action
			MineSweeper::actions current_action = parse_input(toks[0]);
			// Have game change state based on cell
			game.select_cell(std::stoi(toks[1]), std::stoi(toks[2]), current_action);
		} else {
			std::cout << "Invalid Input. Please enter again" << std::endl;
		}
	}

	if (game.lost()) {
		std::cout << "You lost" << std::endl;
	} else if (game.won()) {
		std::cout << "You won" << std::endl;
	}
}

std::vector<std::string> CLI::tokenize(std::string input) {

	std::stringstream ss;
	ss << input;
	std::string word;

	std::vector<std::string> tokens;
	while(ss >> word) {
		std::string tok = word;

		tokens.push_back(tok);
	}

	return tokens;

}

MineSweeper::actions CLI::parse_input(const std::string input) {
	return commands_actions.at(input); 

}

bool CLI::valid_input(std::vector<std::string> input) {
	if (input.size() == 3) {
		std::string x = input[1];
		std::string y = input[2];

		if (is_number(x) && is_number(y)) {
			return true;
		}

	}

	return false;
}

bool CLI::is_number(const std::string& s) {
	for (char const &c : s) {
		if (std::isdigit(c) == false) {
			return false;
		}
	}

	return true;

}

void CLI::show_board() {
	int rows = game.get_rows();
	int cols = game.get_cols();

	for(int x = 0; x < rows; x++) {
		for(int y = 0; y < cols; y++) {
			CellState c = game.get_cell_state(x, y);

			switch(c.state){
				case CellState::cell_states::Closed:
					std::cout << "-";
					break;
				case CellState::cell_states::Bomb:
					std::cout << "!";
					break;
				case CellState::cell_states::Flag:
					std::cout << "F";
					break;
				case CellState::cell_states::Question:
					std::cout << "?";
					break;
				case CellState::cell_states::Value:
					int val = c.get_value();
					std::cout << val ;
					break;
			}
		}
		std::cout << std::endl;
	}

	//game.show_bombs();

}

void cliRun(){
	int rows;
	int cols;
	int opt;

	print("Choose Grid Layout ");
	print("  1. 4x4");
	print("  2. 8x8");
	print("  3. 12x12");
	print("  4. 16x16");
	print("  5. Coustom");
	print("  ");
	print("  6. EXIT");

	std::cout << "  -- ";
	std::cin >> opt;

	switch (opt)
	{
	case 1:
		rows = 4;
		cols = 4;
		break;
	case 2:
		rows = 8;
		cols = 8;
		break;
	case 3:
		rows = 12;
		cols = 12;
		break;
	case 4:
		rows = 16;
		cols = 16;
		break;
	case 5:
		print(" ");
		std::cout << "Enter Number Of Rows:- ";
		std::cin>>rows;
		std::cout << "Enter NUmber Of Columns;- ";
		std::cin>>cols;

		if(rows <= 3) {rows = 4;}
		if(cols <= 3) {cols = 4;}
		if(rows >= 65) {rows = 64;}
		if(cols >= 65) {cols = 64;}
		
		break;
	case 6:
		print("GoodBye!");
		std::system("exit");
	
	default:
		rows = 8;
		cols = 8;
		break;
	}

	std::cin.ignore();
	std::system("clear");

	CLI minesweeper_cli(rows,cols,int(rows*cols*0.23)); // 23% of all places will be occupied by mines
	minesweeper_cli.run();
}
