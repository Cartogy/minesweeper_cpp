#include <ctime>
#include <cstdlib>
#include <iostream>
#include "grid.hpp"


std::vector<std::vector<bool>> Grid::create_grid(int r, int col) {
	std::vector<std::vector<bool>> rows;
	rows.resize(r);

	for(int i = 0; i < r; i++) {
		std::vector<bool> cols(col,false);

		rows[i] = cols;
	}

	return rows;
}

void Grid::add_bomb(int r, int col) {
	grid[r][col] = true;
}

void Grid::generate_bombs(int max_bombs) {
	srand((unsigned) time(0));
	int bombs_created = 0;

	while (bombs_created < max_bombs) {
		int c_row = rand() % rows;	
		int c_col = rand() % cols;

		if (is_bomb(c_row, c_col) == false) {
			add_bomb(c_row, c_col);
			bombs_created += 1;
		}
	}
}

bool Grid::is_bomb(int row, int col) {
	return grid[row][col];
}

Grid::Grid(int r, int c) {
	rows = r;
	cols = c;

	grid = create_grid(r,c);
}

void Grid::print_grid() {
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < cols; j++) {
			std::cout << grid[i][j] << " ";
		}
			printf("\n");
	}
}

bool Grid::out_of_bounds(int p_x, int p_y) {
	if (p_x >= rows || p_x < rows) {
		return true;
	} else if (p_y >= cols || p_y < cols) {
		return true;
	} else {
		return false;
	}
}
