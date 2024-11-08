#pragma once

// Dimensioni della finestra di gioco
const int WINDOW_WIDTH = 360;
const int WINDOW_HEIGHT = 640;

// Titolo del gioco
const char* GAME_TITLE = "Flappy Bird";

// Percorsi delle risorse
const char* FONT = "assets/fonts/AlikeAngular-Regular.ttf";
const char* BACKGROUND_TEXTURE = "assets/images/background.png";
const char* BIRD_TEXTURE = "assets/images/flappybird.png";
const char* PIPEUP_TEXTURE = "assets/images/pipeup.png";
const char* PIPEDOWN_TEXTURE = "assets/images/pipedown.png";

// Dimensioni e posizioni degli oggetti
const int BIRD_WIDTH = 34;
const int BIRD_HEIGHT = 24;
const int PIPE_WIDTH = 64;  // Larghezza della pipe
const int PIPE_HEIGHT = 512;  // Altezza della pipe
const int OPENING_HEIGHT = 200;  // Altezza dell'apertura tra le pipe

// Posizioni iniziali
const int PIPE_X = WINDOW_WIDTH;  // Posizione orizzontale iniziale delle pipe (fuori dallo schermo a destra)
const int PIPE_Y = 0;  // Posizione verticale iniziale del tubo superiore
const int BIRD_X = WINDOW_WIDTH / 8;
const int BIRD_Y = WINDOW_HEIGHT / 2;
