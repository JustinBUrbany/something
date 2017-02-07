#ifndef DECK_H
#define DECK_H

#include "card.h"
#include "random.h"
/************************************************************************
* Class: Deck
*
* Purpose: The purpose of this class is to create a deck that can hold
a deck of cards so that a game can be played with it
*
* Manager functions:
shuffle(): shuffles the cards in the deck
deal() deal the cards per deck
*
* Data_members:
m_deck[52] holds all the cards you have
rand used to get random numbers

*************************************************************************/
class Deck
{

public:
	Deck();
	void Shuffle();
	Card Deal();
	static int GetCard();
	~Deck();
private:
	Card ** m_deck;
	Random rand;
	static int m_currentcard;
};

#endif 