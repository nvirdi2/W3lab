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

	/*NOTES FOR MYSELF:
		- Add function is going to add the number of items
		- with the number of items added and add the name, price, and tax
		- Create a if loop to continue doing it until its adds up and nothing is left
	*/
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

	/*NOTES FOR MYSELF:
		- deallocate is going to be used to delete an item or items (use delete[])
	*/
	void Bill::deallocate() 
	{
		int x;

		for (x = 0; x < m_noOfItems; ++x) 
		{
			delete[] m_items;

			m_items = nullptr;
		}
	}

	/*NOTES FOR MYSELF:
		- Display the whole bill with title footer and context
	*/
	void Bill::display()const 
	{
		int x;
		Title();

		for (x = 0; x < m_noOfItems; ++x) 
		{
			m_items[x].display();
		}
		footer();
	}

	/*NOTES:
		- This is going to be the end of the bill
		- This is going to print the total price, tax, and total with price and tax added
		- Use set fill to enter spaces
		- Use setw to enter the amount of spaces
		- Then print out the price or tax or totla and end the line
	*/
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
		cout << "| Invalid Bill                         |" << endl;
		cout << "+--------------------------------------+" << endl;
		}

	/*NOTES:
		- Init is going to be the numbe rof items added
		- If title and items is 0 then equal to empty and use a function to do that
		- Then if the the user can add to the empty list
		- Add the noOfItems to the list and continue for each NEW item
	*/
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
			
			int x;

			for (x = 0; x < noOfItems; ++x) 
			{
				m_items[x].setEmpty();
			}
		}
	}

	/*NOTES:
		- Is valid function will check if the stuff is true or false
		- Will need a valid variable declared with bool
		- If the title is 0 and items is null 
		- The numbe rof items should be greater then x
		- And then if vailed return valid and valid is true
	*/
	bool Bill::isValid()const 
	{
		bool Valid = false;
		int x;

		if (m_title[0] != '\0' && m_items != NULL) 
		{

			for (x = 0; x < m_noOfItems; ++x) 
			{

				if (!(m_items[x].isValid())) 
				{
					return Valid;
				}
			}

			Valid = true;
		} return Valid;
	}

	/*NOTES:
		- Set empty function will just have 0 characters for the title
		- Items will use nullptr
	*/
	void Bill::setEmpty() 
	{
		m_title[0] = '\0';
		m_items = nullptr;
	}

	/*NOTES:
		- Title function is going to print out the top of the reciept
		- Then it is going to check if what they are going to valid
		- Then going print out if its valid or not and if not the print out in invalid and continue
		- Use ios left to print out the variables faster with the title
	*/
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
		}
			 cout << "+----------------------+---------+-----+" << endl;
			 cout << "| Item Name            | Price   + Tax |" << endl;
			 cout << "+----------------------+---------+-----+" << endl;

	}

	/*NOTES:
		- Total price function function is going to add up all of the prices
		- Add variable is going to double becuase its a price
	*/
	double Bill::totalPrice()const
	{
		double add = 0.00;
		int x;

		for (x = 0; x < m_noOfItems; ++x)
		{ 
			add += m_items[x].price();
		} return add;
	}

	/*NOTES:
		- Total tax function is going to add up all of the prices
		- Add variable is going to double becuase its a price
		- Then taking the added up prices its going to add tax to the items
		- Then its going to return the added up sum after adding tax
	*/
	double Bill::totalTax()const 
	{
		double add = 0.00;
		int x; 

		for (x = 0; x < m_noOfItems; ++x)
		{ 
			add += m_items[x].tax();
		} return add;
	}


}
