#include "StandardDeck.h"

//Default Constructor
StandardDeck::StandardDeck()
{
	//m_size = 0;
	m_cardArray = 0;
	Initialize();
}

//Constructor
StandardDeck::StandardDeck(PlayingCard* deck)
{
	//SetSize(size);
	SetDeck(deck);
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
PlayingCard* StandardDeck::GetDeck() const
{
	return m_cardArray;
}

//Getter
//int StandardDeck::GetSize() const
//{
//	return m_size;
//}

//Setter
void StandardDeck::SetDeck(PlayingCard* new_deck)
{
	m_cardArray = new_deck;
}

//Setter
//void StandardDeck::SetSize(int size)
//{
//	m_size = size;
//}

void StandardDeck::Initialize()
{
	if (m_cardArray != 0)
	{
		delete[]m_cardArray;
	}

	//Allocate Memory
	//m_cardArray = new PlayingCard[SIZE];
	//int numOfCards = SIZE;


	for (int i = 0; i < PlayingCard::SUITS; i++ )
	{
		for (int j = 0; j < PlayingCard::RANKS + 1; j++)
		{

		}
	}

}
