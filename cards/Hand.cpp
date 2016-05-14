///////////////////////////////////////////////////////////////////////
// File: Hand.cpp
// Author: Robert Carll
// This assignment represents my own work and is in accordance with the College Academic Policy
// Copyright (c) 2015 All Right Reserved by Robert Carll
// Contributors:
// Description:
// Date: May 2016
// Revisions:
//////////////////////////////////////////////////////////////////////

#include "Hand.h"
#include "Card.h"


Hand::Hand() //CTOR
{
	payoutHands();
}


Hand::~Hand() //DTOR
{
}

void Hand::addCard(CardPtr c) // Adds card
{
	_hand.push_back(c);
	std::pair<CardPtr, bool>newCard(c, false);
	_draw.push_back(false);
}

void Hand::removeCard(int c) //removes card
{	
	_hand.erase(_hand.begin() + (c - 1));
}

void Hand::redraw(int i, CardPtr c) // redraws card
{
	_hand[i - 1] = c;
}

void Hand::checkHand() // checks hand for payout
{
	if (isRoyalFlush())
		payout["Royal Flush"] = true;
	else if (isStraightFlush())
		payout["Straight Flush"] = true;
	else if (isFourOfaKind())
		payout["Four of a kind"] = true;
	else if (isFullHouse())
		payout["Full House"] = true;
	else if (isFlush())
		payout["Flush"] = true;
	else if (isStraight())
		payout["Straight"] = true;
	else if (isThreeOfaKind())
		payout["Three of a kind"] = true;
	else if (isTwoPair())
		payout["Two Pair"] = true;
	else if (isPair())
		payout["pair"] = true;
}

bool Hand::isPair() // checks hand for pair
{
	std::map<Face, int> h;

	for (int i = 0; i != _hand.size(); i++) {
		if (_hand[i]->face == Face::KING || _hand[i]->face == Face::QUEEN || _hand[i]->face == Face:: JACK || _hand[i]->face == Face::ACE)
			h[_hand[i]->face]++;
	}
	int pairCount = count_if(h.begin(), h.end(), [](std::pair<Face, int> e) { return(e.second == 2); });
	if (pairCount == 1)
	{
		
		return true;
	}
	else
	{
		return false;
	}

}

bool Hand::isThreeOfaKind() //checks hand for three of a kind
{
	std::map<Face, int> h;

	for (int i = 0; i != _hand.size(); i++)
		h[_hand[i]->face]++;

	int threeKindCount = count_if(h.begin(), h.end(), [](std::pair<Face, int> e) { return(e.second == 3); });
	if (threeKindCount == 1)
	{
		std::cout << "You have a three of a kind" << std::endl;
		return true;
	}
	else
	{
		return false;
	}
}

bool Hand::isFourOfaKind() // checks hand for four of a kind
{
	std::map<Face, int> h;

	for (int i = 0; i != _hand.size(); i++)
		h[_hand[i]->face]++;

	int fourKindCount = count_if(h.begin(), h.end(), [](std::pair<Face, int> e) { return(e.second == 4); });
	if (fourKindCount == 1)
	{
		std::cout << "You have a four of a kind" << std::endl;
		return true;
	}
	else
	{
		return false;
	}
}

bool Hand::isFullHouse() // checks hand for full house
{
	if (isPair() && isThreeOfaKind())
		return true;
	else
		return false;
	
}

bool Hand::isTwoPair() // checks hand for two pair
{
	std::map<Face, int> h;

	for (int i = 0; i != _hand.size(); i++)
		h[_hand[i]->face]++;

	int pairCount = count_if(h.begin(), h.end(), [](std::pair<Face, int> e) { return(e.second == 2); });
	if (pairCount == 2)
	{
		std::cout << "You have two pairs" << std::endl;
		return true;
	}
	else
	{
		return false;
	}
}

bool Hand::isFlush() // checks hand for flush
{
	std::set<Suit> s;

	for (int i = 0; i != _hand.size(); i++)
		s.insert(_hand[i]->suit);

	if (s.size() == 1)
		return true;
	else
		return false;
}

bool Hand::isStraight() // checks hand for straight
{
	std::set<int> f;

	for (int i = 0; i != _hand.size(); i++)
		f.insert((int)_hand[i]->face);

	auto start = f.begin();
	auto last = f.end();
	last--;

	if (f.size() == 5)
	{

		if (*start == *last - (f.size() - 1))
		{
			return true;
		}
		else if (*start == 0)
		{
			f.insert(13);
			start++;
			last = f.end();
			last--;
			if (*start == *last - (_hand.size() - 1))
			{
				return true;
			}
		}
		else {
			return false;
		}
			
	}
	else {
		return false;
	}
}

bool Hand::isStraightFlush() // checks hand for straight flush
{
	if (isStraight() && isFlush())
		return true;
	else
		return false;
}

bool Hand::isRoyalFlush() // checks hand for royal flush
{
	std::set<int> f;

	for (int i = 0; i != _hand.size(); i++)
		f.insert((int)_hand[i]->face);

	auto start = f.begin();
	auto last = f.end();
	last--;

	if (f.size() == 5)
	{
		if (*start == 0)
		{
			f.insert(13);
			start++;
			last = f.end();
			last--;
			if (*start == *last - (_hand.size() - 1) && isFlush())
			{
				return true;
			}
		}
		else
			return false;
	}
}

bool Hand::isDraw(int i)  // boolean if draw
{	
		if (_draw[i] == true)  
			return true;
		else
			return false;
	
}


void Hand::payoutHands() // map for payouts
{
	std::pair<std::string, bool> pair("pair", false);
	std::pair<std::string, bool> TwoPair("Two Pair", false);
	std::pair<std::string, bool> threeoak("Three of a kind", false);
	std::pair<std::string, bool> Straight("Straight", false);
	std::pair<std::string, bool> Flush("Flush", false);
	std::pair<std::string, bool> FullHouse("Full House", false);
	std::pair<std::string, bool> fouroak("Four of a kind", false);
	std::pair<std::string, bool> StraightFlush("Straight Flush", false);
	std::pair<std::string, bool> RoyalFlush("Royal Flush", false);

	payout.insert(pair);
	payout.insert(TwoPair);
	payout.insert(threeoak);
	payout.insert(Straight);
	payout.insert(Flush);
	payout.insert(FullHouse);
	payout.insert(fouroak);
	payout.insert(StraightFlush);
	payout.insert(RoyalFlush);
}

void Hand::toggleDraw(int idx) // toggles draw for card
{
	_draw[idx - 1] = !_draw[idx - 1];
}

std::ostream& operator<<(std::ostream& os, const Hand& h) 
{
	int i = 1;
	int j = 0;
	while (j < h.size()) {
		if (h._draw[j] == true)
			std::cout << i << ") " << *h._hand[j] << " (drawing)" << std::endl;
		else
			std::cout << i << ") " << *h._hand[j] << " (holding)" << std::endl;

		i++;
		j++;

	}

	return os;
}

