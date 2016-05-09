#pragma once

#include <memory>
#include <vector>
struct Card;
using CardPtr = std::shared_ptr<Card>;


class Deck
{
public:
	Deck();

	bool isEmpty() const;
	CardPtr draw();
	Card cut();
	void shuffle();
	void sort();



private:
	std::vector<CardPtr> _deck;
	int _topOfDeck;
};

