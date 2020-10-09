#include "StandardDeck.h"
#include <algorithm> // needed for sort(), random_shuffle(), and replace()
#include <iostream>
#include <utility>

//Default Constructor
StandardDeck::StandardDeck()
{
	m_size = 0;
	std::vector<PlayingCard*> m_cardArray;
	Initialize();
}

//Constructor
StandardDeck::StandardDeck(std::vector<PlayingCard*> deck)
{
	SetSize(SIZE);
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

//Getter
int StandardDeck::GetSize() const
{
	return m_size;
}

//Setter
void StandardDeck::SetDeck(std::vector<PlayingCard*> new_deck)
{
	m_cardArray = new_deck;
}

//Setter
void StandardDeck::SetSize(int size)
{
	m_size = size;
}

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
	//std::cout << std::to_string(temp);
	for (int index = 0; index < temp; index++ )
	{
	outputString += "\n-------------------------------------------";
	outputString += "\nCard #: " + std::to_string(index + 1);
	outputString += "\nSuit  : " + m_cardArray[index]->GetSuit();
	outputString += "\nRank  : " + m_cardArray[index]->GetRank();
	}

	return outputString;
}

//Shuffle Method
void StandardDeck::Shuffle()
{
	std::random_shuffle(m_cardArray.begin(), m_cardArray.end());
}

//Cards Remaining Method
int StandardDeck::CardsRemaining()
{
	return m_cardArray.size();
}

//Draw Top Card of Deck
std::string StandardDeck::DrawCard()
{
	std::string outputString = "";

	if(!m_cardArray.empty())
	{
		m_cardArray[0]->FlipCard();

		outputString += "You drew the card:\n";
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


