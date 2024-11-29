
# Turn-Based Fighting Game  

## Description  
This project is a simple text-based, turn-based fighting game simulation in C++. Two characters, a Karatist and a Boxer, battle over a series of rounds. Each character can attack or heal themselves using unique abilities. The game ends after 10 rounds or when one character's health reaches zero.  

---

## Features  
- Two unique characters:  
  - **Karatist**: Uses martial arts moves like High Kick and Spinning Leg Kick.  
  - **Boxer**: Employs boxing moves such as Uppercut and Mike Tyson Combo.  
- Gameplay options: Attack or heal during a player's turn.  
- Randomized abilities to ensure varied gameplay.  
- Game mechanics include health tracking and ability-based damage/healing.  

---

## Technologies Used  
- **Programming Language**: C++.  
- **Libraries**:  
  - `<iostream>` for input/output.  
  - `<vector>` for ability management.  
  - `<cstdlib>` and `<ctime>` for random number generation.  

---

## Gameplay  

### Characters and Abilities  
1. **Karatist**  
   - High Kick: Fixed damage of 10.  
   - Spinning Leg Kick: Random damage between 10 and 24.  
   - Meditating: Restores health (randomly between 4 and 8 HP).  

2. **Boxer**  
   - Uppercut: Fixed damage of 10.  
   - Mike Tyson Combo: Random damage between 10 and 24.  
   - Energy Drink: Restores health (randomly between 4 and 8 HP).  

### How to Play  
1. **Setup**:  
   - Enter the health values for both the Karatist and the Boxer.  

2. **Turn Structure**:  
   - Each character takes turns choosing an action:  
     - **Attack**: Deal damage to the opponent.  
     - **Heal**: Restore health using a healing ability.  
   - Invalid inputs skip the turn.  

3. **Winning**:  
   - A player wins if their opponent's health reaches zero.  
   - The game ends in a tie if both players are alive after 10 rounds.  

---

## Installation  
1. Copy the code into a `.cpp` file (e.g., `fighting_game.cpp`).  
2. Compile the file using a C++ compiler like `g++`:  
   ```bash
   g++ -o fighting_game fighting_game.cpp
   ```  
3. Run the compiled program:  
   ```bash
   ./fighting_game
   ```  

---

## Example Gameplay  
**Input**:  
```
Enter health for Karatist: 100  
Enter health for Boxer: 100  
```

**Output**:  
```
Round 1  
Karatist's turn:  
1. Attack  
2. Heal  
Enter your choice (1 or 2): 1  
Karatist performs High Kick and attacks Boxer for 10 damage!  

Boxer's turn:  
1. Attack  
2. Heal  
Enter your choice (1 or 2): 2  
Boxer uses Energy Drink and heals themselves for 6 HP!  

...  
The game ended in a tie after 10 rounds!  
```  

---

## Notes  
- Ensure randomness by seeding the random number generator with `srand(time(0))`.  
- Modify the number of rounds or health values to customize gameplay.  
"# OOP-Project" 
"# OOP-Project" 
