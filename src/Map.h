
typedef struct Room {
    char* description;
    struct Room* door;
} Room;

Room* NewRoom();
Room* NewMap(int size);
