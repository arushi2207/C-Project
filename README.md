# SNAKE GAME : C Project
# Description :
    
    The Snake Game is the oldest game played on keypad phones. This project aims to create a classic Snake game implemented in the C programming language. This game will provide a simple yet enjoyable gaming experience within a console environment. Players control a snake on a two-dimensional grid, collecting fruit to increase the snake's length while avoiding collision with its own tail. The project's primary focus is to create a fun and educational application for learning and practicing C programming.

# Goals :

    The main objectives of this project are as follows:
    1. Gameplay: Implement the classic Snake game mechanics, including snake movement, food generation, scoring, and collision detection.
    2. User Interface: Create a user-friendly console interface with clear visuals to provide an engaging gaming experience.
    3. Code Quality: Write clean, well-documented, and maintainable C code adhering to best coding practices.

# Specifications :
    
    - A C compiler (e.g., GCC) installed on your system.
    - A terminal or console for running the game.
    - The game interface will be text-based, using characters to represent the game elements.
    - The grid, snake, food, and score will be displayed clearly.
    - The game will respond to player input for controlling the snake.
    - Gameover message and final score will be presented.
    - Player can check the scoreboard after game.

# Desgin :

    Start
    |
    |-- Initialize Game
    |   |
    |   |-- Instructions and loading
    |   |-- Create Grid
    |   |-- Initialize Snake
    |   |-- Place Initial Food
    |   |-- Initialize Score
    |
    |-- Main Game Loop
    |   |
    |   |-- Process User Input
    |   |-- Update Snake Movement
    |   |-- Check Collisions
    |   |-- Check Food Eaten
    |   |-- Update Score
    |   |-- Render Game State
    |   |
    |   |-- If Game Over, Exit Loop
    |
    |-- Display Game Over Message and Final Score
    |-- Display Scoreboard 
    End
