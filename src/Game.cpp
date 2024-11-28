// #include "Game.hpp"
// #include "Engineer.hpp"
// #include "Laborer.hpp"
// #include "WarehouseWorker.hpp"
// #include "Marketer.hpp"
// #include <iostream>

// Game::Game() : company(10000.0) {}

// void Game::start() {
//     std::cout << "Welcome to the economic game!\n";
//     bool running = true;
//     while (running) {
//         std::cout << "Enter command (le - list employees, \nhe - hire engineer, \nhl - hire laborer, \nwm - hire warehouse worker, \nkm - hire marketer, \nloan - take loan, \net - end turn): ";
//         std::string cmd;
//         std::cin >> cmd;

//         if (cmd == "le") {
//             company.listEmployees();
//         } else if (cmd == "he") {
//             company.hire(std::make_unique<Engineer>("John", "Mechanical"));
//         } else if (cmd == "hl") {
//             company.hire(std::make_unique<Laborer>("Mike", 42.5));
//         } else if (cmd == "wm") {
//             company.hire(std::make_unique<WarehouseWorker>("Jane", true));
//         } else if (cmd == "km") {
//             company.hire(std::make_unique<Marketer>("Sarah", 1500));
//         } else if (cmd == "loan") {
//             double amount;
//             int term;
//             std::cout << "Enter loan amount and term (in months): ";
//             std::cin >> amount >> term;
//             company.takeLoan(amount, term);
//         } else if (cmd == "et") {
//             company.endMonth();
//             if (company.getBalance() < 0) {
//                 std::cout << "Your company has gone bankrupt. Game over.\n";
//                 running = false;
//             }
//         }
//     }
// }
