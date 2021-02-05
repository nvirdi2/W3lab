// Name: Navdeep Virdi
// Seneca email: nvirdi2@myseneca.ca
// Student ID: 166485193
// Date: Feb 4, 2021

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include <iomanip>

#include "cstring.h"
#include "Item.h"

using namespace std;

namespace sdds {

	
	const double Tax = 0.13;

	
	void Item::display()const 
	{
		if (isValid()) 
		{
			cout << "| ";
				cout.fill('.');
				cout.width(20);
				cout.setf(ios::left);
				cout << m_itemName;
				cout.unsetf(ios::left);
			cout << " | ";
				cout.precision(2);
				cout.fill(' ');
				cout.width(7);
				cout.setf(ios::fixed);
				cout << m_price;
			cout << " | ";
			
				if (m_taxed != false) 
				{
					cout << "Yes";
				}

				else 
				{
					cout << "No ";
				}
			cout << " |" << endl;
		}

		else 
		{
			cout << "| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |"
				 << endl;
		}
	}

	
	bool Item::isValid()const 
	{
		return !(m_price == 0.00 && m_itemName[0] == '\0');
	}

	
	void Item::set(const char* name, double price, bool taxed) 
	{
		if (name == NULL || price < 0) 
		{
			setEmpty();
		}

		else 
		{
			setName(name);
			m_taxed = taxed;
			m_price = price;
			m_itemName[20] = char(0);
		}
	}

	
	void Item::setEmpty() 
	{
		m_itemName[0] = '\0';
		m_price = 0.0;
		m_taxed = true;
	}

	
	void Item::setName(const char* name) 
	{
		strnCpy(m_itemName, name, 20);
	}

	
	double Item::price()const 
	{
		return m_price;
	}

	
	double Item::tax()const
	 {
		if (m_taxed != false) 
		{
			return m_price * Tax;
		}

		else 
		{
			return 0.0;
		}
	}
}
