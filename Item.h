// Name: Navdeep Virdi
// Seneca email: nvirdi2@myseneca.ca
// Student ID: 166485193
// Date: Feb 4, 2021

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_ITEM_H
#define SDDS_ITEM_H

namespace sdds 
{
   class Item 
   {
      char m_itemName[21];
      double m_price;
      bool m_taxed;
      void setName(const char* name);
      
   public:
      void setEmpty();
      void set(const char* name, double price, bool taxed);
      void display()const;
      bool isValid()const;
      double price()const;
      double tax()const;
   };
}

#endif // !SDDS_ITEM_H
