![beachBrawlLogo](https://user-images.githubusercontent.com/56164075/115942623-22fdf980-a479-11eb-8b8b-97b2b09770df.png)
<br />
<p align="center">
  <p align="center">
    Ken Krebs and Wiley Hunt
    <br />
    <a href="https://github.com/github_username/repo_name">View Demo</a>
  </p>
</p>


<!-- TABLE OF CONTENTS -->
<details open="open">
  <summary><h2 style="display: inline-block">Table of Contents</h2></summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#built-with">Built With</a></li>
      </ul>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#usage">Usage</a></li>
  </ol>
</details>


<!-- ABOUT THE PROJECT -->
## About The Project


This project provides an action-packed, 2-player fighting game compatibleto run on the BeagleBone Black developed using Qt, and C++. At game start, players can navigate through the game menu, choose their players, and start a new match. Once the battle begins, players
will be able to make their fighter move, punch, kick, block, and jump. After 90 seconds, or once a player's health reaches zero, the game ends and a winner is declared!

### Built With

* [Qt Framework](https://www.qt.io/download)
* [C++](https://www.cplusplus.com/)


<!-- GETTING STARTED -->
## Getting Started

To get a local copy up and running follow these simple steps.

### Prerequisites
To run on a local machine:
* Qt Widget Toolkit

To deploy on a BeagleBone Black:
* BeagleBone Black
* BeagleBone Black compatible LCD touchscreen 
* USB Keyboard

  
### Installation
[download QtCreator](https://www.qt.io/download)

<!-- USAGE EXAMPLES -->
## Usage

### Opening and Compiling
To run locally, clone this repo and open the project using QtCreator, choose 'Open' and select the fighterguy folder from the cloned repository. To run, click the "Build" and then "Run" buttons.

To run the BeagleBone Black, you must use Qmake and cross compile the program with the appropriate tool chain. After transferring the executable to the BeagleBone, simply run with "./fighterguy". 

### Game Overview
To begin, run the application, select "New Game", and then choose your characters.

Each Player begins with 20 health points and the game timer is set to 90 seconds.

Within the game, a player can punch another opponent by moving directly adjacent to the opponent and pressing the punch key. If the other player is not blocking, their health will be decremented by 1 health point. If they are blocking (or have jumped), no health points are deducted. 

A player can kick another opponent by moving within 1 step of the their opponent (ie, one more step and they would be directly adjacent) and pressing the kick key. If the other player is not blocking, their health will be decremented by 2 health points. If they are blockin 1 health point are deducted.If the other player is jumping, no health points are deducted.

The game ends when either one player is out of health points or the game timer is up!

### Controls
Each player can move left or right, jump, block, kick and punch. 


|Move        |Player 1    | Player 2   |
| ---------- |:----------:|:----------:|
|Move Left   |A           |J           |
|Move Right  |D           |L           |
|Jump        |W           |I           |
|Block       |S           |K           |
|Kick        |C           |N           |
|Punch       |X           |M           |
|Pause       |Spacebar    |Spacebar    |




