#include "minemap.hpp"

MineMap::MineMap(int p_x, int p_y) {
	cells = start_cells(p_x, p_y);

	x = p_x;
	y = p_y;

}

std::vector<std::vector<Cell>>MineMap::start_cells(int x, int y) {
	std::vector<std::vector<Cell>> cells;

	// Go over row
	for(int i = 0; i < x; i++) {
		std::vector<Cell> cell_row;

		// Go over columns 
		for(int j = 0; j < y; j++) {
			Cell c_cell(i,j);
			cell_row.push_back(c_cell);
		}

		cells.push_back(cell_row);
	}

	return cells;
}

CellState MineMap::get_cell_state(int x, int y) {
	Cell c = cells[x][y];

	return c.get_state();

}

void MineMap::print_map() {
	// print column header
	std::cout << "    ";
	for (int j = 0; j < y; j++) {
		std::cout << j ;
	}

	std::cout << std::endl;
	for(int i = 0; i < x; i++) {
		// print row number
		std::cout << i << " - ";
		for(int j = 0; j < y; j++) {
			int s = cells[i][j].get_state().state;
			std::cout << s;
		}
		std::cout << std::endl;
	}
}

void MineMap::change_cell_state(int x, int y, CellState::cell_states c_state) {
	cells[x][y].change_state(c_state);

}

void MineMap::change_cell_state(int x, int y, CellState::cell_states c_state, int value) {
	cells[x][y].change_state(c_state, value);

}
