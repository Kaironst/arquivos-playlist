#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "playlist.h"

Playlist* criar_playlist() {
    Playlist* playlist = (Playlist*) malloc(sizeof(Playlist));
    playlist->atual = NULL;
    return playlist;
}

void liberar_playlist(Playlist* playlist) {
    Musica* aux=playlist->atual->proxima,* inicial=playlist->atual;
    while(aux->proxima!=inicial) {
        playlist->atual->proxima=playlist->atual->proxima->proxima  ;
        free(aux);
        aux=playlist->atual->proxima;
    }
    free(aux);
    free(playlist->atual);
    free(playlist);
}

// Gerenciamento de músicas
void adicionar_musica(Playlist* playlist, const char* titulo, const char* artista, int duracao) {
    Musica *musica = (Musica*) malloc(sizeof(Musica));
    strcpy(musica->titulo, titulo); strcpy(musica->artista, artista); musica->duracao=duracao;
    if (playlist->atual == NULL) {
        musica->proxima = musica;
        playlist->atual = musica;
        return;
    }
    musica->proxima=playlist->atual->proxima;
    playlist->atual->proxima=musica;
    playlist->tamanho++;
    //isso adiciona a musica ao inicio da playlist (com atual apontando ao final) ou seja, logo depois do atual.
}

int remover_musica(Playlist* playlist, const char* titulo) {
    Musica* aux=buscar_musica(playlist, titulo),* anterior=playlist->atual->proxima;
    if (aux==NULL) return 0;
    while (anterior->proxima!=aux) anterior=anterior->proxima;
    if (aux==playlist->atual) playlist->atual=playlist->atual->proxima;
    anterior->proxima=aux->proxima;
    free(aux);
}

// Navegação
void proxima_musica(Playlist* playlist) {
    playlist->atual=playlist->atual->proxima;
}

void musica_anterior(Playlist* playlist) {
    Musica* aux=playlist->atual->proxima;
    while (aux->proxima!=playlist->atual) aux=aux->proxima;
    playlist->atual=aux;
}

// Configuração
void alternar_modo_repeticao(Playlist* playlist) {
    if (playlist->modo_repeticao==1) playlist->modo_repeticao=0;
    else playlist->modo_repeticao=1;
}

// Visualização
void listar_musicas(Playlist* playlist) {
    Musica* aux=playlist->atual;
    do {
        printf("nome: %s, autor: %s, duração total: %d \n",aux->titulo, aux->artista, aux->duracao);
        aux=aux->proxima;
    }while (aux!=playlist->atual);
}

Musica* buscar_musica(Playlist* playlist, const char* titulo) {
    Musica *aux=playlist->atual;
    do {
        if (strcmp(aux->titulo,titulo)==0) return aux;
        aux=aux->proxima;
    }while(aux!=playlist->atual);
    return NULL;
}

void exibir_musica_atual(Playlist* playlist) {
    printf("nome: %s, autor: %s, duração total: %d \n", playlist->atual->titulo, playlist->atual->artista, playlist->atual->duracao);
}