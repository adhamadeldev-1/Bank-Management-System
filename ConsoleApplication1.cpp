#include <iostream>
#include "ClsLoginScreen.h"

using namespace std;


int main() {
	while (true) {
		if (!ClsLoginScreen::ShowLoginscreen())
			break;
		else
			ClsMainScreen::ShowMainScreen();
	}
}

