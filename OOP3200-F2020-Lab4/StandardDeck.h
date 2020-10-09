/** OOP3200. F2020. StandardDeck.h
 *
 *  In this lab you will create your own collection class called StandardDeck, which
 *	will 'contain' objects of the PlayingCard class.  The intent of the class is to
 *	represent a standard deck of 52 cards that might be useful in a card game type
 *	application.
 *
 *	@author		Thom MacDonald
 *	@author		Tom Tsiliopoulos
 *	@version	2020.10
 *	@since		Jul 2018
 *	@see		Bronson, G. (2012). A First Book of C++ (4th ed.). Boston, MA: Course Technology.
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
	int GetSize() const;

	// Mutators:
	void SetDeck(std::vector<PlayingCard*> new_deck);
	void SetSize(int size);

	//Methods
	virtual void Initialize();
	std::string ToString() const;

private:
	static const int SIZE = 52;
	int m_size;
	std::vector<PlayingCard*> m_cardArray;
};

#endif /* defined (__STANDARD_DECK__) */

