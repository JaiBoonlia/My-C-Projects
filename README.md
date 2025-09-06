# Bollywood Movie Randomizer
# Overview
The Bollywood Movie Randomizer is a C-based program that helps users discover random Bollywood movies based on their preferred genre. By selecting a genre, the program fetches movie names from text files and provides a random recommendation. This project highlights file handling, arrays, randomization, and modular programming in C.

# Features
The project is designed to provide the following functionalities:<br>
Select from multiple Bollywood genres.<br>
Load movie names dynamically from external text files.<br>
Recommend a random movie within the chosen genre.<br>
Allow multiple recommendations until the user stops.<br>
Handle invalid inputs gracefully.<br>
Exit the program safely upon request.<br>

# Supported Genres
The following genres are currently supported:<br>
Action<br>
Comedy<br>
Drama<br>
Romance<br>
Horror<br>
Thriller<br>

Each genre corresponds to a text file (e.g., action.txt, comedy.txt). Each file contains a list of movies written line by line.

# Dataset / Input Files
Each genre has a simple text file storing its movie list.<br>
Example (action.txt):<br>
Sholay<br>
War<br>
Krrish<br>
Dhoom<br>
Ghajini<br>

- Each movie should be on a new line.<br>
- You can add more movies by updating the respective text file.<br>

# Core Techniques
The project uses the following programming concepts:<br>
Arrays to store movie names.<br>
File Handling to read genre-specific files.<br>
Randomization (rand()) to select random movies.<br>
Functions for modular design (load_movies, recommend_movie, show_genres).<br>
Loops and conditionals for menu navigation and repeated recommendations.<br>

# How to Run
Clone or download the repository.<br>
Ensure all movie list files (action.txt, comedy.txt, etc.) are in the same directory as the program.<br>
Compile the program using:<br>
gcc movie_randomizer.c -o movie_randomizer<br>
Run the program using:<br>
./movie_randomizer<br>
Follow the prompts to select a genre and get recommendations.<br>

# Example Run
=== Bollywood Movie Randomizer ===<br>
Select a genre to get a movie recommendation:<br>
1. Action<br>
2. Comedy<br>
3. Drama<br>
4. Romance<br>
5. Horror<br>
6. Thriller<br>
0. Quit<br>
Enter your choice: 1<br>
Your recommended movie is: Sholay<br>
Would you like another recommendation from this genre? (y/n): y<br>
Try this one: Dhoom<br>
Another one? (y/n): n<br>

# Limitations
Each text file can store up to 100 movies (MAX_MOVIES).<br>
Movie names must not exceed 100 characters (MAX_NAME_LENGTH).<br>
The program only works if the corresponding text files exist in the same directory.<br>
No duplicate prevention – the same movie may be recommended again.<br>

# Future Enhancements
Add support for multiple languages.<br>
Include Hollywood or regional cinema genres.<br>
Track user preferences for personalized recommendations.<br>
Develop a GUI or web-based version for improved interactivity.<br>
