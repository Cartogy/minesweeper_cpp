#include "cell_state.hpp"

class Cell {
private:
	int x, y;
	CellState cell_state;
public:
	void change_state(CellState::cell_states s) {
		cell_state.change_state(s);
	}

	void change_state(CellState::cell_states s, int x) {
		cell_state.change_state(s);
		cell_state.add_value(x);
	}

	CellState get_state() {
		return cell_state;
	}

	int get_value() {
		if (get_state().state == CellState::cell_states::Value) {
			return cell_state.get_value();
		} else {
			return -1;
		}
	}

	Cell(int p_x, int p_y) {
		x = p_x;
		y = p_y;

		cell_state = CellState();
	}

};
