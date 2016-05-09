#pragma once
#include "Deck.h"
#include <iostream>
#include <map>
#include <algorithm>

struct Card;
using CardPtr = std::shared_ptr<Card>;

class Hand
{
public:
	Hand(Deck& deck);
	~Hand();


	void addCard(CardPtr c);
	
	bool isPair();
	bool isThreeOfaKind();
	bool isFourOfaKind();
	bool isFullHouse();
	bool isTwoPair();
	bool isFlush();
	bool isStraight();
	bool isStraightFlush();
	bool isRoyalFlush();

	friend std::ostream& operator<<(std::ostream& os, const Hand& h);
	
	void clear() {_hand.clear();}
	int size() const { return _hand.size(); }
private:
	std::vector<CardPtr> _hand;
	
};


std::ostream& operator<<(std::ostream& os, const Hand& h); 