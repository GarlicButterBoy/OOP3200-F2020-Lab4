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
	std::cout << std::to_string(deck.CardsRemaining());
	// Show the deck object as initialized
	Pause();

	// Draw the next card and show it
	std::cout << deck.DrawCard();
	std::cout << std::to_string(deck.CardsRemaining());

	// Draw a random card and show it
	std::cout << deck.RandomDraw();
	std::cout << std::to_string(deck.CardsRemaining());

	// Show the deck with the remaining cards
	//std::cout << deck.ToString();

	// Shuffle the deck and show the result
	deck.Shuffle();
	std::cout << deck.DrawCard();
	std::cout << std::to_string(deck.CardsRemaining());
	//std::cout << deck.ToString();

	// Reset the deck and show the result
	deck.Initialize();
	std::cout << deck.DrawCard();
	std::cout << std::to_string(deck.CardsRemaining());
	//std::cout << deck.ToString();
}


