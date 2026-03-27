# Project Pitch
### Project Name: 
Battleship 
### Developer: 
Solo
### Summary
A playable battleship game built in Java. The player places on a 10 x 10 grid and the battle is against an AI opponent. The game will support the saving and loading handle invalid input and use object oriented design throughout.

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
