# Project 2: Simon Says – Arduino Memory Game

## Overview

Build a simple electronic Simon Says game using an Arduino Uno. The game will display a sequence of lights, and the player must remember and repeat the sequence using buttons.

You will use two LEDs, two buttons, and a Piezo speaker to build an interactive memory game.

**Groups:** Each group should ideally have 3 students.

## Game Description

- The game uses two LEDs (Left and Right) and two buttons (Left and Right).
- At the beginning of the game, the Piezo speaker plays a short introductory tune.
- The game displays a random sequence of lights, starting with a sequence of length 1.
- Each light in the sequence stays on for a quarter of a second (250 milliseconds).
- After the sequence is displayed, the player must repeat it by pressing the corresponding buttons in the correct order.
- If the player repeats the sequence correctly, the speaker plays a success sound, and the game moves to the next round. The next sequence will be one element longer.
- If the player presses the wrong button, the speaker plays an error sound, and the game ends.
- The player must respond to each light within 3 seconds. If no button is pressed within this time, the game ends.
- The game continues until the player makes a mistake or fails to respond within the time limit. When the game ends, the speaker plays a different tune to indicate the end of the game.

**Example:** If the displayed sequence is `LLRLR`, the player must press the Left, Left, Right, Left, and Right buttons in exactly that order.


### Programming and Design Requirements

This project is based on Lab 9, but is more complex. You are expected to apply proper software engineering practices:

- **Minimize the use of global variables:** Prefer local variables and pass data between functions through parameters and return values. Use static local variables when a function needs to retain its state between calls.
- **Functions:** Decompose your program into multiple functions, with each function performing a single, well-defined task.
- **Arrays:** Use an array to store the sequence of lights.
- **Constants:** Use constants instead of hard-coded values where appropriate.
- **Naming and Readability**: Use meaningful and descriptive names for variables and functions to make your code easy to read and understand.


## Sample Run

Your program's Serial Monitor output should behave similarly to, but does not have to exactly match, the following example:

```text
Game starting...

Level 1:
LED sequence: L
You pressed: L
Correct! Move to Level 2!

Level 2:
LED sequence: LR
You pressed: LR
Correct! Move to Level 3!

Level 3:
LED sequence: LRL
You pressed: LRL
Correct! Move to Level 4!

Level 4:
LED sequence: LRLR
You pressed: LRLL
Wrong! Game Over!
```

*Note: The sample run illustrates the expected game flow. Your actual game must communicate with the player using the LEDs, buttons, and Piezo speaker. Serial Monitor output is intended for debugging and providing additional feedback, not as a replacement for the physical game interface.*

## Submission

1. Like your project 1, create another repository (repo) named comp120_project2 with README.md.
2. Upload your Arduino source code (`.ino` file) to your GitHub repo.
3. Write a good `README.md` file describing your project. Include:
   - Project overview and game instructions.
   - (Bonus 5 marks) A picture of a Tinkercad simulation with a complete circuit diagram
   - A picture of hardware circuit.
   - How to run and play the game.
   - First names of all group members.
4. Copy your GitHub repository link and submit it on e-learn.

**Demonstration:** Each group must demonstrate its working game during the last class.

## Grading Guide

| Category | Marks | Expectations |
|---|---:|---|
| Execution | 30 | The Arduino circuit is correctly wired, easy to play, and the game works according to the specifications. |
| Design | 30 | The program is well structured, uses appropriate functions and arrays, minimizes the use of global variables, and uses constants and `static` variables appropriately. |
| Documentation | 15 | A clear, well-organized, and informative README.md file in your GitHub repo, describing the project, hardware circuit and how to play the game. |
| Bonus | 5 | 5 marks for including a Tinkercad simulation with a complete circuit diagram in your README.md file. For example, a project that earns 95 marks without the simulation can earn 100 marks with it. |
| 3-min Presentation | 20 | 
| **Total** | **100** | |
