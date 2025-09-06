#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_MOVIES 100
#define MAX_NAME_LENGTH 100
#define MAX_USER_MOVIES 4

int load_movies(const char *filename, char movies[][MAX_NAME_LENGTH]);
void recommend_movie(const char *filename);
void show_genres();
int get_user_choice();

const char *genres[] = {"Action", "Comedy", "Drama", "Romance", "Horror", "Thriller"};
const char *files[] = {"action.txt", "comedy.txt", "drama.txt", "romance.txt", "horror.txt", "thriller.txt"};
const int genre_count = sizeof(genres) / sizeof(genres[0]);

int main()
{
    srand(time(NULL));
    int choice;

    printf("=== Bollywood Movie Randomizer ===\n");

    do
    {
        show_genres();             
        choice = get_user_choice();

        if (choice >= 1 && choice <= genre_count)
        {
            recommend_movie(files[choice - 1]);
        }
        else if (choice != 0)
        {
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    printf("Thank you for using the Movie Randomizer. Goodbye!\n");
    return 0;
}

void show_genres()
{
    printf("\nSelect a genre to get a movie recommendation:\n");
    for (int i = 0; i < genre_count; i++)
    {
        printf("%d. %s\n", i + 1, genres[i]);
    }
    printf("0. Quit\n");
    printf("Enter your choice: ");
}

int get_user_choice()
{
    int choice;
    if (scanf("%d", &choice) != 1)
    {
        while (getchar() != '\n')
            ;
        return -1;
    }
    return choice;
}

int load_movies(const char *filename, char movies[][MAX_NAME_LENGTH])
{
    FILE *file = fopen(filename, "r");
    if (!file)
    {
        printf("Error: Could not open file %s\n", filename);
        return 0;
    }

    int count = 0;
    while (fgets(movies[count], MAX_NAME_LENGTH, file))
    {
        
        char *newline = strchr(movies[count], '\n');
        if (newline)
            *newline = '\0';

        count++;
        if (count >= MAX_MOVIES)
            break;
    }

    fclose(file);
    return count;
}

void recommend_movie(const char *filename)
{
    char movies[MAX_MOVIES][MAX_NAME_LENGTH];
    int count = load_movies(filename, movies);

    if (count == 0)
    {
        printf("No movies found in this genre.\n");
        return;
    }

    int index = rand() % count;
    printf("\nYour recommended movie is: %s\n", movies[index]);

    char answer;
    printf("Would you like another recommendation from this genre? (y/n): ");
    scanf(" %c", &answer);

    while (answer == 'y' || answer == 'Y')
    {
        index = rand() % count;
        printf("Try this one: %s\n", movies[index]);
        printf("Another one? (y/n): ");
        scanf(" %c", &answer);
    }
}
