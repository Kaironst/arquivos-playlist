#include <stdio.h>
#include <stdlib.h>
#include "playlist.h"
#include "playlist.c"
int main() {
    Playlist *playlist;

    playlist = criar_playlist();
    adicionar_musica(playlist,"musica1","eu",300);
    adicionar_musica(playlist,"musica2","eu",300);
    adicionar_musica(playlist,"musica3","eu",300);
    adicionar_musica(playlist,"musica4","eu",300);
    adicionar_musica(playlist,"musica5","eu",300);
    adicionar_musica(playlist,"musica6","eu",300);
    adicionar_musica(playlist,"musica7","eu",300);
    listar_musicas(playlist); printf("\n\n");
    remover_musica(playlist,"musica4");
    remover_musica(playlist,"musica1");
    remover_musica(playlist,"musica7");
    listar_musicas(playlist); printf("\n\n");
    proxima_musica(playlist);
    listar_musicas(playlist); printf("\n\n");
    proxima_musica(playlist);
    musica_anterior(playlist);
    listar_musicas(playlist); printf("\n\n");
    liberar_playlist(playlist);
}