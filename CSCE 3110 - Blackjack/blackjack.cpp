/*

ntk0025
CSCE 3110
Blackjack game using arrays for card suits, face, status, and score. linked List is used for discard pile with the data 
being displayed through an output file. 

*/

#include <iostream>		// input/output functionality
#include <ctime>		// randomize/shuffle cards in deck
#include <stdio.h>		// file manipulation and NULL 
#include <string>		// string functionality
#include <fstream>		// write data to file 

using namespace std;

// global declarations and initializations for card arrays 
int new_suit = 0;
string faces[13] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
string suits[4] = {"Diamonds", "Clubs", "Hearts", "Spades"};
string status[3] = {"In Play", "In Deck", "Discard Pile"};          // discard pile will act as linked list
int cardValue[13] = {11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10};

int count = 0;			// count for drawing cards for dealer and player
int totalPoints = 0;	// player points
int dealerPoints = 0;	// dealer points

// beginning -- linked list data structure

class Node
{
    public:
        int     data;   // stores user data
        Node    *next;  // pointer for linked list nodes
};
// add node to the front of the list
void push(Node **head_ref, int new_data)
{
    // allocate new node and store data
    Node *new_node = new Node();
    new_node->data = new_data;

    // assign new node to the head node at the front of the list
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
// add node to the back of the list
void append(Node **head_ref, int new_data)
{
    // create last node and assign it to head
    Node *last = (*head_ref);
    Node *new_node = new Node();

    // store data
    new_node->data = new_data;
    new_node->next = NULL;

    // if linked list is empty
    if (*head_ref == NULL)
    {
        cout << "linked list is empty" << endl;
        *head_ref = new_node;
        return;
    }

    // traverse to tail node
    while (last->next != NULL)
    {
        last = last->next;
    }

    // make new node the tail node
    last->next = new_node;
}
// add a new node after a given one
void insertAfter(Node *prev_node, int new_data)
{
    // check if given node is NULL
    if (prev_node == NULL)
    {
        cout << "node cannot be NULL" << endl;
        return;
    }

    // allocate memory for node and store data
    Node *new_node = new Node();
    new_node->data = new_data;

    // reassign nodes to correct new node position
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}
// delete given node
void deleteNode(Node **head_ref, int key)
{
    // store head node
    Node *temp = *head_ref;
    Node *prev = NULL;

    // if head node holds the key to be deleted
    if (temp != NULL && temp->data == key)
    {
        *head_ref = temp->next;
        delete temp;
        return;
    }
    // else search for the key to be deleted
    else
    {
        while (temp != NULL && temp->data != key)
        {
            prev = temp;
            temp = temp->next;
        }

        // if key is not present in linked list
        if (temp == NULL)
        {
            return;
        }
        // unlink node from list
        prev->next = temp->next;

        // free memory
        delete temp;
    }
}
// display linked list
void printList(Node *n)
{
    while (n != NULL)
    {
        cout << n->data << endl;
        n = n->next;
    }
    cout << endl;
}

// end -- linked list data structure

// struct for deck of cards
struct Card
{
    string suit;
    string face;
    int points;
    int status;
} deck[53];

// uses global variables to create deck of cards
void createDeck()
{
    for (int i = 0; i < 52; i++)
    {
        deck[i].face = faces[i % 13];
        deck[i].suit = suits[new_suit];
        deck[i].points = cardValue[i % 13];
        deck[i].status = 1;
        
        if ((i + 1) % 13 == 0)
            new_suit++;
    }
}

// shuffle cards using srand 
void shuffleDeck()
{
    srand((unsigned)time(0));
	for (int i = 0; i < 600; i++)
	{
		int a = rand() % 52;
		int b = rand() % 52;
		
		deck[52].face = deck[a].face;
		deck[52].suit = deck[a].suit;
		deck[52].points = deck[a].points;
		deck[52].status = deck[a].status;

		deck[a].face = deck[b].face;
		deck[a].suit = deck[b].suit;
		deck[a].points = deck[b].points;
		deck[a].status = deck[b].status;

		deck[b].face = deck[52].face;
		deck[b].suit = deck[52].suit;
		deck[b].points = deck[52].points;
		deck[b].status = deck[52].status;
	}
}

// player draws card
int drawCard(Node* head)
{
    // if card is in deck, draw and change status to in play
    if (deck[count].status == 1)
    {
        deck[count].status = 0;     // set card to "in play"
        cout << deck[count].face << " of " << deck[count].suit << " : " << deck[count].points << " points" << endl;
		
		// add to discard pile (linked list)
		push(&head, deck[count].points);

        totalPoints = totalPoints + deck[count].points;     // calculate player score
    }
    count++;

    return totalPoints;
}

// function for dealer to draw card
int dealerCard(Node* head)
{
    // if card is in deck, draw and change to in play
    if (deck[count].status == 1)
    {
        deck[count].status = 0;

        //cout << deck[count].face << " of " << deck[count].suit << " : " << deck[count].points << " points : " << status[deck[count].status] << endl;

		// add to discard pile (linked list)
		push(&head, deck[count].points);

        dealerPoints = dealerPoints + deck[count].points;   // calculate dealer score
    }
    count++;

    return dealerPoints;
}

// print deck array 
void printDeck()
{
    for (int i = 0; i < 52; i++)
    {
        cout << deck[i].face << " of " << deck[i].suit << " : Value of " << deck[i].points << endl;       
    }
}

int main()
{
    // declaration of boolean condition for input loop and user input
	Node* head = NULL;	// to implement linked list
    bool refl = 0;;
    string input;
	ofstream discard;	// output file stream for discard pile 
	
	discard.open("discard_pile.dat");	// create dat file for cards going to discard pile 

    cout << "Welcome to Blackjack" << endl;

    // create and shuffle deck
    createDeck();
    shuffleDeck();

    // compute dealer game and calculate dealer score
    while (dealerPoints <= 16)
    {
        dealerCard(head);
    }

    // automatically draw card for player
    drawCard(head);

    // looping condition for blackjack game
    while (refl == 0)
    {
        cout << "Your points: " << totalPoints << endl;

        // if player points are still under 21 ask user if they want to draw another card, else tally scores
        if (totalPoints < 21)
        {
            cout << "Draw another card? (y/n): "; cin >> input;
            if (input == "y")
            {
                drawCard(head);
            }
            // tally scores
            else
            {
                if (dealerPoints < totalPoints)
                {
					cout << endl;
                    cout << "YOU WIN" << endl;
                    cout << "Dealer points: " << dealerPoints << ", Player points: " << totalPoints << endl;
                    refl = 1;
                    break;                
                }
                else if (dealerPoints == totalPoints)
                {
					cout << endl;
                    cout << "TIE" << endl;
                    cout << "Dealer points: " << dealerPoints << ", Player points: " << totalPoints << endl;
                    refl = 1;
                    break;                 
                }
                else if ((dealerPoints > totalPoints) && dealerPoints <= 21)
                {
					cout << endl;
                    cout << "DEALER WINS" << endl;
                    cout << "Dealer points: " << dealerPoints << ", Player points: " << totalPoints << endl;
                    refl = 1;
                    break;               
                }
				else if ((dealerPoints > totalPoints) && dealerPoints > 21)
				{
					cout << endl;
					cout << "NO WINNERS" << endl;
					cout << "Dealer points: " << dealerPoints << ", Player points: " << totalPoints << endl;
					refl = 1;
					break;		
				}
            }
        }
        // if user points exceed 21, tally scores
        else if (totalPoints > 21)
        {
            if (dealerPoints > 21)
            {
				cout << endl;
                cout << "NO WINNERS" << endl;
                cout << "Dealer points: " << dealerPoints << ", Player points: " << totalPoints << endl;
                refl = 1;
                break;
            }
            else
            {
				cout << endl;
                cout << "DEALER WINS" << endl;
                cout << "Dealer points: " << dealerPoints << ", Player points: " << totalPoints << endl;
                refl = 1;
                break;
            }
        }
        // if user points equals 21, check for tie, else inform player of blackjack
        else if (totalPoints == 21)
        {
            if (dealerPoints == 21)
            {
				cout << endl;
                cout << "TIE" << endl;
                cout << "Dealer points: " << dealerPoints << ", Player points: " << totalPoints << endl;
                refl = 1;
                break;               
            }
            else 
            {
				cout << endl;
                cout << "BLACKJACK - YOU WIN" << endl;
                cout << "Dealer points: " << dealerPoints << ", Player points: " << totalPoints << endl;
                refl = 1;
                break;                  
            }
        }
    }
	
	discard << "Discard Pile Cards" << endl << endl;
	for (int i = 0; i < 52; i++)
	{
		if (deck[i].status == 0)
		{
			discard << deck[i].face << " of " << deck[i].suit << " (" << deck[i].points << ")" << endl;
		}
	}

    return 0;
}
