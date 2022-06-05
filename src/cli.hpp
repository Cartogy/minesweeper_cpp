#include "game/game.hpp"
#include <functional>
#include <map>

#define print(x) std::cout << x << std::endl

class CLI {

private:
	std::vector<std::string> tokenize(std::string input);
	MineSweeper::actions parse_input(const std::string input);
	bool valid_input(std::vector<std::string> input);
	bool is_number(const std::string& s);

	const static std::map<std::string, MineSweeper::actions> commands_actions;

	MineSweeper game;
public:
	CLI(int x, int y, int max_bombs);
	void run();
	void show_board();
};

void cliRun();
