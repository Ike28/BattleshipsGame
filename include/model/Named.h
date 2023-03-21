#pragma once
#include <string>

class Named {
	protected:
		std::string name;

	public:
		virtual std::string getName() = 0;
};
