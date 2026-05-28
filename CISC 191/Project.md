# Project Pitch
### Project Name: 
Battleship 
### Developer: 
Solo
### Summary
A playable battleship game built in Java. The player places on a 10 x 10 grid and the battle is against an AI opponent. The game will support the saving and loading handle invalid input and use object oriented design throughout.

# Week 1

## GUI Mock-Up
- Two 10x10 grids -- User and Enemy (AI) grid
- Status Bar -- displays game messages
- Buttons -- Place Ship, Save/Load Game, New Game
- User Grid -- show your ship placement, where missed, where hit
- Enemy Grid -- hits and missed
- Ship List -- ships that are yet to be used

```
-------------------------------------------------
|                   BATTLESHIP                  |
-----------------------+-------------------------
|   USER GRID          |   ENEMY GRID           |
|  (shows your ships   |  (click to fire;       |
|   and hits/misses)   |   shows hits/misses)   |
-----------------------+-------------------------
|  [ Place Ships ]  [ Save Game ]  [ Load Game ]|
|  Status: "Your turn — select a target..."     |
|  Ships remaining: Carrier(5) Destroyer(2)...  |
-------------------------------------------------
```

## Class-Responsibility-Collaboration (CRC) cards
### Card 1: `Ship`
| **Ship** | |
|---|---|
| **Responsibilities** | Know its name, length, hit count; know if it's sunk |
| **Collaborators** | `Board`, `Cell` |

---

### Card 2: `Carrier extends Ship`
| **Carrier** | |
|---|---|
| **Responsibilities** | Represent a 5-cell ship; provide its specific name/length |
| **Collaborators** | `Ship` (parent) |

---

### Card 3: `Cell`
| **Cell** | |
|---|---|
| **Responsibilities** | Track one grid square's state (empty, ship, hit, miss) |
| **Collaborators** | `Board`, `Ship` |

---

### Card 4: `Board`
| **Board** | |
|---|---|
| **Responsibilities** | Hold 10×10 grid of Cells; place ships; receive shots; check win condition |
| **Collaborators** | `Cell`, `Ship`, `Player` |

---

### Card 5: `Player` (Abstract Class)
| **Player** | |
|---|---|
| **Responsibilities** | Own a Board; hold a fleet of Ships; take a turn |
| **Collaborators** | `Board`, `Ship`, `HumanPlayer`, `AIPlayer` |

---

### Card 6: `HumanPlayer extends Player`
| **HumanPlayer** | |
|---|---|
| **Responsibilities** | Accept GUI input for shots and ship placement |
| **Collaborators** | `Player` (parent), `BattleshipGUI` |

---

### Card 7: `AIPlayer extends Player`
| **AIPlayer** | |
|---|---|
| **Responsibilities** | Fire shots automatically (random or hunt/target mode) |
| **Collaborators** | `Player` (parent), `Board` |

---

### Card 8: `Game`
| **Game** | |
|---|---|
| **Responsibilities** | Manage overall game state and turn loop; coordinate players |
| **Collaborators** | `HumanPlayer`, `AIPlayer`, `BattleshipGUI`, `GameFileManager` |

---

### Card 9: `GameFileManager`
| **GameFileManager** | |
|---|---|
| **Responsibilities** | Save and load game state to/from a text file |
| **Collaborators** | `Game`, `Board`, `Ship` |

---

### Card 10: `BattleshipGUI`
| **BattleshipGUI** | |
|---|---|
| **Responsibilities** | Build and display the Swing GUI; handle user events; update display |
| **Collaborators** | `Game`, `HumanPlayer`, `Board`, `Cell` |

---

## Unified Modeling Language (UML) Diagram
```    
        <<abstract>>              <<abstract>>
           Player                    Ship
          /      \                /  |  |  \  \
  HumanPlayer  AIPlayer    Carrier Battleship Destroyer Submarine PatrolBoat

  Player ──has──▶ Board ──has──▶ Cell
  Player ──has──▶ List<Ship>
  Game ──has──▶ HumanPlayer, AIPlayer
  Game ──uses──▶ BattleshipGUI
  Game ──uses──▶ GameFileManager
```

## Demonstratation of LOs
| LO | How It's Used in Battleship |
|----|----------------------------|
| LO1 | Each class has one job |
| LO2 | `Cell[][]` in `Board` is a 2D array -- 10×10 game board |
| LO3 | `Board` holds `Cell` objects; `Player` holds `Board` and `Ship` objects; `Game` holds both players |
| LO4 | `Ship` is abstract; `Carrier`, `Battleship`, etc. extend it. `Player` is abstract |
| LO5 | `List<Ship>` (ArrayList) stores each player's fleet |
| LO6 | Two 10×10 `JButton grid`s in a `JFrame` |
| LO7 | Catch of bad ship placement or any errors |
| LO8 | `GameFileManager` saves and loads game into `.txt` |

## Video
[https://sdccd.us-west-2.instructuremedia.com/embed/42ef8761-1f40-4a7d-9c15-8b361ef81b9f]

## Planned Work Schedule
Work per week --> 1 hour/day * 7 = 7 hours/week

| Week | To-Do |
|------|-------------------|
| 1 | Submit proposal; design CRC cards and UML; sketch GUI mockup |
| 2 | Implement `Cell`, `Ship` (abstract), and all 5 ship subclasses; unit test |
| 3 | Implement `Board` (2D array, placeShip, receiveShot, allShipsSunk) |
| 4 | Implement `Player` (abstract), `HumanPlayer`, `AIPlayer` (random mode) |
| 5 | Build `BattleshipGUI` — two grids, status bar |
| 6 | Implement `Game` controller; full playthrough |
| 7 | Add `GameFileManager` (save/load); add exception handling |
| 8 | Polish UI, Javadoc all classes, fix bugs, record demo video |

# Week 2
## Journal Entry
This week focused on the model layer: Cell, the abstract Ship class, and all five ship subclasses. Getting the abstract class right took more thought than expected — I had to decide which behaviour truly belongs in Ship versus in the subclasses. I settled on keeping getName() and getLength() abstract so each subclass supplies its own identity, while hit(), isSunk(), and getHitCount() are fully implemented in the parent.
## Challenges:
1. Deciding whether Ship should store a reference to its cells on the board or just track a hit counter. Chose the hit counter approach for simplicity; the Board handles coordinate tracking.
2. Making sure isSunk() compares hit count to length correctly.

## Design changes from Week 1:
1. Added a getSymbol() method to Ship for GUI rendering (each ship type gets a single-character label).
2. Cell now stores an orientation field (HORIZONTAL/VERTICAL) that will be used during ship placement rendering.

## Work remaining: 
Board class, Player hierarchy, GUI, Game controller, file I/O.

## Screenshots:

# Week 3
## Journal Entry
This week I built the Board class — the core data structure of the game. The 10×10 Cell[][] array is working, ship placement validates bounds and overlaps, and receiveShot() updates cell state correctly.
## Challenges:
1. Boundary checking for ship placement across both orientations (horizontal vs vertical) required careful index math. Off-by-one errors appeared twice during testing.
2. Decided to throw a custom InvalidPlacementException (extends Exception) when a ship cannot be placed, rather than returning a boolean. This satisfies LO7 and makes the calling code cleaner.
3. allShipsSunk() iterates over the ship list rather than scanning the grid — faster and simpler.

## Design changes:
1. Added getCell(int row, int col) to Board so the GUI can query individual cell states without exposing the array directly.
2. Added resetBoard() to support the New Game button.

## Work remaining: 
Player hierarchy, GUI, Game controller, file I/O.

## Screenshots:

# Week 4
## Journal Entry
This week I implemented the Player abstract class and both concrete subclasses: HumanPlayer and AIPlayer. The AI uses a two-phase strategy — random firing until a hit, then a hunt mode that targets adjacent cells.
## Challenges:
1. Designing the abstract takeTurn() method was tricky because HumanPlayer's turn is event-driven (it waits for a GUI click) while AIPlayer's turn runs immediately. I resolved this by having HumanPlayer.takeTurn() do nothing on its own — the BattleshipGUI will call fireAt() directly when the player clicks the enemy grid.
2. The AI hunt/target logic needed a queue of candidate cells. Used an ArrayDeque<int[]> to store adjacent cells after a hit.
3. Had to ensure the AI never fires at the same cell twice — added a shotsFired boolean grid.

## Design changes:
1. Player now holds List<Ship> fleet (an ArrayList<Ship>) populated by a buildFleet() method — satisfies LO5.
2. Added getBoard() accessor to Player so Game can pass the opponent's board for hit detection.

## Work remaining: 
GUI, Game controller, file I/O.

## Screenshots:

# Week 5
## Journal Entry
This week I built the BattleshipGUI class using Java Swing. The two 10×10 JButton grids are rendering correctly, the status bar updates on each action, and ship placement mode is working end-to-end.
## Challenges:
1. Laying out two grids side by side with labels required nested JPanels and GridLayout. Getting the sizing consistent across platforms took several iterations.
2. Ship placement required a two-click workflow: click the desired starting cell, then choose orientation via a dialog. I used JOptionPane for the orientation prompt.
3. Color coding the buttons (blue for water, red for hits, white for misses, gray for ships) required calling setBackground() and disabling the button's content area fill.

## Design changes:
1. BattleshipGUI now holds a reference to Game (not just to HumanPlayer and Board) so the controller can be the single source of truth for state transitions.
2. Added a refreshGrids() method that repaints both boards from current Cell state — called after every shot and after loading a saved game.

## Work remaining: 
Game controller (wiring GUI ↔ logic), file I/O.

## Screenshots:

# Week 6
## Journal Entry
This week I wrote the Game class, which wires everything together. A full game can now be played from ship placement through to a win/lose screen. The turn loop works correctly: human fires, AI responds, game checks for a winner, GUI updates.
## Challenges:
1. The "game over" state needed to block further input on the enemy grid without crashing any pending listeners. BattleshipGUI.enableEnemyGrid(false) plus a gameOver flag in Game solved this.
2. New Game required resetting both boards, rebuilding both fleets, and refreshing the GUI — coordinating all three objects took careful ordering.

## Design changes:
1. placeAllShipsRandomly(Player) helper method added so New Game can auto-place ships for the AI instantly.

## Work remaining: 
File I/O, exception handling, polish, Javadoc.

## Screenshots:

# Week 7
## Journal Entry
This week I implemented GameFileManager for save/load and added comprehensive exception handling throughout the project.
The save file is a plain .txt file. The format serializes: game state, both boards cell by cell, ship placement coordinates, hit counts, and whose turn it is. BufferedWriter and BufferedReader handle the I/O. The file is human-readable, which made debugging easy.
## Challenges:
1. Loading a partially-sunk ship required restoring the hit count without calling hit() the wrong number of times — added a setHitCount(int) package-private method to Ship.
2. Tested save/load by saving mid-game, restarting the application, and loading — game resumed correctly.

## Work remaining: 
Polish, full Javadoc, demo video.

## Screenshots:

# Week 8
## Journal Entry
The Battleship project is complete. Over eight weeks I went from a sketch on paper to a fully playable Java game with a Swing GUI, AI opponent, save/load functionality, and comprehensive exception handling.
- What went well:
The OOP design held up throughout. When I needed to add the AI hunt/target logic in Week 4, I only had to touch AIPlayer — nothing else changed.
Separating Game (logic controller) from BattleshipGUI (display) made debugging much easier. I could test Game logic in isolation before connecting the GUI.
The InvalidPlacementException pattern from Week 3 paid off in Week 6 — Game.placeHumanShip() cleanly catches bad placements and shows a user-friendly error.
- What I'd do differently:
I'd implement the Model-View-Controller pattern more formally from the start. The boundary between Game and BattleshipGUI blurred slightly when I added save/load.
I'd write more unit tests earlier. Manual console testing was fine for the model layer, but I caught a few GUI bugs late that earlier automated tests might have found.

## Screenshots:

## Demo Video: 
