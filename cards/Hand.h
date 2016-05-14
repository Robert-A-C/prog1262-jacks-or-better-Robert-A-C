///////////////////////////////////////////////////////////////////////
// File: Hand.h
// Author: Robert Carll
// This assignment represents my own work and is in accordance with the College Academic Policy
// Copyright (c) 2015 All Right Reserved by Robert Carll
// Contributors:
// Description:
// Date: May 2016
// Revisions:
//////////////////////////////////////////////////////////////////////

#pragma once
#include "Deck.h"
#include <iostream>
#include <map>
#include <algorithm>
#include <unordered_map>

struct Card;
using CardPtr = std::shared_ptr<Card>;

class Hand
{
public:
	Hand();
	~Hand();


	void addCard(CardPtr c); // adds card
	void removeCard(int c); //removes card
	void redraw(int i, CardPtr c); // redraws card

	void checkHand(); // checks the hand for payouts

	std::unordered_map<std::string, bool> payout; 

	friend std::ostream& operator<<(std::ostream& os, const Hand& h); 

	void clear() { _hand.clear(); } // clears hand
	int size() const { return _hand.size(); } // gets size of hand

	bool isDraw(int idx); // bool for draw
	void toggleDraw(int idx); // toggle draw or hold

private:
	void payoutHands(); // map for payouts
	bool isPair();
	bool isThreeOfaKind();
	bool isFourOfaKind();
	bool isFullHouse();
	bool isTwoPair();
	bool isFlush();
	bool isStraight();
	bool isStraightFlush();
	bool isRoyalFlush();

	std::vector<CardPtr> _hand;
	std::vector<bool> _draw;

};

std::ostream& operator<<(std::ostream& os, const Hand& h);

