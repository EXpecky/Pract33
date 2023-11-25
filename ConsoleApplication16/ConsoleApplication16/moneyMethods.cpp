﻿#include "moneyStruct.h"
#include "pch.h"
#include <iomanip>
#include<vector>
#include<iostream>

using namespace std;

void MoneyStruct::correctKurs(int kurs)
{
	if (kurs <= 0) throw std::runtime_error{ "Error! Incorrect CURRENCY EXCHANGE RATE was entered " };
}

void MoneyStruct::correctName(std::string name) {
	std::string val = " RUB DOL EUR UAH TRY";
	if (!(val.find(name) != std::string::npos))  throw std::runtime_error{ "Error! Incorrect NAME was entered " };
}
void MoneyStruct::createMoneyFromFile(istream& file)
{
	std::string name_1;
	std::string name_2;
	float bfKurs = 0.0;

	file >> name_1;
	file >> name_2;
	file >> bfKurs;
	correctName(name_1);
	correctName(name_2);
	correctKurs(bfKurs);

	name1 = name_1;
	name2 = name_2;
	kurs = bfKurs;

}

void MoneyStruct::printMoney(ostream& out)
{
	out <<" "<< name1 << " " << name2 << " " << kurs << " ";
	out << endl; 
}

string MoneyStruct::get_name1()
{
	return name1;
}

string MoneyStruct::get_name2()
{
	return name2;
}

float MoneyStruct::get_kurs()
{
	return kurs;
}


void MoneyStruct::setName1(std::string name) {
	name1 = name;
}

void MoneyStruct::setName2(std::string name) {
	name2 = name;
}

void MoneyStruct::setKurs(float k) {
	kurs = k;
}

void MoneyStruct::set_date(DateStruct Date)
{
	date = Date;
}

DateStruct& MoneyStruct::get_Date() {
	return date;
}
void MoneyStruct::printVector(std::vector<MoneyStruct>& money, std::ostream& ost)
{
	//date.printDate(std::cout);
	for (rsize_t i = 0; i < money.size(); i++)
	{
		money.at(i).date.printDate(ost);
		money.at(i).printMoney(ost);
	}
}


void MoneyStruct::moneyData(std::istream& file, std::vector<MoneyStruct>& money)
{
	while (!file.eof())
	{
		MoneyStruct m_data;
		m_data.date.createDateFromFile(file);
		m_data.createMoneyFromFile(file);
		money.push_back(m_data);
	}
}