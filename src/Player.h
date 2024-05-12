
typedef struct Player {
    char name[100];
    int health;
} Player;

Player NewPlayer(const char *name, int hp);
