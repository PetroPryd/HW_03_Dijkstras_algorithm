#include <iostream>
#include <thread>
#include <chrono>

int main() {
	int row = 20;
	int column = 40;
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

	bool complete = false;
	while (!complete) {
		for (int i = 1; i <= row; i++)
		{
			for (int j = 1; j <= column; j++)
			{
				if (p_A_x == j && p_A_y == i)
					std::cout << 'A';
				else if (p_B_x == j && p_B_y == i)
					std::cout << 'B';
				else
					std::cout << '-';
			}
			std::cout << std::endl;
		}
		if (p_A_x < p_B_x) 
			p_A_x++;
		else if (p_A_x > p_B_x)
			p_A_x--;
		else if (p_A_y < p_B_y)
			p_A_y++;
		else if (p_A_y > p_B_y)
			p_A_y--;

		if (p_A_x == p_B_x && p_A_y == p_B_y) {
			complete = true;
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		system("cls");
	}

	return 0;
}