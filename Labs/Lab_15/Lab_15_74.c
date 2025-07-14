#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Song {
    char name[100];
    struct Song* next;
    struct Song* prev;
} Song;

Song* head = NULL;
Song* current = NULL;

// Function to create a new song node
Song* createSong(char name[]) {
    Song* newSong = (Song*)malloc(sizeof(Song));
    strcpy(newSong->name, name);
    newSong->next = NULL;
    newSong->prev = NULL;
    return newSong;
}

// Add song to the end of the playlist
void addSong(char name[]) {
    Song* newSong = createSong(name);
    if (head == NULL) {
        head = newSong;
        current = head;
    } else {
        Song* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newSong;
        newSong->prev = temp;
    }
    printf("✅ '%s' added to playlist.\n", name);
}

// Delete a song by name
void deleteSong(char name[]) {
    Song* temp = head;
    while (temp != NULL && strcmp(temp->name, name) != 0)
        temp = temp->next;
    if (temp == NULL) {
        printf("❌ Song not found.\n");
        return;
    }
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    if (current == temp)
        current = temp->next ? temp->next : temp->prev;
    printf("🗑️  '%s' deleted.\n", temp->name);
    free(temp);
}

// Display the playlist
void displayPlaylist() {
    Song* temp = head;
    if (temp == NULL) {
        printf("🎵 Playlist is empty.\n");
        return;
    }
    printf("🎶 Playlist:\n");
    while (temp != NULL) {
        printf(" - %s\n", temp->name);
        temp = temp->next;
    }
}

// Play current song
void playCurrent() {
    if (current == NULL) {
        printf("🎵 No song is playing.\n");
        return;
    }
    printf("🎧 Now playing: %s\n", current->name);
}

// Play next song
void playNext() {
    if (current && current->next) {
        current = current->next;
        playCurrent();
    } else {
        printf("⏩ No next song.\n");
    }
}

// Play previous song
void playPrevious() {
    if (current && current->prev) {
        current = current->prev;
        playCurrent();
    } else {
        printf("⏪ No previous song.\n");
    }
}

// Search a song
void searchSong(char name[]) {
    Song* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            printf("🔍 '%s' found in playlist.\n", name);
            return;
        }
        temp = temp->next;
    }
    printf("❌ '%s' not found.\n", name);
}

// Free memory
void freePlaylist() {
    Song* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int choice;
    char name[100];

    do {
        printf("\n🎵 Music Player Menu 🎵\n");
        printf("1. Add Song\n");
        printf("2. Delete Song\n");
        printf("3. Display Playlist\n");
        printf("4. Play Current Song\n");
        printf("5. Play Next Song\n");
        printf("6. Play Previous Song\n");
        printf("7. Search Song\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // clear newline

        switch (choice) {
            case 1:
                printf("Enter song name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0;  // remove newline
                addSong(name);
                break;
            case 2:
                printf("Enter song name to delete: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0;
                deleteSong(name);
                break;
            case 3:
                displayPlaylist();
                break;
            case 4:
                playCurrent();
                break;
            case 5:
                playNext();
                break;
            case 6:
                playPrevious();
                break;
            case 7:
                printf("Enter song name to search: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0;
                searchSong(name);
                break;
            case 8:
                printf("👋 Exiting Music Player.\n");
                break;
            default:
                printf("⚠️ Invalid choice.\n");
        }

    } while (choice != 8);

    freePlaylist();
    return 0;
}
