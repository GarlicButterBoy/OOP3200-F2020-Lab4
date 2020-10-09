/*
 *
 *Name		@ Nick Sturch-Flint
 *Date		@ October 09, 2020
 *File Name @ StandardDeck.h
 *
 */

#pragma once
#ifndef __STANDARD_DECK__
#define __STANDARD_DECK__

#include <vector>

#include "PlayingCard.h"

class StandardDeck
{
public:
	// Initialization:
	StandardDeck();

	StandardDeck(std::vector<PlayingCard*> deck);

	// Rule of three:
	//1. Destructor
	~StandardDeck();

	//2. Copy Constructor
	StandardDeck(const StandardDeck& other_deck);

	//3. Assignment Operator
	StandardDeck& operator=(const StandardDeck other_deck);

	// Accessors:
	std::vector<PlayingCard*> GetDeck() const;


	// Mutators:
	void SetDeck(std::vector<PlayingCard*> new_deck);


	//Methods
	virtual void Initialize();
	std::string ToString() const;
	virtual void Shuffle();
	std::string CardsRemaining() const;
	std::string DrawCard();
	std::string RandomDraw();

private:

	std::vector<PlayingCard*> m_cardArray;
};

#endif /* defined (__STANDARD_DECK__) */

