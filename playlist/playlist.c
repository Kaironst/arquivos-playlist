#include <stdio.h>
#include <stdlib.h>
#include "playlist.h"

Playlist* criar_playlist() {
    Playlist* playlist = (Playlist*) malloc(sizeof(Lista));
    lista->fim = NULL;
    return lista;
}

void liberar_playlist(Playlist* playlist);

// Gerenciamento de músicas
void adicionar_musica(Playlist* playlist, const char* titulo, const char* artista, int duracao);
int remover_musica(Playlist* playlist, const char* titulo);

// Navegação
void proxima_musica(Playlist* playlist);
void musica_anterior(Playlist* playlist);

// Configuração
void alternar_modo_repeticao(Playlist* playlist);

// Visualização
void listar_musicas(Playlist* playlist);
Musica* buscar_musica(Playlist* playlist, const char* titulo);
void exibir_musica_atual(Playlist* playlist);