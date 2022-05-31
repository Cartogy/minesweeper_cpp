#include "minemap/minemap.hpp"
#include "grid/grid.hpp"

class MineSweeper {
private:
	struct Direction {
		int x;
		int y;

		Direction(int dir_x, int dir_y) {
			x = dir_x;
			y = dir_y;
		}
	};

	// state of the game
	enum game_state {MENU, PLAYING, GAME_OVER};
	game_state current_state;

	// Main components that it interacts with
	Grid grid;
	MineMap mine_map;

	bool is_bomb(int x, int y);
	int nearby_bombs(int x, int y);

	int rows;
	int cols;

	// Directions for checking a cell's nearby bombs
	const static std::vector<Direction> directions;
public:
	enum actions {CELL_SELECT, FLAG, QUESTION, CLEAR};
	MineSweeper(int x, int y, int max_bombs);

	// Request command inputs
	void select_cell(int x, int y, actions a);
	CellState get_cell_state(int x, int y);

	game_state get_state();
	bool is_game_over();
	void print_mine_view();

	int get_rows();
	int get_cols();
};
