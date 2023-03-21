#include "../include/controller/StandardConfig.h"

int main() {
	StandardConfig gameConfig = StandardConfig();
	while (true) {
		gameConfig.nextTurn();
	}
	return 0;
}
