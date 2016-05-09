#include "Hand.h"
#include "Card.h"


Hand::Hand(Deck& deck)
{
	while (_hand.size() < 5)
	{
		_hand.push_back(deck.draw());
	}
}


Hand::~Hand()
{
}

void Hand::addCard(CardPtr c)
{
	_hand.push_back(c);
}

bool Hand::isPair()
{
	std::map<Face, int> h;

	for (int i = 0; i < _hand.size(); i++)
		h[_hand[i]->face]++;

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

bool Hand::isThreeOfaKind()
{
	std::map<Face, int> h;

	for (int i = 0; i < _hand.size(); i++)
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

bool Hand::isFourOfaKind()
{
	std::map<Face, int> h;

	for (int i = 0; i < _hand.size(); i++)
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

bool Hand::isFullHouse()
{
	if (isPair() && isThreeOfaKind())
		return true;
	else
		return false;
	
}

bool Hand::isTwoPair()
{
	std::map<Face, int> h;

	for (int i = 0; i < _hand.size(); i++)
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

bool Hand::isFlush()
{
	std::set<Suit> s;

	for (int i = 0; i < _hand.size(); i++)
		s.insert(_hand[i]->suit);

	if (s.size() == 1)
		return true;
	else
		return false;
}

bool Hand::isStraight()
{
	std::set<int> f;

	for (int i = 0; i < _hand.size(); i++)
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

bool Hand::isStraightFlush()
{
	if (isStraight() && isFlush())
		return true;
	else
		return false;
}

bool Hand::isRoyalFlush()
{
	std::set<int> f;

	for (int i = 0; i < _hand.size(); i++)
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



std::ostream& operator<<(std::ostream& os, const Hand& h)
{
	for (int i = 0; i < h.size(); i++)
	{
		os << *h._hand[i] << std::endl;
	}
	return os;
}