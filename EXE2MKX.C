#include "MknLib.H"

int main(int argc, char *argv[])
{
	if (argc != 2) {
		return 0;
	}
	mkxcrt(argv[1]);
	remove(argv[1]);
	return 0;
}
