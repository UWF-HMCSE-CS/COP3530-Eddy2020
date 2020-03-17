#ifndef PASSAGE_HPP
#define PASSAGE_HPP

#include <string>

class Passage
{
	private:
		bool isOpen;
		std::string key;
	public:
		Passage() {};
		Passage(bool isOpen);
		Passage(bool isOpen, std::string key);

		bool IsOpen();
		bool RequiresKey();

		std::string GetRequiredKey();
		
		void Open();
};

#endif
