# Robot Delivery Simulation

**Author:** Abdelrhman Hamdy (#Abdo736a)

## Description
A C++ simulation of a robot delivering packages on a grid.  
The program uses Object-Oriented Programming concepts and logs all robot movements and deliveries to a timestamped text file.

## Features
- Robot moves in a 10x10 grid.
- Delivery points are represented in the grid (`D` = not delivered, `X` = delivered).
- Robot location is marked as `R`.
- All robot moves and deliveries are logged in a file named `robot_log_<timestamp>.txt`.
- Logs include timestamp for each move and delivery.

## How to Run
1. Compile the program using a C++ compiler: `g++ main.cpp -o RobotDelivery`
2. Run the executable: `./RobotDelivery`

## Example Output
Log file for new proccess for date : 2026-01-02 07:46:00 

enter move (U/D/L/R) or Q to quit: Robot direction X = (0)  Y = (1) moves : (1) 
. . . . . . . . . . 
R . . . . . . . . . 
. D . . . . . . . . 
. . . . . . . . . . 
. . . D . . . . . . 
. . . . . . . . D . 
. . . . . . . . . . 
. . . . . . . . . . 
. . . . . . . . . . 
. . . . . . . . . . 

enter move (U/D/L/R) or Q to quit: Robot direction X = (0)  Y = (2) moves : (2) 
. . . . . . . . . . 
. . . . . . . . . . 
R D . . . . . . . . 
. . . . . . . . . . 
. . . D . . . . . . 
. . . . . . . . D . 
. . . . . . . . . . 
. . . . . . . . . . 
. . . . . . . . . . 
. . . . . . . . . . 

enter move (U/D/L/R) or Q to quit: Robot direction X = (1)  Y = (2) moves : (3) 
The robot deliverd (pack. 2) successfully! with count moves : (3) 
. . . . . . . . . . 
. . . . . . . . . . 
. R . . . . . . . . 
. R . . . . . . . . 
. . . D . . . . . . 
. . . . . . . . D . 
. . . . . . . . . . 
. . . . . . . . . . 
. . . . . . . . . . 
. . . . . . . . . . 

enter move (U/D/L/R) or Q to quit: Robot direction X = (1)  Y = (3) moves : (4) 
. . . . . . . . . . 
. . . . . . . . . . 
. X . . . . . . . . 
. R . . . . . . . . 
. . . D . . . . . . 
. . . . . . . . D . 
. . . . . . . . . . 
. . . . . . . . . . 
. . . . . . . . . . 
. . . . . . . . . . 

