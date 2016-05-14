///////////////////////////////////////////////////////////////////////
// File: VideoPoker.cpp
// Author: Robert Carll
// This assignment represents my own work and is in accordance with the College Academic Policy
// Copyright (c) 2015 All Right Reserved by Robert Carll
// Contributors:
// Description:
// Date: May 2016
// Revisions:
//////////////////////////////////////////////////////////////////////

#include "VideoPoker.h"



VideoPoker::VideoPoker()
{
	payouts();
}

VideoPoker::~VideoPoker()
{
}

void VideoPoker::play() //game loop
{

	int choice;
	bool leave = false;
	while (leave != true)
	{
		welcome();

		std::cout << "\n*************************************\n" <<
			"        1) View pay table        \n" <<
			"        2) Play the game         \n" <<
			"        3) Quit                  \n" <<
			"*************************************\n" << std::endl;


		std::cout << "credis: " << credits << std::endl;

		std::cin >> choice;

		while (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore();
			std::cin >> choice;
		}
		std::cin.ignore();
		
		switch (choice) {
		case 1:
			table();
			break;
		case 2:
			game();
			break;

		case 3:
			leave = true;
			break;
		default:
			break;
		};

		system("cls");
	}
	system("cls");
}

void VideoPoker::table() const  
{

	system("cls");
	std::cout << "****************************************\n" <<
		"       hand              credits     \n" <<
		"______________________________________\n" <<
		" Royal Flush               250       \n" <<
		"______________________________________\n" <<
		" Straight flush             50       \n" <<
		"______________________________________\n" <<
		" Four of a kind             25       \n" <<
		"______________________________________\n" <<
		" Full House                  9       \n" <<
		"______________________________________\n" <<
		" Flush                       6       \n" <<
		"______________________________________\n" <<
		" Straight                    4       \n" <<
		"______________________________________\n" <<
		" Three of a kind             3       \n" <<
		"______________________________________\n" <<
		" Two pair                    2       \n" <<
		"______________________________________\n" <<
		" Jacks of better             1       \n" <<
		"______________________________________\n" <<
		" Theoretical Return         98.4%    \n" <<
		"                                      \n" <<
		"****************************************" << std::endl;
	system("pause");

}

void VideoPoker::welcome() const
{
	std::cout << "*****************************************\n" <<
		"      Welcome to Jacks or better!      \n" <<
		"*****************************************" << std::endl << std::endl;
	
	std::cout << "Your goal is to get a pair of jacks or higher!" << std::endl;
}

void VideoPoker::game()
{

	system("cls");

	Deck deck;
	Hand hand;

	deck.shuffle();
	
	while (hand.size() != 5) // Adds cards to hand
		hand.addCard(deck.draw());

	newCards(hand); 


	for (int i = 0; i != _choices.size(); i++)
	{
		if (_choices[i] != 0)
			hand.redraw(_choices[i], deck.draw()); // redraws selected cards
	}

	std::cout << hand << std::endl;
	hand.checkHand(); // Checks to see if there is a winning hand
	outcome(hand); // If they won shows payout	
}

void VideoPoker::payouts() // the payout map
{
	std::pair<std::string, int> pair("pair", 1);
	std::pair<std::string, int> twoPair("Two Pair", 2);
	std::pair<std::string, int> threeOfAKind("Three of a kind", 3);
	std::pair<std::string, int> straight("Straight", 4);
	std::pair<std::string, int> flush("Flush", 6);
	std::pair<std::string, int> fullHouse("Full House", 9);
	std::pair<std::string, int> fourOfAKind("Four of a kind", 25);
	std::pair<std::string, int> straightFlush("Straight Flush", 50);
	std::pair<std::string, int> royalFlush("Royal Flush", 250);

	_payout.insert(pair);
	_payout.insert(twoPair);
	_payout.insert(threeOfAKind);
	_payout.insert(straight);
	_payout.insert(flush);
	_payout.insert(fullHouse);
	_payout.insert(fourOfAKind);
	_payout.insert(straightFlush);
	_payout.insert(royalFlush);
}

void VideoPoker::newCards(Hand hand)
{
	int c = 1; 

	while (c != 0)
	{
		std::cout << hand << std::endl;											  //
		std::cout << "chose the card you would like to redraw (0 to continue): "; // Prints hand and gives players option to draw or hold
		std::cin >> c;															  //
		
		if (c < 0 || c > hand.size() || std::cin.fail())
		{
			std::cout << "enter a valid choice" << std::endl;
			std::cin.clear();
			std::cin.ignore();
			system("pause");
		}
		else if (c != 0)
		{
			hand.toggleDraw(c);
			int count = std::count(_choices.begin(), _choices.end(), c); // Checks for toggle 
			if (count > 0) // If it gets retoggled to hold
			{
				for (int i = 0; i < _choices.size(); i++)
				{
					if (_choices[i] == c)
						_choices.erase(_choices.begin() + i);
				}
			}
			else	
				_choices.push_back(c);
		}
		system("cls");
	}
	system("cls");
}

void VideoPoker::outcome(Hand hand)
{
	auto end = hand.payout.end();
	end--;

	for (auto h : hand.payout) // checks for the payouts
	{
		auto p = _payout.begin();

		if (h.second == true)
		{
			while (p->first != h.first) // matches the outcome with the payout
				p++;

			std::cout << h.first << "You won " << p->second << " credits!" << std::endl;
			credits = credits + p->second;
			system("pause");
			break;
		}
		else if (h.first == end->first) // if no matches then it prints you lose
		{
			std::cout << "you lost" << std::endl;
			system("pause");
		}


	}
}
