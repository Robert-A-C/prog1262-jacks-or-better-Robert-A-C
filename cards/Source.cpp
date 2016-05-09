#include "Card.h"
#include "Deck.h"
#include "Hand.h"
#include <vector>
#include <iostream>



int main() {




	Deck deck;
	
	deck.shuffle();

	
	Hand hand1 (deck);
	

	
	std::cout << hand1 << std::endl;
	if(hand1.isPair())
		std::cout << "You have a pair" << std::endl;
	if(hand1.isThreeOfaKind())
		std::cout << "You have a three of a kind" << std::endl;
	if(hand1.isFourOfaKind())
		std::cout << "You have a four of a kind" << std::endl;
	if(hand1.isFullHouse())
		std::cout << "You have a fullhouse" << std::endl;
	if(hand1.isTwoPair())
		std::cout << "You have two pair" << std::endl;
	if(hand1.isFlush())
		std::cout << "You have a flush" << std::endl;
	if (hand1.isStraight())
		std::cout << "a straight";
	

	system("pause");
}
