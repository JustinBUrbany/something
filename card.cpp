#include <iostream>
using std::cout;
using std::endl;
#include "card.h"
#include <iostream>
using std::cin;
/**********************************************************************
* Purpose:Multi arg constructor intialize suit and rank of a card
*
* Precondition: pass in a suit and a rank
*
* Postcondition: intialize the object
*
************************************************************************/
Card::Card(Rank rank, Suit suit) : m_rank(rank), m_suit(suit)
{ }
/**********************************************************************
* Purpose:The purpose of this function is to display the card to the
screen
*
* Precondition: be called within a card object
*
* Postcondition: have displayed a card to the screen
*
************************************************************************/
void Card::DisplayCard()
{

	const char*rank_txt[] = { "Ace","Deuce", "Trey", "Four", "Five", "Six", "Seven", "Eight",
		"Nine", "Ten", "Jack", "Queen","King" };

	cout << rank_txt[m_rank - 1] << " of " << static_cast<char>(m_suit);

}
/**********************************************************************
* Purpose:default destructor delete a card clean up memory
*
* Precondition: called when a card is going out of close
*
* Postcondition: the card no longer exsits
*
************************************************************************/
Card::~Card()
{

}
/**********************************************************************
* Purpose:This function is to set the rank of your cards private member
rank
*
* Precondition: called within a card and pass in a rank
*
* Postcondition: set m_rank to the rank
*
************************************************************************/
void Card::SetRank(Rank rank)
{
	m_rank = rank;
}
/**********************************************************************
* Purpose:This function is to set the suit of your cards data member
suit
*
* Precondition:called within a card and pass in a suit
*
* Postcondition: set the private member suit to the value that was
passed in
*
************************************************************************/
void Card::SetSuit(Suit suit)
{
	m_suit = suit;

}
/**********************************************************************
* Purpose: Returns thte private rank member of your cards
*
* Precondition: get called within a card object
*
* Postcondition: return the private data member m_rank
*
************************************************************************/
//Card::Rank 
int Card::PlayerGetRank()
{
	int tempvalue = 0;
	if (m_rank == DEUCE)
	{
		tempvalue = 2;
	}
	else if (m_rank == TREY)
	{
		tempvalue = 3;
	}
	else if (m_rank == FOUR)
	{
		tempvalue = 4;
	}
	else if (m_rank == FIVE)
	{
		tempvalue = 5;
	}
	else if (m_rank == SIX)
	{
		tempvalue = 6;
	}
	else if (m_rank == SEVEN)
	{
		tempvalue = 7;
	}
	else if (m_rank == EIGHT)
	{
		tempvalue = 8;
	}
	else if (m_rank == NINE)
	{
		tempvalue = 9;
	}
	else if (m_rank == KING || m_rank == QUEEN || m_rank == JACK || m_rank==TEN)
	{
		tempvalue = 10;
	}
	else if (m_rank == ACE)
	{
		int selection = 0;
		cout << "Do you want your ace to be 1 or 11?(Enter 0 for 1 or Enter 1 for 11)";
		cin >> selection;
		if (selection == 0)
		{
			tempvalue=1;
		}
		else
		{
			tempvalue=11;
		}
	}

	return tempvalue;

}
/********************************************************
*
*Purpose: Sets intial value of the dealers cards
*
*Precondition: Doesn't take anything called from card
*
*Postcondition: return an integer value equal to the rank
* value for that card
*
*********************************************************/
int Card::GetRank(bool & secondace)
{

	int tempvalue = 0;
	if (m_rank == DEUCE)
	{
		tempvalue = 2;
	}
	else if (m_rank == TREY)
	{
		tempvalue = 3;
	}
	else if (m_rank == FOUR)
	{
		tempvalue = 4;
	}
	else if (m_rank == FIVE)
	{
		tempvalue = 5;
	}
	else if (m_rank == SIX)
	{
		tempvalue = 6;
	}
	else if (m_rank == SEVEN)
	{
		tempvalue = 7;
	}
	else if (m_rank == EIGHT)
	{
		tempvalue = 8;
	}
	else if (m_rank == NINE)
	{
		tempvalue = 9;
	}
	else if (m_rank == KING || m_rank == QUEEN || m_rank == JACK || m_rank == TEN)
	{
		tempvalue = 10;
	}
	else if (secondace == false && m_rank == ACE)

	{
		tempvalue=11;
		secondace = true;
	}
	else if (secondace == true && m_rank == ACE)
	{
		tempvalue = 1;
	}
	return tempvalue;
	
}
/********************************************************
*
*Purpose: To give a value equal to the rank of the card
* also set the ace to a the correct value to not allow
* unnecessary bust. Soft bad needs another conditioin
*
*Precondition: Take in the previous value 
*
*Postcondition: Return a value
*
*********************************************************/
int Card::DealerGetRank(int currentvalue)
{
	
	int tempvalue = 0;
	if (m_rank == DEUCE)
	{
		tempvalue = 2;
	}
	else if (m_rank == TREY)
	{
		tempvalue = 3;
	}
	else if (m_rank == FOUR)
	{
		tempvalue = 4;
	}
	else if (m_rank == FIVE)
	{
		tempvalue = 5;
	}
	else if (m_rank == SIX)
	{
		tempvalue = 6;
	}
	else if (m_rank == SEVEN)
	{
		tempvalue = 7;
	}
	else if (m_rank == EIGHT)
	{
		tempvalue = 8;
	}
	else if (m_rank == NINE)
	{
		tempvalue = 9;
	}
	else if (m_rank == KING || m_rank == QUEEN || m_rank == JACK || m_rank == TEN)
	{
		tempvalue = 10;
	}
	else if (m_rank == ACE)
	{
		if (currentvalue + 11 > 21)
		{
			tempvalue = 1;
		}
		else
		{
			tempvalue = 11;
		}
	}

	return tempvalue;
}
/**********************************************************************
* Purpose:This is a getter for the card class that returns the private
member m_suit
*
* Precondition: get called within a card object
*
* Postcondition: must return the private member m_suit
*
************************************************************************/
Card::Suit Card::GetSuit()
{

	return m_suit;

}