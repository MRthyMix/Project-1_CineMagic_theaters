# Final Project AI IMAX CineMagic Theater at GTCC

**▶ [Try it in your browser](https://mrthymix.github.io/Project-1_CineMagic_theaters/)**

The CineMagic Theater project is a command-line C++ application designed to simulate the experience of visiting a movie theater. Users can purchase tickets, select from a variety of snacks and beverages, and even choose their desired seats. The program utilizes data structures, arrays, and switch statements to ensure effective organization and management of user interactions. It operates entirely within the command prompt or a similar environment, offering a user-friendly and practical way to simulate a trip to the movies.

I wrote it as my final project when I was first learning to code at Guilford Technical Community College (GTCC).

## What you can do

- **Buy movie tickets** for one of five movies at Adult ($15), Child ($10) or Senior ($7) prices.
- **Pick your seats** from a 5 × 6 seating chart. Each movie's open seats are randomized every time the program starts.
- **Order concessions**: snacks, food and drinks, with sub-menus for candy, popcorn, hamburgers, fountain drinks and Icees.
- **Get a receipt** with a running total and 7% sales tax.
- **Print your tickets** to `ticket.txt`, with the movie and your seats.

## What's inside the code

| Concept | Where it's used |
| --- | --- |
| `struct` | `Ticket` holds each line of the order: name, quantity, price, seats |
| `vector` | `vector<Ticket>` stores the whole order for the receipt |
| Multi-dimensional arrays | `seats[5][5][6]` tracks open and taken seats for each movie |
| `switch` statements | Map menu numbers to items and prices |
| Input validation | `readInt()` asks again when someone types letters instead of a number |
| File output | `ofstream` writes the tickets to `ticket.txt` |

## Run it

**In the browser:** the [live demo](https://mrthymix.github.io/Project-1_CineMagic_theaters/) is a JavaScript port of the same menus, prices and rules, so you can try it without installing anything. Its source is [`docs/index.html`](docs/index.html).

**On Windows:** download [`CineMagic.exe`](Project%201_CineMagic_theaters/CineMagic.exe) and double-click it. Windows may warn you because the program isn't signed.

**Build from source** with g++ (for example [MinGW-w64](https://winlibs.com/)):

```bash
g++ -std=c++17 -O2 -static -o CineMagic.exe "Project 1_CineMagic_theaters/Project 1_CineMagic_theaters.cpp"
./CineMagic.exe
```

## Project layout

```
Project 1_CineMagic_theaters/
  Project 1_CineMagic_theaters.cpp   the C++ program
  CineMagic.exe                      prebuilt Windows executable
docs/
  index.html                         browser version (served by GitHub Pages)
```
