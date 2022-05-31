struct CellState {
	enum cell_states {Closed, Value, Flag, Bomb, Question};
	cell_states state;

	int value;

	void change_state(cell_states s) {
		state = s;
	}

	void add_value(int x) {
		value = x;
	}

	int get_value() {
		return value;
	}

	CellState() {
		state = cell_states::Closed;
		value = 0;
	}

};

