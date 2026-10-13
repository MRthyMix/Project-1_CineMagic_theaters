#include <iostream>
#include <iomanip> // for formatting output
#include <ctime>   // for time()
#include <cstdlib> // for srand() and rand()
#include <fstream>
#include <limits>  // for numeric_limits (clearing bad input)
#include <string>
#include <vector>

#ifdef _WIN32
#ifndef NOMINMAX
#define NOMINMAX     // stop Windows.h from defining min/max macros
#endif
#include <Windows.h> // added sleep function for Windows
#else
#include <unistd.h> // added sleep function for Linux/Unix
#endif

using namespace std;

// Constants
const int NUM_MOVIES = 5;
const int NUM_ROWS = 5;
const int NUM_COLS = 6;
const double SALES_TAX_RATE = 0.07;

// A structure to store ticket & order details
struct Ticket {
    string itemName;
    int quantity = 0;
    vector<pair<int, int>> selectedSeats;  // vector to store selected seats
    double itemPrice = 0.0;
    bool isMovie = false;                  // true for movie tickets, false for concessions
};

// Global vector to store ticket details
vector<Ticket> tickets;

//Gobal variables
double total = 0.0; // running total
double itemPrice = 0.0;
string itemName;

// Movie names (shared by the menu, the seat lookup and the ticket printout)
const string movieNames[NUM_MOVIES] = {
    "The Shift",
    "Wish",
    "The Hunger Games(2023)",
    "Trolls Band Together",
    "Napoleon"
};


// Pause for the given number of milliseconds
void pauseMs(int ms) {
#ifdef _WIN32
    Sleep(ms);
#else
    usleep(ms * 1000);
#endif
}

// Clear the console window
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Read a whole number from the user. If they type something that isn't a
// number (like a letter), ask again instead of getting stuck in a loop.
int readInt() {
    int value;
    while (!(cin >> value)) {
        if (cin.eof()) {
            exit(0); // input closed, nothing more to read
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter a number: ";
    }
    return value;
}


//snacks sub-menu(s)
// Each submenu sets itemName/itemPrice and returns true, or returns false on an invalid choice.
bool candy_submenu() {
    clearScreen();
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
    candy_type = readInt();

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
        return false; // Exit the submenu
    }
    return true;
}

//food sub-menu(s)
bool Popcorn_SubMenu() {
    clearScreen();
    int popcorn_size;

    cout << "\n\n" << endl;
    cout << "   |     Select the size of Popcorn    |" << endl;
    cout << "   |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|" << endl;
    cout << "   | 1 - Large Popcorn ........ $3.50  |" << endl;
    cout << "   | 2 - Medium Popcorn ........$2.75  |" << endl;
    cout << "   | 3 - Small Popcorn ........ $2.00  |" << endl;
    cout << "   |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n" << endl;
    cout << "   Select the size of Popcorn: ";
    popcorn_size = readInt();

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
        return false; // Exit the submenu
    }
    return true;
}

bool hamburger_submenu() {
    clearScreen();
    int hamburger_type;

    cout << "\n\n" << endl;
    cout << "   |   Select the type of Hamburger   |" << endl;
    cout << "   |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|" << endl;
    cout << "   | 1 - Classic Hamburger .... $4.50 |" << endl;
    cout << "   | 2 - Cheeseburger ......... $5.00 |" << endl;
    cout << "   | 3 - Bacon Burger ......... $5.50 |" << endl;
    cout << "   |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n" << endl;
    cout << "   Select the type of Hamburger: ";
    hamburger_type = readInt();

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
        return false; // Exit the submenu
    }
    return true;
}


//drink sub-menu(s)
bool fountainsizes_SubMenu() {
    clearScreen();
    int drink_size;

    cout << "\n\n" << endl;
    cout << "   |  Select the size of Drink |" << endl;
    cout << "   |~~~~~~~~~~~~~~~~~~~~~~~~~~~|" << endl;
    cout << "   | 1 - Large ......... $4.50 |" << endl;
    cout << "   | 2 - Medium .........$3.75 |" << endl;
    cout << "   | 3 - Small ......... $2.00 |" << endl;
    cout << "   |~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n" << endl;
    cout << "   Select the size of Drink: ";
    drink_size = readInt();

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
        return false; // Exit the submenu
    }
    return true;
}

bool Icee_SubMenu() {
    clearScreen();
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
    icee_flavor = readInt();

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
        return false; // Exit the submenu
    }
    return true;
}

//food main menu
void displayFoodMenu() {
    // Clear screen before menu
    clearScreen();

    // Display the main menu with items and prices

    cout << "   |            Snacks              |     |            Foods               |" << endl;
    cout << "   |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|     |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|" << endl;
    cout << "   | 1 - Onion Rings ........ $4.50 |     | 6 - Popcorn .................. |" << endl;
    cout << "   | 2 - Soft Pretzel ....... $2.50 |     | 7 - Hamburger ................ |" << endl;
    cout << "   | 3 - Nachos ............. $3.50 |     | 8 - Chicken Strips ..... $4.40 |" << endl;
    cout << "   | 4 - Candy .................... |     | 9 - Corn Dog ........... $2.50 |" << endl;
    cout << "   | 5 - Mozzarella Sticks .. $5.50 |     | 10 - Hot Dog ........... $4.50 |" << endl;
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


// Define the array for available tickets (one count per movie)
int ticketsAvailable[NUM_MOVIES];

// Multi-dimensional array to represent the seating chart for each movie
// 1 = open seat, 0 = reserved seat
int seats[NUM_MOVIES][NUM_ROWS][NUM_COLS];

// Function to fill each movie's seating chart with a random number of open seats
// (0 to 30) and keep ticketsAvailable equal to the number of open seats.
void initializeSeatingChart() {
    const int totalSeats = NUM_ROWS * NUM_COLS;

    for (int m = 0; m < NUM_MOVIES; ++m) {
        // Start with every seat reserved
        for (int i = 0; i < NUM_ROWS; ++i) {
            for (int j = 0; j < NUM_COLS; ++j) {
                seats[m][i][j] = 0;
            }
        }

        // Generate a random number of available tickets between 0 and 30
        int openSeats = rand() % (totalSeats + 1);
        ticketsAvailable[m] = openSeats;

        // Open that many randomly chosen seats
        while (openSeats > 0) {
            int r = rand() % NUM_ROWS;
            int c = rand() % NUM_COLS;
            if (seats[m][r][c] == 0) {
                seats[m][r][c] = 1;
                openSeats--;
            }
        }
    }
}

void displayMovieChoices() {
    // Clear screen before menu
    clearScreen();

    cout << "   |                                           Movies                                           |" << endl;
    cout << "   |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|" << endl;

    // Create an array to store the movie names and genres
    string movies[NUM_MOVIES] = {
        "The Shift .......................... Mystery & Thriller, PG-13",
        "Wish ................................. Comedy,Animation, PG   ",
        "The Hunger Games(2023)......... Action/Adventure, Drama, PG-13",
        "Trolls Band Together .................... Kids & Family, PG   ",
        "Napoleon ......................... Historical Film, War, R    "
    };

    // Loop through the movies and display them along with available tickets
    for (int i = 0; i < NUM_MOVIES; i++) {
        cout << "   | " << i + 1 << " - " << movies[i] << " | Available Tickets: " << setw(2) << ticketsAvailable[i] << " |" << endl;
    }

    cout << "   |                                                                                            |" << endl;
    cout << "   |               Adult - $15              Child - $10             Senior - $7                 |" << endl;
    cout << "   |                                                                                            |" << endl;
    cout << "   |                                     0 - end selection                                      |" << endl;
    cout << "   |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|" << endl;

}

/////////////////////////////////////////////////////////////////

// Function to display the seating chart for the selected movie
void displaySeatingChart(int movie) {
    cout << "\nSeating Chart for '" << movieNames[movie] << "' (O = open, X = taken):" << endl;

    // Column numbers across the top
    cout << "      ";
    for (int j = 0; j < NUM_COLS; ++j) {
        cout << j + 1 << " ";
    }
    cout << endl;

    for (int i = 0; i < NUM_ROWS; ++i) {
        cout << "Row " << i + 1 << " ";
        for (int j = 0; j < NUM_COLS; ++j) {
            if (seats[movie][i][j] == 1) {
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
bool reserveSeat(int movie, int row, int col) {
    if (seats[movie][row][col] == 1) {
        seats[movie][row][col] = 0; // Reserve the seat
        return true;
    }
    else {
        return false; // Seat is already reserved
    }
}

///////////////////////////////////////////////////////////////////////

void tixMenu() {

    int sel; //selections

    initializeSeatingChart(); // Initialize the seating charts and available ticket counts

    while (true) {

        // Clear the screen and display the movie choices and ticket prices
        displayMovieChoices();
        cout << fixed << setprecision(2); // Set output to two decimal places
        cout << "\nRunning Total: $" << total << endl;

        int movieSelection;
        cout << "\nEnter the movie number (0 to end selection): ";
        movieSelection = readInt();

        if (movieSelection == 0) {
            // Exit the loop if the user chooses 0
            break;
        }

        if (movieSelection < 1 || movieSelection > NUM_MOVIES) {
            cout << "Invalid movie selection. Please try again." << endl;
            pauseMs(3000);
            continue; // Skip the rest of the loop for invalid selections
        }

        int movie = movieSelection - 1;
        string movieName = movieNames[movie];

        if (ticketsAvailable[movie] == 0) {
            cout << "Sorry, '" << movieName << "' is sold out. Please pick another movie." << endl;
            pauseMs(3000);
            continue;
        }

        // Get the user's age group (Adult, Child, or Senior)
        int ageGroup;
        cout << "\nSelect your age group (1 - Adult, 2 - Child, 3 - Senior): ";
        ageGroup = readInt();

        if (ageGroup < 1 || ageGroup > 3) {
            cout << "Invalid age group selection. Please try again." << endl;
            pauseMs(3000);
            continue; // Skip the rest of the loop for invalid selections
        }

        //shows Available seats from user selected movie
        cout << "\nAvailable seats for '" << movieName << "': " << ticketsAvailable[movie] << endl;

        // Get the number of tickets the user wants to purchase
        cout << "Enter the number of tickets you want to purchase: ";
        int numTickets = readInt();

        if (numTickets < 1) {
            cout << "You need to buy at least one ticket. Please try again." << endl;
            pauseMs(3000);
            continue;
        }

        // Check if the requested number of tickets is available
        if (numTickets > ticketsAvailable[movie]) {
            cout << "Sorry, there are not enough tickets available for that movie." << endl;
            cout << "Please try again." << endl;
            pauseMs(3000);
            continue;
        }

        //////////////////////////////////////////////displaySeatingChart
        displaySeatingChart(movie);

        // A fresh ticket for this movie, so seats from earlier orders don't carry over
        Ticket ticket;

        for (int p = 0; p < numTickets; p++) {
            cout << "Ticket " << p + 1 << ": Enter the row and column for your seat (e.g., 1 2): ";
            int selectedRow = readInt();
            int selectedCol = readInt();

            // Validate the seat selection
            if (selectedRow < 1 || selectedRow > NUM_ROWS || selectedCol < 1 || selectedCol > NUM_COLS) {
                cout << "Invalid seat selection. Please try again." << endl;
                p--;  // Decrement p to re-enter the seat selection for the same ticket
                continue;
            }

            // Check if the selected seat is available
            if (!reserveSeat(movie, selectedRow - 1, selectedCol - 1)) {
                cout << "Sorry, the selected seat is already reserved. Please choose another seat." << endl;
                p--;  // Decrement p to re-enter the seat selection for the same ticket
                continue;
            }

            // Store the selected seat in the vector
            ticket.selectedSeats.push_back({ selectedRow, selectedCol });
        }

        ///////////////////////////////////////////////////////////////////////

        // Calculate the cost for the selected movie and age group
        double ticketPrice = 0.0;
        string ageName;
        switch (ageGroup) {
        case 1: // Adult
            ticketPrice = 15.00;
            ageName = "Adult";
            break;
        case 2: // Child
            ticketPrice = 10.00;
            ageName = "Child";
            break;
        case 3: // Senior
            ticketPrice = 7.00;
            ageName = "Senior";
            break;
        }

        double movieCost = numTickets * ticketPrice;
        total += movieCost;

        // Deduct the sold tickets from the available tickets
        ticketsAvailable[movie] -= numTickets;

        //////////////////////////////////////////////////////////////////////
        // Store ticket details in the vector
        ticket.itemName = movieName;
        ticket.quantity = numTickets;
        ticket.itemPrice = ticketPrice;
        ticket.isMovie = true;

        // Add the ticket to the vector
        tickets.push_back(ticket);
        //////////////////////////////////////////////////////////////////////

        // Display the user's current selection and running total
        cout << "\nYou have selected " << numTickets << " " << ageName << " ticket(s) for '" << movieName << "' for a total of $" << movieCost << endl;
        cout << "\nRunning Total: $" << total << endl;

        cout << "\nWould you like to make another movie selection? (1 - Yes, 0 - No): ";
        sel = readInt();
        if (sel == 0) {
            break; // Exit the loop if the user chooses 0
        }
    }
}



void concMenu() {
    // local variables
    int sel; //selections
    int quantity; // quanities

    // Clear screen and Food display menu initially
    displayFoodMenu();

    cout << fixed << setprecision(2); // Set output to two decimal places

    cout << "\nRunning Total: $" << total << endl;

    // Things the cashier might say
    const string talkOptions[8] = {
        "What can I get for you? ",
        "Is there anything else you'd like to order? ",
        "Are there any other snacks or drinks you'd like to add? ",
        "Do you have any specific cravings from our menu? ",
        "Tell me, what's your taste bud's desire today? ",
        "What's your flavor of the day? ",
        "Is there a particular treat that catches your eye? ",
        "Anything special you'd like to indulge in tonight? "
    };

    while (true) {

        // Pick a random talk_option (0 to 7)
        cout << "\n" << talkOptions[rand() % 8];

        sel = readInt();

        if (sel == 0) {
            break; // Exit the loop if the user chooses 0
        }

        bool validItem = true;

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
            validItem = candy_submenu();
            break;
        case 5:
            itemName = "Mozzarella Sticks";
            itemPrice = 5.50;
            break;
        case 6:
            validItem = Popcorn_SubMenu();
            break;
        case 7:
            validItem = hamburger_submenu();
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
            validItem = fountainsizes_SubMenu();
            break;
        case 13:
            validItem = Icee_SubMenu();
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
            validItem = false;
            break;
        }

        if (!validItem) {
            pauseMs(1500);
            displayFoodMenu();
            cout << "\nInvalid selection. Please try again." << endl;
            cout << "\nRunning Total: $" << total << endl;
            continue; // Skip the rest of the loop for invalid selections
        }

        cout << "How many " << itemName << " would you like to purchase: ";
        quantity = readInt();

        if (quantity < 1) {
            displayFoodMenu();
            cout << "\nNo " << itemName << " added." << endl;
            cout << "\nRunning Total: $" << total << endl;
            continue;
        }

        double itemTotal = itemPrice * quantity;
        total += itemTotal;

        Ticket item;
        item.itemName = itemName;
        item.quantity = quantity;
        item.itemPrice = itemPrice;
        tickets.push_back(item);

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
    // Only movie purchases get a printed ticket
    bool hasMovie = false;
    for (const Ticket& ticket : tickets) {
        if (ticket.isMovie) {
            hasMovie = true;
        }
    }
    if (!hasMovie) {
        return;
    }

    ofstream ticketFile("ticket.txt"); // Open a text file for writing
    if (!ticketFile.is_open()) {
        cout << "Error creating ticket file. Please check permissions." << endl;
        return;
    }

    // Iterate over tickets and print details for movie tickets
    for (const Ticket& ticket : tickets) {
        if (ticket.isMovie) {

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

    cout << "\nTicket(s) printed successfully. Check 'ticket.txt' for details." << endl;
}

int main() {
    // Seed the random number generator once for the whole program
    srand(static_cast<unsigned>(time(0)));

    //greetings
    cout << "\n\t\tWelcome to CineMagic Theater!\n";
    pauseMs(3000);

    //prompt ticket menu
    tixMenu();

    //prompt concession menu
    concMenu();

    // show user all the things they ordered on the receipt
    receipt();
    printTicket();


    // Pause to allow the user to see the information
    cout << "\nPress Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();

    return 0;
}
