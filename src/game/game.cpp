#include "game.hpp"

const std::vector<MineSweeper::Direction> MineSweeper::directions = 
{ MineSweeper::Direction(1,1), MineSweeper::Direction(-1,-1),MineSweeper::Direction(0,-1), MineSweeper::Direction(0, 1), MineSweeper::Direction(1,0), MineSweeper::Direction(-1,0),MineSweeper::Direction(-1,1),MineSweeper::Direction(1,-1)};

MineSweeper::MineSweeper(int x, int y, int max_bombs) : grid(x,y), mine_map(x,y){
	current_state = game_state::MENU;
	grid.generate_bombs(max_bombs);

	rows = x;
	cols = y;
}

MineSweeper::game_state MineSweeper::get_state() {
	return current_state;
}

// TODO
void MineSweeper::select_cell(int x, int y, actions a) {
	switch (a) {
		case actions::CELL_SELECT:
			if (grid.is_bomb(x, y)) {
				std::cout << "BOMB" << std::endl;
				// Bomb!!
				current_state = game_state::GAME_OVER;
				mine_map.change_cell_state(x, y, CellState::cell_states::Bomb );
			} else {
				// Show value of bombs around, if any.	
				int bombs = nearby_bombs(x, y);
				mine_map.change_cell_state(x, y, CellState::cell_states::Value, bombs );

				std::cout << "Not a Bomb" << std::endl;
			}
			break;
		case actions::CLEAR:
			mine_map.change_cell_state(x, y, CellState::cell_states::Closed);
			break;
		case actions::FLAG:
			mine_map.change_cell_state(x, y, CellState::cell_states::Flag);
			break;
		case actions::QUESTION:
			mine_map.change_cell_state(x, y, CellState::cell_states::Question);
			break;
		default:
			break;
	}
}

bool MineSweeper::is_game_over() {
	return current_state == game_state::GAME_OVER;
}

bool MineSweeper::is_bomb(int x, int y) {
	return grid.is_bomb(x, y);
}

int MineSweeper::nearby_bombs(int x, int y) {
	int bombs = 0;

	// repate until no more directions
	for(int i = 0; i < directions.size(); i++) {
		Direction c_dir = directions[i];

		// update next_x and next_y
		int next_x = x + c_dir.x;
		int next_y = y + c_dir.y;

		if (grid.out_of_bounds(next_x, next_y) == false) {
			bombs = grid.is_bomb(next_x, next_y) ? (1 + bombs) : bombs;
		}
	}

	return 0;
}

void MineSweeper::print_mine_view() {
	mine_map.print_map();
}

CellState MineSweeper::get_cell_state(int x, int y) {

	return mine_map.get_cell_state(x,y);
}

int MineSweeper::get_rows() {
	return rows;	
}

int MineSweeper::get_cols() {
	return cols;	
}
