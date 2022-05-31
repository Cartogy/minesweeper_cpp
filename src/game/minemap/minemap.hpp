#include <iostream>
#include <vector>
#include "cell/cell.hpp"

class MineMap {
private:
	std::vector<std::vector<Cell>> cells;
	std::vector<std::vector<Cell>> start_cells(int x, int y);

	int x, y;
public:
	MineMap(int x, int y);
	void cell_selected(int x, int y, CellState a, bool is_bomb);
	CellState get_cell_state(int x, int y);
	void change_cell_state(int x, int y, CellState::cell_states c_state);
	void change_cell_state(int x, int y, CellState::cell_states c_state, int value);
	void print_map();
};
