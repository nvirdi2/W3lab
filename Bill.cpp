// Name: Navdeep Virdi
// Seneca email: nvirdi2@myseneca.ca
// Student ID: 166485193
// Date: Feb 4, 2021

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.v

#include "cstring.h"
#include "Bill.h"

#include <iostream>
#include <iomanip>
using namespace std;

namespace sdds 
{

	
	bool Bill::add(const char* item_name, double price, bool taxed) 
	{
		if (m_itemsAdded < m_noOfItems) 
		{
			m_items[m_itemsAdded].set(item_name, price, taxed);

			m_itemsAdded++;

			return true;
		} 
		else
		{
			return false;
		}
	}


	void Bill::deallocate() 
	{
		for (int x = 0; x < m_noOfItems; ++x) 
		{
			delete[] m_items;

			m_items = nullptr;
		}
	}


	void Bill::display()const 
	{
		Title();

		for (int x = 0; x < m_noOfItems; ++x) 
		{
			m_items[x].display();
		}
		footer();
	}


	void Bill::footer()const 
	{
		cout << "+----------------------+---------+-----+" << endl;

		if (isValid()) 
		{
			cout << "|                Total Tax: " << setfill(' ') << setw(10) << totalTax() << " |" << endl;

			cout << "|              Total Price: " << setfill(' ') << setw(10) << totalPrice() << " |" << endl;

			cout << "|          Total After Tax: " << setfill(' ') << setw(10) << totalPrice() + totalTax() << " |" << endl;
		}

		else 
		{
			cout << "| Invalid Bill                         |" << endl;
		}
		cout << "+--------------------------------------+" << endl;
	}


	void Bill::init(const char* title, int noOfItems) 
	{
		if (title[0] == '\0' || noOfItems <= 0) 
		{
			setEmpty();
		}

		else 
		{
			m_noOfItems = noOfItems;
			m_itemsAdded = 0;

			strnCpy(m_title, title, 36);

			m_items = new Item[noOfItems];

			for (int x = 0; x < noOfItems; ++x) 
			{
				m_items[x].setEmpty();
			}
		}
	}


	bool Bill::isValid()const 
	{
		bool valid = false;

		if (m_title[0] != '\0' && m_items != NULL) 
		{

			for (int x = 0; x < m_noOfItems; ++x) 
			{

				if (!(m_items[x].isValid())) 
				{
					return valid;
				}
			}

			valid = true;
		} return valid;
	}


	void Bill::setEmpty() 
	{
		m_title[0] = '\0';
		m_items = nullptr;
	}


	void Bill::Title()const 
	{
		cout << "+--------------------------------------+" << endl;

		if (isValid()) 
		{
			cout << "| ";
			cout.fill(' ');

			cout.width(36);
			cout.setf(ios::left);
			cout << m_title;
			cout.unsetf(ios::left);

			cout<< " |" << endl;
		}

		else
		{ 
			cout << "| Invalid Bill                         |" << endl;
			cout << "+----------------------+---------+-----+" << endl;
			cout << "| Item Name            | Price   + Tax |" << endl;
			cout << "+----------------------+---------+-----+" << endl;
		}
	}


	double Bill::totalPrice()const
	{
		double sum = 0.00;

		for (int x = 0; x < m_noOfItems; ++x)
		{ 
			sum += m_items[x].price();
		} return sum;
	}


	double Bill::totalTax()const 
	{
		double sum = 0.00;

		for (int x = 0; x < m_noOfItems; ++x)
		{ 
			sum += m_items[x].tax();
		} return sum;
	}


}

