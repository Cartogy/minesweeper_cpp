#include <vector>

class Grid {
	private:
		int rows;
		int cols;
		std::vector<std::vector<bool>> grid;

		void add_bomb(int r, int col);
		std::vector<std::vector<bool>> create_grid(int r, int col);

	public:
		Grid(int r, int c);
		bool is_bomb(int row, int col);
		void generate_bombs(int max_bombs);
		void print_grid();

		bool out_of_bounds(int p_x, int p_y);

};
