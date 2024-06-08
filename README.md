
# Merkelx

Merkelx is a C++ application that simulates a basic cryptocurrency trading platform. It includes classes and methods for handling order books, user inputs, and wallet management.

## Table of Contents
- [Merkelx](#merkelx)
  - [Table of Contents](#table-of-contents)
  - [Features](#features)
  - [Installation](#installation)
  - [Usage](#usage)
  - [Contributing](#contributing)

## Features

- **Order Book Management**: Handles bid and ask orders, providing functionalities to add, remove, and process orders.
- **CSV Reading**: Reads order data from CSV files, facilitating the import of large datasets for trading simulation.
- **User Interface**: A console-based interface that allows users to interact with the application, place orders, and view market data.
- **Wallet Management**: Simulates a user's wallet for trading purposes, including functionalities to manage balances and transactions.

## Installation

1. Clone the repository:
    ```sh
    git clone https://github.com/Pavelosky/Merkelx.git
    ```
2. Navigate to the project directory:
    ```sh
    cd Merkelx
    ```
3. Compile the project:
    ```sh
    g++ -o MerkelxMain main.cpp CSVReader.cpp OrderBook.cpp OrderBookEntry.cpp Wallet.cpp
    ```

## Usage

Run the compiled executable:
```sh
./MerkelxMain
```

Follow the on-screen prompts to interact with the application. Users can:
- Load market data from a CSV file.
- Place buy and sell orders.
- View the current state of the order book.
- Check their wallet balance and transaction history.

## Contributing

Contributions are welcome! Please follow these steps:

1. Fork the repository.
2. Create a new branch (`git checkout -b feature-branch`).
3. Commit your changes (`git commit -m 'Add some feature'`).
4. Push to the branch (`git push origin feature-branch`).
5. Open a Pull Request.

