#pragma once

typedef struct Room {
    char* description;
    struct Room* door;
} Room;

Room* NewRoom(void);
Room* NewMap(int size);
