/*
 *
 *Name		@ Nick Sturch-Flint
 *Date		@ October 09, 2020
 *File Name @ Main.cpp
 *
 */

#include <ctime>
#include <iostream>
#include "StandardDeck.h"

void Pause() {
	std::cout << "\nPress \'ENTER\' to continue..." << std::endl;
	std::cin.ignore();	fflush(stdin);
}

int main()
{
	/*	Your main() function should demonstrate each of the features of the StandardDeck class*/
	srand(time(nullptr)); // seed the random number generator

	// create a deck
	StandardDeck deck;


	// Show the deck object as initialized
	std::cout << "New Card Deck: \n";
	std::cout << deck.ToString();
	std::cout << deck.CardsRemaining();
	Pause();

	// Draw the next card and show it
	std::cout << "Drawing the top card: \n";
	std::cout << deck.DrawCard();
	std::cout << deck.CardsRemaining();

	// Draw a random card and show it
	std::cout << "Drawing a random card: \n";
	std::cout << deck.RandomDraw();
	std::cout << deck.CardsRemaining();

	// Show the deck with the remaining cards
	std::cout << "These are the cards left in the deck: \n";
	std::cout << deck.ToString();
	std::cout << deck.CardsRemaining();

	// Shuffle the deck and show the result
	std::cout << "Now shuffling the deck, then printing the new order: \n";
	deck.Shuffle();
	std::cout << deck.ToString();
	std::cout << deck.CardsRemaining();

	// Reset the deck and show the result
	std::cout << "Resetting the deck: \n";
	deck.Initialize();
	std::cout << deck.DrawCard();
	std::cout << deck.CardsRemaining();
}


