#include <iostream>
#include <iomanip> // for formatting output
#include <ctime>   // for time()
#include <cstdlib> // for srand() and rand()
#include <fstream>
#include <vector>
#include <set>  // Add this line for the set data structure

#ifdef _WIN32       
#include <Windows.h> // added sleep function for Windows
#else
#include <unistd.h> // added sleep function for Linux/Unix
#endif

using namespace std;

// Constants
const int NUM_ROWS = 5;
const int NUM_COLS = 6;
const double SALES_TAX_RATE = 0.07;

// A structure to store ticket & order details
struct Ticket {
    string itemName;
    int quantity;
    vector<pair<int, int>> selectedSeats;  // vector to store selected seats
    double itemPrice;
};

// Global vector to store ticket details
vector<Ticket> tickets;

Ticket ticket;

//Gobal variables
double total = 0.0; // running total
double itemPrice = 0.0;
int numTickets;
string itemName;
string MovieName;
int selectedRow;
int selectedCol;
int quantity; // quanities
double itemTotal; 
int amount_of_items = 0;


//snacks sub-menu(s)
void candy_submenu() {
    system("cls");
    int candy_type;

    cout << "\n\n" << endl;
    cout << "   |    Select the type of Candy     |" << endl;
    cout << "   |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|" << endl;
    cout << "   | 1 - Chocolate bars ...... $1.50 |" << endl;
    cout << "   | 2 - Gummy Bears ......... $1.75 |" << endl;
    cout << "   | 3 - Sour Patch Kids ..... $2.00 |" << endl;
    cout << "   | 4 - Skittles ............ $1.25 |" << endl;
    cout << "   | 5 - M&M's ............... $1.50 |" << endl;
    cout << "   | 6 - Reese's Pieces ...... $1.75 |" << endl;
    cout << "   | 7 - Twizzlers ........... $1.25 |" << endl;
    cout << "   | 8 - Jolly Ranchers ...... $1.50 |" << endl;
    cout << "   |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n" << endl;
    cout << "   Select the type of Candy: ";
    cin >> candy_type;

    switch (candy_type) {
    case 1:
        itemName = "Chocolate bars";
        itemPrice = 1.50;
        break;
    case 2:
        itemName = "Gummy Bears";
        itemPrice = 1.75;
        break;
    case 3:
        itemName = "Sour Patch Kids";
        itemPrice = 2.00;
        break;
    case 4:
        itemName = "Skittles";
        itemPrice = 1.25;
        break;
    case 5:
        itemName = "M&M's";
        itemPrice = 1.50;
        break;
    case 6:
        itemName = "Reese's Pieces";
        itemPrice = 1.75;
        break;
    case 7:
        itemName = "Twizzlers";
        itemPrice = 1.25;
        break;
    case 8:
        itemName = "Jolly Ranchers";
        itemPrice = 1.50;
        break;
    default:
        cout << "Invalid candy type selection." << endl;
        return; // Exit the submenu
    }
}

//food sub-menu(s)
void Popcorn_SubMenu() {
    system("cls");
    int popcorn_size;

    cout << "\n\n" << endl;
    cout << "   |     Select the size of Popcorn    |" << endl;
    cout << "   |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|" << endl;
    cout << "   | 1 - Large Popcorn ........ $3.50  |" << endl;
    cout << "   | 2 - Medium Popcorn ........$2.75  |" << endl;
    cout << "   | 3 - Small Popcorn ........ $2.00  |" << endl;
    cout << "   |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n" << endl;
    cout << "   Select the size of Popcorn: ";
    cin >> popcorn_size; 

    switch (popcorn_size) {
    case 1:
        itemName = "Large Popcorn";
        itemPrice = 3.50;
        break;
    case 2:
        itemName = "Medium Popcorn";
        itemPrice = 2.75;
        break;
    case 3:
        itemName = "Small Popcorn";
        itemPrice = 2.00;
        break;
    default:
        cout << "Invalid Popcorn type selection." << endl;
        return; // Exit the submenu
    }
    
}

void hamburger_submenu() {
    system("cls");
    int hamburger_type;

    cout << "\n\n" << endl;
    cout << "   |   Select the type of Hamburger   |" << endl;
    cout << "   |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|" << endl;
    cout << "   | 1 - Classic Hamburger .... $4.50 |" << endl;
    cout << "   | 2 - Cheeseburger ......... $5.00 |" << endl;
    cout << "   | 3 - Bacon Burger ......... $5.50 |" << endl;
    cout << "   |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n" << endl;
    cout << "   Select the type of Hamburger: ";
    cin >> hamburger_type;

    switch (hamburger_type) {
    case 1:
        itemName = "Classic Hamburger";
        itemPrice = 4.50;
        break;
    case 2:
        itemName = "Cheeseburger";
        itemPrice = 5.00;
        break;
    case 3:
        itemName = "Bacon Burger";
        itemPrice = 5.50;
        break;
    default:
        cout << "Invalid Hamburger type selection." << endl;
        return; // Exit the submenu
    }
}


//drink sub-menu(s)
void fountainsizes_SubMenu() {
    system("cls");
    int drink_size; 

    cout << "\n\n" << endl;
    cout << "   |  Select the size of Drink |" << endl;
    cout << "   |~~~~~~~~~~~~~~~~~~~~~~~~~~~|" << endl;
    cout << "   | 1 - Large ......... $4.50 |" << endl;
    cout << "   | 2 - Medium .........$3.75 |" << endl;
    cout << "   | 3 - Small ......... $2.00 |" << endl;
    cout << "   |~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n" << endl;
    cout << "   Select the size of Drink: ";
    cin >> drink_size; 

    switch (drink_size) { 
    case 1:
        itemName = "Large Drink";
        itemPrice = 4.50;
        break;
    case 2:
        itemName = "Medium Drink";
        itemPrice = 3.75;
        break;
    case 3:
        itemName = "Small Drink";
        itemPrice = 2.00;
        break;
    default:
        cout << "Invalid Drink type selection." << endl;
        return; // Exit the submenu
    }
}

void Icee_SubMenu() {
    system("cls");
    int icee_flavor;

    cout << "\n\n" << endl;
    cout << "   |     Select the Icee Flavor     |" << endl;
    cout << "   |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|" << endl;
    cout << "   | 1 - Cola .............. $3.00  |" << endl;
    cout << "   | 2 - Cherry .............$3.00  |" << endl;
    cout << "   | 3 - Blue Raspberry .... $3.00  |" << endl;
    cout << "   | 4 - Grape ............. $3.00  |" << endl;
    cout << "   | 5 - Lemon-Lime ........ $3.00  |" << endl;
    cout << "   |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n" << endl;
    cout << "   Select the Icee Flavor: ";
    cin >> icee_flavor;

    switch (icee_flavor) {
    case 1:
        itemName = "Cola Icee";
        itemPrice = 3.00;
        break;
    case 2:
        itemName = "Cherry Icee";
        itemPrice = 3.00;
        break;
    case 3:
        itemName = "Blue Raspberry Icee";
        itemPrice = 3.00;
        break;
    case 4:
        itemName = "Grape Icee";
        itemPrice = 3.00;
        break;
    case 5:
        itemName = "Lemon-Lime Icee";
        itemPrice = 3.00;
        break;
    default:
        cout << "Invalid Icee flavor selection." << endl;
        return; // Exit the submenu
    }
}

//food main menu
void displayFoodMenu() {
    // Clear screen before menu
    system("cls");

    // Display the main menu with items and prices

    cout << "   |            Snacks              |     |            Foods               |" << endl;
    cout << "   |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|     |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|" << endl;
    cout << "   | 1 - Onion Rings ........ $4.50 |     | 6 - Popcorn .................. |" << endl;
    cout << "   | 2 - Soft Pretzel ....... $2.50 |     | 7 - Hamburger ................ |" << endl;
    cout << "   | 3 - Nachos ............. $3.50 |     | 8 - Chicken Strips ..... $4.40 |" << endl;
    cout << "   | 4 - Candy .................... |     | 9 - Corn Dog ........... $2.50 |" << endl;
    cout << "   | 5 - Mozzerella Sticks .. $5.50 |     | 10 - Hot Dog ........... $4.50 |" << endl;
    cout << "   |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|     | 11 - 7 inch Pizza ...... $5.00 |" << endl;
    cout << "                                          |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n\n" << endl;

    cout << "   |           Beverages            |" << endl;
    cout << "   |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|" << endl;
    cout << "   | 12 - Fountain Drink .......... |" << endl;
    cout << "   | 13 - Icee .................... |" << endl;
    cout << "   | 14 - Apple Juice ....... $2.25 |" << endl;
    cout << "   | 15 - Chocolate Milk .... $2.25 |" << endl;
    cout << "   | 16 - Bottled Water ..... $1.00 |" << endl;
    cout << "   |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n" << endl;

    cout << "   |---------------------------|" << endl;
    cout << "   | 0 - end selection         |" << endl;
    cout << "   |---------------------------|" << endl;
}


// Define the array for available tickets
int ticketsAvailable[5];

void initializeTicketsAvailable() {
    // Seed the random number generator
    srand(time(0));

    for (int i = 0; i < 5; i++) {
        // Generate a random number of available tickets between 0 and 30
        ticketsAvailable[i] = rand() % 31;
    }
}

void displayMovieChoices() {
    // Clear screen before menu
    system("cls");

    cout << "   |                                           Movies                                           |" << endl;
    cout << "   |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|" << endl;

    // Create an array to store the movie names and genres
    string movies[5] = {
        "The Shift .......................... Mystery & Thriller, PG-13",
        "Wish ................................. Comedy,Animation, PG   ",
        "The Hunger Games(2023)......... Action/Adventure, Drama, PG-13",
        "Trolls Band Together .................... Kids & Family, PG   ",
        "Napoleon ......................... Historical Film, War, R    "
    };

    // Loop through the movies and display them along with available tickets
    for (int i = 0; i < 5; i++) {
        cout << "   | " << i + 1 << " - " << movies[i] << " | Available Tickets: " << setw(2) << ticketsAvailable[i] << " |" << endl;
    }

    cout << "   |                                                                                            |" << endl;
    cout << "   |               Adult - $15              Child - $10             Senior - $7                 |" << endl;
    cout << "   |                                                                                            |" << endl;
    cout << "   |                                     0 - end selection                                      |" << endl;
    cout << "   |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|" << endl;
                                         
}

/////////////////////////////////////////////////////////////////

// Multi-dimensional array to represent the seating chart for each movie
int seats[NUM_ROWS][NUM_COLS];

// Function to initialize the seating chart with random values
void initializeSeatingChart() {
    srand(time(0)); // Seed for random number generation

    for (int i = 0; i < NUM_ROWS; ++i) {
        for (int j = 0; j < NUM_COLS; ++j) {
            // Check if there are available tickets for the corresponding movie
            if (ticketsAvailable[i] > 0) {
                // Generate a random number (0 or 1) to indicate seat availability
                seats[i][j] = rand() % 2;
                // If the seat is available, decrement the available tickets for the movie
                if (seats[i][j] == 1) {
                    ticketsAvailable[i]--;
                }
            } else {
                // If no available tickets, set all seats to reserved (0)
                seats[i][j] = 0;
            }
        }
    }
}

// Function to display the seating chart for the selected movie
void displaySeatingChart(const string& movieName) {
    cout << "\nSeating Chart for '" << movieName << "':" << endl;

    for (int i = 0; i < NUM_ROWS; ++i) {
        for (int j = 0; j < NUM_COLS; ++j) {
            if (seats[i][j] == 1) {
                cout << "O "; // Available seat
            }
            else {
                cout << "X "; // Reserved seat
            }
        }
        cout << endl;
    }
}

// Function to check if a seat is available and reserve it
bool reserveSeat(int row, int col) {
    if (seats[row][col] == 1) {
        seats[row][col] = 0; // Reserve the seat
        return true;
    }
    else {
        return false; // Seat is already reserved
    }
}

///////////////////////////////////////////////////////////////////////

void tixMenu() {

    int sel; //selections


    initializeTicketsAvailable(); //populate each of the array elements for number of tickets with random values from 0 to 30.
    initializeSeatingChart(); // Initialize the seating chart  

    while (true) {

        // Clear the screen and display the movie choices and ticket prices
        displayMovieChoices();
        cout << fixed << setprecision(2); // Set output to two decimal places
        cout << "\nRunning Total: $" << total << endl;

        int movieSelection;
        cout << "\nEnter the movie number (0 to end selection): ";
        cin >> movieSelection;

        if (movieSelection == 0) {
            // Exit the loop if the user chooses 0
            break;
        }

        if (movieSelection < 1 || movieSelection > 5) {
            cout << "Invalid movie selection. Please try again." << endl;
            Sleep(3000);
            continue; // Skip the rest of the loop for invalid selections
        }


        // Get the user's age group (Adult, Child, or Senior)
        int ageGroup;
        cout << "\nSelect your age group (1 - Adult, 2 - Child, 3 - Senior): ";
        cin >> ageGroup;

        if (ageGroup < 1 || ageGroup > 3) {
            cout << "Invalid age group selection. Please try again." << endl;
            Sleep(3000);
            continue; // Skip the rest of the loop for invalid selections
        }

        //shows Available seats from user selected movie
        switch (movieSelection)
        {
        case 1:
            MovieName = "The Shift";
            cout << "\nAvailable seats for '" << MovieName << "': " << ticketsAvailable[movieSelection - 1] << endl;
            break;
        case 2:
            MovieName = "Wish";
            cout << "\nAvailable seats for '" << MovieName << "': " << ticketsAvailable[movieSelection - 1] << endl;
            break;
        case 3:
            MovieName = "The Hunger Games(2023)";         
            cout << "\nAvailable seats for '" << MovieName << "': " << ticketsAvailable[movieSelection - 1] << endl;
            break;
        case 4:
            MovieName = "Trolls Band Together";
            cout << "\nAvailable seats for '" << MovieName << "': " << ticketsAvailable[movieSelection - 1] << endl;
            break;
        case 5:
            MovieName = "Napoleon";
            cout << "\nAvailable seats for '" << MovieName << "': " << ticketsAvailable[movieSelection - 1] << endl;
            break;

        }


        // Get the number of tickets the user wants to purchase
        
        cout << "Enter the number of tickets you want to purchase: ";
        cin >> numTickets;

        // Check if the requested number of tickets is available
        if (numTickets > ticketsAvailable[movieSelection - 1]) {
            cout << "Sorry, there are not enough tickets available for that movie." << endl;
            cout << "Please try again." << endl;
            Sleep(3000);
            continue;
        }

       
        
        //////////////////////////////////////////////displaySeatingChart
        displaySeatingChart(MovieName);

        for (int p = 0; p < numTickets; p++) {
            cout << "Ticket " << p + 1 << ": Enter the row and column for your seat (e.g., 1 2): ";
            cin >> selectedRow >> selectedCol;

            // Validate the seat selection
            if (selectedRow < 1 || selectedRow > NUM_ROWS || selectedCol < 1 || selectedCol > NUM_COLS) {
                cout << "Invalid seat selection. Please try again." << endl;
                Sleep(3000);
                p--;  // Decrement p to re-enter the seat selection for the same ticket
                continue;
            }

            // Check if the selected seat is available
            if (!reserveSeat(selectedRow - 1, selectedCol - 1)) {
                cout << "Sorry, the selected seat is already reserved. Please choose another seat." << endl;
                Sleep(3000);
                p--;  // Decrement p to re-enter the seat selection for the same ticket
                continue;
            }

            // Store the selected seat in the vector
            ticket.selectedSeats.push_back({ selectedRow, selectedCol });
        }

        ///////////////////////////////////////////////////////////////////////

        // Calculate the cost for the selected movie and age group
        double ticketPrice = 0.0;
        switch (ageGroup) {
        case 1: // Adult
            ticketPrice = 15.00;
            break;
        case 2: // Child
            ticketPrice = 10.00;
            break;
        case 3: // Senior
            ticketPrice = 7.00;
            break;
        }

        double movieCost = numTickets * ticketPrice;
        total += movieCost;


        // Deduct the sold tickets from the available tickets
        ticketsAvailable[movieSelection - 1] -= numTickets;

        //////////////////////////////////////////////////////////////////////
        // Store ticket details in the vector
        ticket.itemName = MovieName;
        ticket.quantity = numTickets;
        ticket.itemPrice = ticketPrice;
        
        // Add the ticket to the vector
        tickets.push_back(ticket); 
        //////////////////////////////////////////////////////////////////////

        // Display the user's current selection and running total
        cout << "You have selected " << numTickets << " " << itemName << " tickets for a total of $" << movieCost << endl;
        cout << "\nRunning Total: $" << total << endl;

        cout << "\nWould you like to make another movie selection? (1 - Yes, 0 - No): ";
        cin >> sel;
        if (sel == 0) {
            break; // Exit the loop if the user chooses 0
        }
    }
}



void concMenu() {
    // local variables
    const double salesTaxRate = 0.07; // Tax
    int sel; //selections
    int quantity; // quanities

    // Clear screen and Food display menu initially
    displayFoodMenu();

    cout << fixed << setprecision(2); // Set output to two decimal places

    cout << "\nRunning Total: $" << total << endl;

    while (true) {

        // Seed the random number generator
        srand(time(0));

        // Generate a random talk_option (0 to 7)
        int talk_option = rand() % 8;

        if (talk_option == 0) {
            cout << "What can I get for you? ";
        }
        else if (talk_option == 1) {
            cout << "Is there anything else you'd like to order? ";
        }
        else if (talk_option == 2) {
            cout << "Are there any other snacks or drinks you'd like to add? ";
        }
        else if (talk_option == 3) {
            cout << "Do you have any specific cravings from our menu? ";
        }
        else if (talk_option == 4) {
            cout << "Tell me, what's your taste bud's desire today? ";
        }
        else if (talk_option == 5) {
            cout << "What's your flavor of the day? ";
        }
        else if (talk_option == 6) {
            cout << "Is there a particular treat that catches your eye? ";
        }
        else if (talk_option == 7) {
            cout << "Anything special you'd like to indulge in tonight? ";
        }

        cin >> sel;
        cin.ignore();

        if (sel == 0) {
            break; // Exit the loop if the user chooses 0
        }

        switch (sel) {
        case 1:
            itemName = "Onion Rings";
            itemPrice = 4.50;
            break;
        case 2:
            itemName = "Soft Pretzel";
            itemPrice = 2.50;
            break;
        case 3:
            itemName = "Nachos";
            itemPrice = 3.50;
            break;
        case 4:
            candy_submenu();
            break;
        case 5:
            itemName = "Mozzerella Sticks";
            itemPrice = 5.50;
            break;
        case 6:
            Popcorn_SubMenu();
            break;
        case 7:
            hamburger_submenu();
            break;
        case 8:
            itemName = "Chicken Strips";
            itemPrice = 4.40;
            break;
        case 9:
            itemName = "Corn Dog";
            itemPrice = 2.50;
            break;
        case 10:
            itemName = "Hot Dog";
            itemPrice = 4.50;
            break;
        case 11:
            itemName = "7 inch Pizza";
            itemPrice = 5.00;
            break;
        case 12:
            fountainsizes_SubMenu();
            break;
        case 13:
            Icee_SubMenu();
            break;
        case 14:
            itemName = "Apple Juice";
            itemPrice = 2.25;
            break;
        case 15:
            itemName = "Chocolate Milk";
            itemPrice = 2.25;
            break;
        case 16:
            itemName = "Bottled Water";
            itemPrice = 1.00;
            break;
        default:
            cout << "Invalid selection. Please try again." << endl;
            continue; // Skip the rest of the loop for invalid selections
        }

        cout << "How many " << itemName << " would you like to purchase: ";
        cin >> quantity;
        cin.ignore();

        double itemTotal = itemPrice * quantity;
        total += itemTotal;

        

        
        ticket.itemName = itemName;
        ticket.quantity = quantity;
        ticket.itemPrice = itemPrice;
        tickets.push_back(ticket);

        // Clear screen and display menu after each selection
        displayFoodMenu(); 

        // Display the user's current selection and running total
        cout << "\nYou have selected " << quantity << " " << itemName << "(s) for a total of $" << itemTotal << endl;
        cout << "\nRunning Total: $" << total << endl;
    }
}

// Function for displaying the receipt
void receipt() {
    double salesTax = total * SALES_TAX_RATE;
    double finalTotal = total + salesTax;

    // Display a summary receipt for each item purchased
    cout << "\n\n\t\tReceipt Summary\n";
    cout << "----------------------------------------------\n";

    // Loop through the purchased items and display details
    cout << left << setw(25) << "Item" << setw(10) << "Quantity" << setw(10) << "Price" << endl;

    for (size_t i = 0; i < tickets.size(); ++i) {
        const Ticket& ticket = tickets[i];

        cout << left << setw(25) << ticket.itemName << setw(10) << ticket.quantity << setw(10) << ticket.itemPrice << endl;
    }

    cout << "----------------------------------------------\n";
    cout << "Subtotal: $" << total << endl;
    cout << "Sales Tax (7%): $" << salesTax << endl;
    cout << "Total (including tax): $" << finalTotal << endl;
}

void printTicket() {
    ofstream ticketFile("ticket.txt"); // Open a text file for writing
    if (!ticketFile.is_open()) {
        cout << "Error creating ticket file. Please check permissions." << endl;
        return;
    }

    // Iterate over tickets and print details for movie tickets
    for (size_t i = 0; i < tickets.size(); ++i) {
        const Ticket& ticket = tickets[i];

        // Check if the item is a movie by comparing with the specified movie names
        if (ticket.itemName == "The Shift" ||
            ticket.itemName == "Wish" ||
            ticket.itemName == "The Hunger Games(2023)" ||
            ticket.itemName == "Trolls Band Together" ||
            ticket.itemName == "Napoleon") {

            ticketFile << "\tCineMagic Theater Ticket\n";
            ticketFile << "----------------------------------------------\n";
            ticketFile << "Movie: " << ticket.itemName << endl;

            // Print selected seats
            ticketFile << "Selected Seats: ";
            for (const auto& seat : ticket.selectedSeats) {
                ticketFile << "Row " << seat.first << ", Column " << seat.second << "\n\t\t";
            }
            ticketFile << "\n";

            ticketFile << "----------------------------------------------\n";
            ticketFile << "Enjoy your movie!\n\n\n\n";
        }
    }

    // Close the file
    ticketFile.close();

    cout << "Ticket(s) printed successfully. Check 'ticket.txt' for details." << endl;
}

int main() {
    //greetings 
    cout << "\n\t\tWelcome to CineMagic Theater!\n";
    Sleep(3000);
    
    //prompt ticket menu
    tixMenu();

    //prompt concession menu
    concMenu();

    // prompt receipt 
    //*** add & show user all the things they order on the receipt.
    receipt(); 
    printTicket(); 
    

    // Pause to allow the user to see the information 
    cout << "\nPress Enter to continue...";
    cin.get();

    return 0;
}
