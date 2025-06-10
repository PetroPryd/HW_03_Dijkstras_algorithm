#include <iostream>
#include <thread>
#include <chrono>
#include <vector>

int main() {
	const int row = 20;
	const int column = 40;
	int p_A_x, p_A_y;
	int p_B_x, p_B_y;

	std::cout << "Enter x of A: ";
	std::cin >> p_A_x;
	std::cout << "Enter y of A: ";
	std::cin >> p_A_y;
	std::cout << "Enter x of B: ";
	std::cin >> p_B_x;
	std::cout << "Enter y of B: ";
	std::cin >> p_B_y;

	char map[row][column];

	const char obstacle = '*';

	bool complete = false;

	int obstacle_length = 13;
	int obstacle_column = 5;

	bool obstacle_lenght_done = false;

	// Entity map[row][column];
	// Entity {x, y, char)

	// Entity player ()

	while (!complete) {
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		system("cls");
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < column; j++)
			{
				map[i][j] = '-';

				if(j == obstacle_column && i < obstacle_length)
					map[i][j] = obstacle;

				if (p_A_x == j && p_A_y == i)
					map[i][j] = 'A';
				if (p_B_x == j && p_B_y == i)
					map[i][j] = 'B';
			}
		}

		// draw
		
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < column; j++)
			{
				std::cout << map[i][j];
			}
			std::cout << std::endl;
		}

		if (obstacle_length > p_A_y && !obstacle_lenght_done) 
			p_A_y++;
		else if (obstacle_column < p_A_x && p_A_x != p_B_x) {
			p_A_x++;
			obstacle_lenght_done = true;
		}
		else {
			obstacle_lenght_done = true;
			if (p_A_x < p_B_x && map[p_A_y][p_A_x + 1] != obstacle)
				p_A_x++;
			else if (p_A_x > p_B_x && map[p_A_y][p_A_x - 1] != obstacle)
				p_A_x--;
			else if (p_A_y < p_B_y && map[p_A_y + 1][p_A_x] != obstacle)
				p_A_y++;
			else if (p_A_y > p_B_y && map[p_A_y - 1][p_A_x] != obstacle)
				p_A_y--;
		}

		if (p_A_x == p_B_x && p_A_y == p_B_y) {
			complete = true;
		}
	}

	return 0;
}