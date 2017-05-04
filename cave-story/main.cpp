#include "Windows.h" // Needed for OutputDebugString (can be removed when finished)
#include "game.h"
#undef main

int main(int argc, const char *argv[]) {
	Game game;

	OutputDebugString("test?\n");
	return 0;
}