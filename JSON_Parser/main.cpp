#include "Interaction.hpp"
#include "JSONCheck/JSONCheck.hpp"

int main(int argc, char* argv[]) {

	Interaction* starter = nullptr;
	//
	if (argc == 2) {

		starter = new Interaction(argv[1]);

	}
	else if (argc > 2) {
		cout << "Too many command line arguments!";
	}

	//
	if (!starter) {
		starter = new Interaction;
	}
	//Interaction starter;
	try {
		starter->start();
	}
	catch (const Exit_Program& e) {
		cout << endl << e.what();
	}
	catch (std::exception& e) {
		cout << e.what();
	}
	catch (...) {
		cout << "Unexpected error occurred while executing the command.\n";
	}

	delete starter;

	return 0;
}