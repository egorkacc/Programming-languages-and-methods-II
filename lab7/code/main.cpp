#include "implementations.cpp"
#include "chessDesk.h"

int main(int argc, char *argv[])
{

	chessDesk chessGame;
	
	chessGame.ShowDesk();
	
	std::cout << std::endl << "total figures = " << chessGame.figures_count() << std::endl;
	
	system("pause");
	return 0;
}
