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
    int bookId;
    int size;
    string bookTitle;
    int quantity;
    string genre;
    float price;
    Item* next;
    Item* prev;
    //Points to the next item
   
    Item(){
        //Initialize Item Linked List
        this->head = NULL;
        this->size = 0;
        this->next = NULL;
        this->prev = NULL;
    }

        
    void insertItemStart(
        string bookTitle, 
        int quantity, 
        string genre, 
        float price)
        {
            Item* newItem = new Item();
            newItem->bookId = bookId;
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
            cout << currentItem->bookId << ", ";
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
    Purchase* head;
    Purchase* size;
    int purchaseId;
    Item* item;
    float totalPrice;


    //Points to the next purchase
    Purchase* next;
    
    //Points to the previous purchase
    Purchase* prev;

    Purchase() {
        //Initialize Purchase Linked List
        this->head = NULL;
        this->size = 0;
    };

    void addNewPurchase() {


        //declare variables
        int bookchoice;
        int quantity;
        bool purchaseDone = false;
        int userchoice = 1;

        //declare new linked list 
        /*LinkedList a;*/


        //Create a loop to buy books until the user sets purchaseDone variable to false

        while (userchoice != 2) {
            Purchase purchase;
            Item newItem;

            //Show all items 
            cout << "\n\nWhat books to buy?\n\n" << endl;
            cout << "1. Harry Potter" << endl;
            cout << "2. Diary of A Wimpy Kid" << endl;
            cout << "3. 1984" << endl;
            cout << "4. Invincible" << endl;

            cin >> bookchoice;

            /*insertItemStart wrong constructor content. Change it so that
            the addNewPurchase method have each book fields are its own 
            variable. This makes it so it can pass through insertItemStart method*/
            newItem.insertItemStart(bookchoice);

            cout << "Quantity: " << endl;
            cin >> quantity;

            //add new nodes into linked list

            /*IMPORTANT! Need to somehow add the item contents into an Item object 
            instead of a pointer Item object and then insertAtEnd(Item)*/
            purchase.insertAtEnd(newItem);

            cout << "\n\nWould you like to add more books?\n\n " << endl;
            cout << "1. Yes 2. No\n\n" << endl;
            cin >> userchoice;

            //if user chooses 'No', the status of purchaseDone is true
            if (userchoice == 2) {
                purchaseDone = true;
                break;
                cout << "\n\nYour receipt\n\n";
                
                purchase.display();
            }

        }

        

    }

    void insertAtBeginning(Item* item) {
        Purchase* newPurchase = new Purchase;
        newPurchase->item = item;
        newPurchase->next = head;
        head = newPurchase;
        size++;
    }

    void display() {
        Purchase* current;
        current = head;

        while (current != NULL) {
            //Check this for display errors
            cout << current->item << ", ";
            current = current->next;
        }
    }

    void insertAtEnd(Item* item) {
        Purchase* newPurchase = new Purchase;
        newPurchase->item = item;
        newPurchase->next = NULL;

        if (head == NULL) {
            head = newPurchase;
        }
        else {
            Purchase* last = head;
            while (last->next != NULL) {
                last = last->next;
            }

            last->next = newPurchase;

        }
        size++;
    }



    void viewAllPurchases() {
        //Not done yet
        cout << "viewallpurchases" << endl;
    }

    //display linked list items 

    

    // Find a way to display book names instead of the userchoice integer

};



int main() {
    
    //Unexisting LinkedList class (remove later)
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


}