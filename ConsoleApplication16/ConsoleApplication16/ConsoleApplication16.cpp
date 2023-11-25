#include "moneyStruct.h"
#include <vector>
#include <iostream>



int main()
{
	setlocale(LC_ALL, "RU");
	ifstream file("txt.txt");
	
	try {
		if (file.is_open())
		{
			std::vector <MoneyStruct> money;
			MoneyStruct zal;

			zal.moneyData(file, money);
			zal.printVector(money, std::cout);
		}
	}

	catch (std::runtime_error& Message) {
		std::cout << Message.what();
	}
}

