///////////////////////////////////////////////////////////////////////
// File: VideoPoker.h
// Author: Robert Carll
// This assignment represents my own work and is in accordance with the College Academic Policy
// Copyright (c) 2016 All Right Reserved by Robert Carll
// Contributors:
// Description:
// Date: May 2016
// Revisions:
//////////////////////////////////////////////////////////////////////

#pragma once
#include "Hand.h"
#include <unordered_map>

class VideoPoker
{
public:
	VideoPoker();
	~VideoPoker();

	void play();

private:
	
	void payouts(); 
	void table() const;
	void welcome() const;
	void game();	
	void newCards(Hand hand);
	void outcome(Hand hand);	
	
	std::unordered_map<std::string, int> _payout;
	std::vector<int> _choices;
	int credits = 0;
};