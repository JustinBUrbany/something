#ifndef CARD_H
#define CARD_H

/************************************************************************
* Class: Card
*
* Purpose: The purpose of this class is to create cards that can be used
in games
*
* Manager functions:
DisplayCard-displays a card to the screen
GetRank()-gets the rank of the private member
GetSuit()-gets the suit of the private member
SetRank()-sets the rank of the private member
SetSuit()-sets the suit of the private member
*
* Data_members:
m_rank hold the rank of a card
m_suit holds the suit of a card
*************************************************************************/
class Card
{
	// TODO: remember to come back and check out this enum stuff
public:
	enum Rank { ACE = 1, DEUCE, TREY, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };
	enum Suit { HEART = 3, DIAMOND, CLUB, SPADE };

	Card(Rank rank = ACE, Suit suit = SPADE);
	void DisplayCard();

	~Card();
	void SetRank(Rank rank);
	void SetSuit(Suit suit);
	//Rank PlayerGetRank();
	int PlayerGetRank();

	//Rank DealerGetRank(int currentvalue);
	int DealerGetRank(int currentvalue);
	int GetRank(bool & secondace);

	//Rank GetRank();
	Suit GetSuit();

private:
	Rank m_rank;
	Suit m_suit;
};

#endif
