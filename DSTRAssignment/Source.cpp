#include <iostream>
using namespace std;
//Node 

struct Node {
    int data;
    Node* next;
};

struct Item{
    //Item data
    Item* head;
    int size;
    string bookTitle;
    int quantity;
    string genre;
    float price;
    //Points to the next item
    Item* next;
   
    Item(){
        //Initialize Item Linked List
        this->head = NULL;
        this->size = 0;
    }

    void insertItemStart(
        string bookTitle, 
        int quantity, 
        string genre, 
        float price)
        {
            Item* newItem = new Item();
            newItem->bookTitle = bookTitle;
            newItem->quantity = quantity;
            newItem->genre = genre;
            newItem->price = price;
            newItem->next = head;
            head = newItem;
            size++;
        }

    void displayItems(){
        Item* currentItem;
        currentItem = head;

        while(currentItem != NULL){
            cout << "\n\n\n";
            cout << currentItem->bookTitle << ", ";
            cout << currentItem->quantity << ", ";
            cout << currentItem->genre << ", ";
            cout << currentItem->price;
            currentItem = currentItem->next;
        }
    }
};

struct Purchase{
    //Purchase data
    int purchaseId;
    Item* item;
    float totalPrice;

    //Points to the next purchase
    Purchase* next;
    Purchase(){
        //Initialize Purchase Linked List
    }
};

class LinkedList {

public:
    Node* head;
    int size;
    int getSize() {
        int size = 0;
        Node* current = head;
        while (current != NULL) {
            size++;
            current = current->next;
        }
        return size;
    }

    LinkedList() {
        this->size = 0;
        this->head = NULL;
    }

    void insertAtBeginning(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = head;
        head = newNode;
        size++;
    }

    void display() {
        Node* current;
        current = head;

        while (current != NULL) {
            cout << current->data << ", ";
            current = current->next;
        }
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        }
        else {
            Node* last = head;
            while (last->next != NULL) {
                last = last->next;
            }
                
            last->next = newNode;
            
        }
        size++;
    }

    void addNewPurchase() {

        //declare variables
        int bookchoice;
        int quantity;
        bool purchaseDone = false;
        int userchoice = 1;

        //declare new linked list 
        LinkedList a;

        //Create a loop to buy books until the user sets purchaseDone variable to false
        
        while (userchoice != 2) {

            //Show all items 
            cout << "\n\nWhat books to buy?\n\n" << endl;

            cout << "1. Harry Potter" << endl;
            cout << "2. Diary of A Wimpy Kid" << endl;
            cout << "3. 1984" << endl;
            cout << "4. Invincible" << endl;
            cin >> bookchoice;

            cout << "Quantity: " << endl;
            cin >> quantity;

            //add new nodes into linked list 
            a.insertAtEnd(bookchoice);

            cout << "\n\nWould you like to add more books?\n\n " << endl;
            cout << "1. Yes 2. No\n\n" << endl;
            cin >> userchoice; 

            //if user chooses 'No', the status of purchaseDone is true
            if (userchoice == 2) {
                purchaseDone = true;
                break;
            }

        }

        //display linked list items 

        cout << "\n\nYour receipt\n\n";
        a.display();

        // Find a way to display book names instead of the userchoice integer

    }

    void viewAllPurchases() {
        cout << "viewallpurchases" << endl;
    }
};

int main() {
     
    LinkedList list;

    //CLI

    //Add new purchase

    int wallet = 100;
    int userchoice;

    
    cout << "\n****************||Welcome Back, Manager||****************\n" << endl;
    cout << "*************||What would you like to do?||*************" << endl;


    cout << "1. Add new purchase" << endl;
    cout << "2. View all purchases" << endl;
    cout << "\n\n";

    cin >> userchoice;
       
    switch (userchoice) {
    case 1:
        cout << "Add New Purchase" << endl;
        list.addNewPurchase();
        break;
            
    case 2:
        cout << "view All Purchases" << endl;
        list.viewAllPurchases();
        break;
    default:
        cout << "Wrong choice. Please pick a valid choice." << endl;
    }


    //Display inserted items into item linked list (insertfrombeginning)
    
 /*   Item newItem;

    newItem.insertItemStart(1,"Test", 4, "horror", 2.4);
    newItem.insertItemStart(2,"test2", 2, "scifi", 3.4);

    newItem.displayItems();

    list.insertAtBeginning(1);
    list.insertAtBeginning(2);
    list.insertAtBeginning(3);
    list.insertAtBeginning(4);

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);

    list.display();
    */
    
    
}