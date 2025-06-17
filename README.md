# Pacman Game

Pacman in C with Raylib: A fun, retro maze game where you guide Pac-Man with arrow keys to eat pellets and dodge ghosts. Built in C, it highlights game logic, graphics, and input handling in a compact, nostalgic package.

## Features

**Gameplay Mechanics**

- **Maze Navigation**: Players control Pacman to move through a maze filled with pellets.
- **Pellets and Super Pellets**: Consuming pellets increases the score, while Super pellets allow Pacman to eat ghosts for a limited time.
- **Ghosts**: Implemented three ghosts with unique behaviors — Red uses BFS to chase Pac-Man, Green moves randomly but chases when Pac-Man enters its zone, and Pink follows a fully random path.
- **Lives**: The game begins with a three number of lives, with one life lost each time a ghost catches Pacman.When the score reaches 5000,an extra life is given.
- **Scoring**: Points are earned by eating pellets,super pellets, and capturing ghosts.



**Graphical User Interface**
- **Rendering**: Utilizes the raylib library to draw the maze, Pacman, ghosts, and other visual elements.
- **Animations**: Features smooth animations for the movements and interactions of characters.
- **Game Interface**: Displays essential game information such as score and remaining lives.
- **Background Music**: Added background music to enhance immersion and signal gameplay states in Pac-Man.



**User Input Handling**

- **Keyboard Controls**: Use arrow keys to navigate Pacman through the maze.
- **Responsive Controls**: Ensures immediate reaction to player inputs for seamless gameplay.


**Ghost**

- **Chase Mode**: Ghosts chases Pacman using different algorithms.
- **Frightened Mode**: Ghosts become vulnerable after Pacman consumes a super pellet as pacman can consume ghost for a specific time.


## Tech Stack

- **Programming language:** C

- **Libraries:** Make use of the Raylib graphics library for rendering and input manipulation.

- **IDE**: A standard C IDE with GCC for compilation, is being utilized.


## Game Structure

- **Main loop**: Runs continuously to update game state and render frames, ensuring smooth and engaging gameplay.

- **Game States:** States implemented include Start mode, Pause mode, Restart mode, etc. 

- **Entities:** Distinct entities include Pac-Man, ghosts, pellets, and maze data, each managed within its own encapsulated global variables.

- **Collision Detection:** Different algorithms are implemented for each ghost to prevent dynamic running and to handle collisions between Pac-Man, ghosts, and walls.

- **Ghost Logic:** Implements sophisticated behavioral patterns for ghosts through advanced algorithms, enhancing their movement and decision-making capabilities based on game conditions and player actions.


## Code Operation

- **globals.h**: Defines the variables and data types.

- **globals.c**: Contains the declarations of the global variables.

- **main.c**: Handles the game state updates, rendering, and audio playback within the main loop, including functionalities for pause, game over, and score tracking.

- **instructions.c**: Displays the game instructions and a "START" button, transitioning to the main game screen when clicked.

- **maze_pellet_initialization.c**: Draws the maze and lives, and updates the visibility of the super pellet in the game.

- **pacman_creation_movement.c**: Draws Pac-Man with an animated mouth and updates Pac-Man's position, score, and interactions with pellets and super pellets in the game.

- **ghost_creation_movement.c**: Draws ghosts, updates ghost positions and behavior, has ghosts chase Pac-Man, and handles collisions between Pac-Man and ghosts with corresponding sound effects.

- **path_finding.c**: Implements BFS pathfinding to chase Pac-Man, with alternate behavior when ghosts can be consumed, updating their positions accordingly.

- **pausegame.c**: Draws a button and toggles the game's pause state when the button is clicked, updating the button text accordingly.

## Installation and Requirements

**Prerequisites**

* C Compiler:  Ensure you have a C compiler installed, such as GCC.
* raylib Library: Install the raylib library, which is used for rendering graphics.

**Step-by-Step Guide**

1. Navigate to the Project Directory:
         cd pacman-game

2. Install raylib:

       On Linux:
                sudo apt-get install libraylib-dev
        On macOS:
                 brew install raylib
         On Windows:
                  Download the raylib installer from the official website and follow the installation instructions.

3. Build the Project:

         gcc -o pacman main.c -lraylib

4. Run the Game:

          ./pacman
          On Windows:
                     pacman.exe

## Controls

        * Press Start button to start the game 
        * Use the arrow keys in the keyboard to control the movement of the Pacman
        * Press Pause button to pause the game
        * Press Resume button to continue the game
        * Press Restart button to start the game from the beginning

## Authors
K Anishka , *SSN College of Engineering , Tamil nadu , India*

Anne Jacika J , *SSN College of Engineering , Tamil nadu , India*
