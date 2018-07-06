

#include "TesterGame.h"
#include <stdexcept>
#include <fstream>
#include <iostream>

//for memory leaks
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifdef _WIN32
#include <windows.h>

void sleep( unsigned milliseconds )
{
	Sleep( milliseconds );
}
#else
#include <unistd.h>

void sleep( unsigned milliseconds )
{
	usleep( milliseconds * 1000 ); // takes microseconds
}
#endif

int main(int argc, char** argv)
{
	TesterGame testGame;
	//auto compile shaders, temp solution, this needs to be changed on a different machine/configuration!!!!!
	system( "D:\\BeamDogVulkan\\BeamDogVulkan\\TesterGame\\Shaders\\compile.bat" );
	
	
	try
	{
		testGame.Run();
	}
	catch (const std::runtime_error& e)
	{
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}