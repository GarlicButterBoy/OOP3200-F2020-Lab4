/*
 *
 *Name		@ Nick Sturch-Flint
 *Date		@ October 09, 2020
 *File Name @ StandardDeck.cpp
 *
 */

#include "StandardDeck.h"
#include <algorithm> // needed for sort(), random_shuffle(), and replace()
#include <iostream>
#include <utility>

//Default Constructor
StandardDeck::StandardDeck()
{
	std::vector<PlayingCard*> m_cardArray;
	StandardDeck::Initialize();
}

//Constructor
StandardDeck::StandardDeck(std::vector<PlayingCard*> deck)
{
	SetDeck(std::move(deck));
}

//Destructor
StandardDeck::~StandardDeck()
= default;

//Copy Constructor
StandardDeck::StandardDeck(const StandardDeck& other_deck)
{
	//SetSize(other_deck.m_size);
	SetDeck(other_deck.m_cardArray);

}

//Assignment Operator Constructor
StandardDeck& StandardDeck::operator=(const StandardDeck other_deck)
{
	//SetSize(other_deck.m_size);
	SetDeck(other_deck.m_cardArray);
	return (*this); //this line is the main difference between the copy constructor and assignment operator overload
}

//Getter
std::vector<PlayingCard*> StandardDeck::GetDeck() const
{
	return m_cardArray;
}

//Setter
void StandardDeck::SetDeck(std::vector<PlayingCard*> new_deck)
{
	m_cardArray = new_deck;
}

//Resets the deck to 52 cards, sequentially
void StandardDeck::Initialize()
{
	if (!m_cardArray.empty())
	{
		m_cardArray.clear();
	}


	for (int i = 0; i < PlayingCard::SUITS; i++ )
	{
		for (int j = 1; j < PlayingCard::RANKS + 1; j++)
		{
			//Set the elements
			auto temp = new PlayingCard(j, i);
			m_cardArray.push_back(temp);
		}
	}

}

//ToString method to print the card array
std::string StandardDeck::ToString() const
{
	std::string outputString;

	const int temp = m_cardArray.size();
	for (int index = 0; index < temp; index++ )
	{
	outputString += "\n--------------------";
	outputString += "\nCard  : #" + std::to_string(index + 1);
	outputString += "\nSuit  : " + m_cardArray[index]->GetSuit();
	outputString += "\nRank  : " + m_cardArray[index]->GetRank();
	outputString += "\n--------------------\n";
	}

	return outputString;
}

//Shuffle Method
void StandardDeck::Shuffle()
{
	std::random_shuffle(m_cardArray.begin(), m_cardArray.end());
}

//Cards Remaining Method
std::string StandardDeck::CardsRemaining() const
{
	std::string outputString = "";
	outputString += "\n--------------------\n";
	outputString += "Cards Remaining: " + std::to_string(m_cardArray.size());
	outputString += "\n--------------------\n";
	return outputString;
}

//Draw Top Card of Deck
std::string StandardDeck::DrawCard()
{
	std::string outputString = "";

	if(!m_cardArray.empty())
	{
		m_cardArray[0]->FlipCard();

		outputString += "\nYou drew the card:\n";
		outputString += "-------------------";
		outputString += "\nSuit: " + m_cardArray[0]->GetSuit();
		outputString += "\nRank: " + m_cardArray[0]->GetRank();
		outputString += "\n-------------------\n";
		m_cardArray.erase(m_cardArray.begin());
	}

	return outputString;
}

//Draw Card from the Deck Randomly
std::string StandardDeck::RandomDraw()
{
	const int num = rand() % m_cardArray.size() + 1;

	std::string outputString = "";

	if (!m_cardArray.empty())
	{
		m_cardArray[num]->FlipCard();

		outputString += "You drew the card:\n";
		outputString += "-------------------";
		outputString += "\nSuit: " + m_cardArray[num]->GetSuit();
		outputString += "\nRank: " + m_cardArray[num]->GetRank();
		outputString += "\n-------------------\n";
		m_cardArray.erase(m_cardArray.begin() + num);
	}

	return outputString;
}


