#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h> // Mantenha esta linha
#include <iostream>
#include <SDL3/SDL_oldnames.h>

bool quadradoBorda(int posX, int posY, int larguraJanela, int alturaJanela, int larguraQuadrado, int alturaQuadrado);
void setCorQuadrado(SDL_Renderer* renderer, int numeroCor);

int main(int argc, char* args[]) {
    SDL_Init(SDL_INIT_VIDEO);

    // 🎯 VARIAVEIS DO QUADRADO (não da janela!)
    float quadradoX = 400.0f;  // Posição X do quadrado
    float quadradoY = 300.0f;  // Posição Y do quadrado
    const float VELOCIDADE = 500.0f;
    float novaX = 0;
    float novaY = 0;

    SDL_Window *window = SDL_CreateWindow(
        "desafio 2",
        800,
        600,
        0
    );

    SDL_Renderer *renderer = SDL_CreateRenderer(window, NULL);
    SDL_FRect quadrado = {quadradoX, quadradoY, 50, 50};
    int windowWidth, windowHeight;
    SDL_GetWindowSize(window, &windowWidth, &windowHeight);

    int delay = 20;
    bool teleport = true;
    bool quit = false;
    int corAtual = 1;
    SDL_Event e;
    bool keyUpPressed = false;
    bool keyDownPressed = false;
    bool keyRightPressed = false;
    bool keyLeftPressed = false;

    while(!quit){
        static Uint64 lastTime = SDL_GetPerformanceCounter();
        Uint64 now = SDL_GetPerformanceCounter();
        float deltaTime = (now - lastTime) / (float)SDL_GetPerformanceFrequency();
        lastTime = now;
         // 🎮 PROCESSAR EVENTOS
        while(SDL_PollEvent(&e) != 0){
            if(e.type == SDL_EVENT_QUIT){
                quit = true;
            }
            if(e.type == SDL_EVENT_KEY_DOWN){
                if(e.key.key == SDLK_ESCAPE){
                    quit = true;
                }
                if(e.key.key == SDLK_1 || e.key.key == SDLK_2 || e.key.key == SDLK_3 || e.key.key == SDLK_4 || e.key.key == SDLK_5 ||
                    e.key.key == SDLK_6 || e.key.key == SDLK_7 || e.key.key == SDLK_8 || e.key.key == SDLK_9){
                        if(e.key.key == SDLK_1){
                            corAtual = 1;
                            SDL_RenderFillRect(renderer, &quadrado);
                        }
                        if(e.key.key == SDLK_2){
                            corAtual = 2;
                            SDL_RenderFillRect(renderer, &quadrado);
                        }
                        if(e.key.key == SDLK_3){
                            corAtual = 3;
                            SDL_RenderFillRect(renderer, &quadrado);
                        }
                        if(e.key.key == SDLK_4){
                            corAtual = 4;
                            SDL_RenderFillRect(renderer, &quadrado);
                        }
                        if(e.key.key == SDLK_5){
                            corAtual = 5;
                            SDL_RenderFillRect(renderer, &quadrado);
                        }
                        if(e.key.key == SDLK_6){
                            corAtual = 6;
                            SDL_RenderFillRect(renderer, &quadrado);
                        }
                        if(e.key.key == SDLK_7){
                            corAtual = 7;
                            SDL_RenderFillRect(renderer, &quadrado);
                        }
                        if(e.key.key == SDLK_8){
                            corAtual = 8;
                            SDL_RenderFillRect(renderer, &quadrado);
                        }
                        if(e.key.key == SDLK_9){
                            corAtual = 9;
                            SDL_RenderFillRect(renderer, &quadrado);
                        }
                        
                }
                
                // 🎯 MOVER O QUADRADO (não a janela!)
                if(e.key.key == SDLK_UP || e.key.key == SDLK_W){
                    keyUpPressed = true;
                }
                if(e.key.key == SDLK_DOWN || e.key.key == SDLK_S){
                    keyDownPressed = true;
                }
                if(e.key.key == SDLK_RIGHT || e.key.key == SDLK_D){
                    keyRightPressed = true;
                }
                if(e.key.key == SDLK_LEFT || e.key.key == SDLK_A){
                    keyLeftPressed = true;
                }
                
                std::cout << "Quadrado em: X=" << quadradoX << ", Y=" << quadradoY << std::endl;
            }
            if(e.type == SDL_EVENT_MOUSE_BUTTON_DOWN){
                if(teleport){
                    //pegar a posicao do mouse e por o quadrado la
                    float mouseX, mouseY;
                    SDL_GetMouseState(&mouseX, &mouseY);
                    quadradoX = mouseX - 25;  // 25 = metade de 50
                    quadradoY = mouseY - 25;
                    quadrado.x = quadradoX;  // <-- FALTA ISSO!
                    quadrado.y = quadradoY;  // <-- FALTA ISSO!
                    
                    teleport = false;
                }
                
            }
            if(e.type == SDL_EVENT_KEY_UP){
                if(e.key.key == SDLK_UP || e.key.key == SDLK_W){
                    keyUpPressed = false;
                }
                if(e.key.key == SDLK_DOWN || e.key.key == SDLK_S){
                    keyDownPressed = false;
                }
                if(e.key.key == SDLK_LEFT || e.key.key == SDLK_A){
                    keyLeftPressed = false;
                }
                if(e.key.key == SDLK_RIGHT || e.key.key == SDLK_D){
                    keyRightPressed = false;
                }
            }
        }

        if(keyUpPressed){
            novaY = quadradoY - (VELOCIDADE * deltaTime);
            if(novaY >= 0){
                //SDL_Delay(delay);
                quadradoY -= VELOCIDADE * deltaTime;
                quadrado.y = quadradoY;
            }
        }
        if(keyDownPressed){
            novaY = quadradoY + (VELOCIDADE * deltaTime);
            if(novaY + 50 < windowHeight){
                //SDL_Delay(delay);
                quadradoY += VELOCIDADE * deltaTime;  // Move para baixo
                quadrado.y = quadradoY;
            }
        }
        if(keyRightPressed){
            novaX = quadradoX + (VELOCIDADE * deltaTime);
            if(novaX + 50 < windowWidth){
                //SDL_Delay(delay);
                quadradoX += VELOCIDADE * deltaTime;  // Move para direita
                quadrado.x = quadradoX;
            }
        }
        if(keyLeftPressed){
            novaX = quadradoX - (VELOCIDADE * deltaTime);
            if(novaX >= 0){
                //SDL_Delay(delay);
                quadradoX -= VELOCIDADE * deltaTime;  // Move para esquerda
                quadrado.x = quadradoX;
            }
        } 
        
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        
        // 3. Desenhar quadrado (vermelho)
        setCorQuadrado(renderer, corAtual);  // Vermelho
        SDL_RenderFillRect(renderer, &quadrado);  // 🎯 FUNÇÃO CORRETA!
        
        // 4. Mostrar na tela
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    
    return 0;
}

bool quadradoBorda(int posX, int posY, int larguraJanela, int alturaJanela, int larguraQuadrado, int alturaQuadrado) {
    // Verifica se o quadrado está TOCANDO as bordas
    return (posX <= 0 ||                        // Borda esquerda
            posX + larguraQuadrado >= larguraJanela ||  // Borda direita
            posY <= 0 ||                        // Borda superior
            posY + alturaQuadrado >= alturaJanela);     // Borda inferior
}

void setCorQuadrado(SDL_Renderer* renderer, int numeroCor) {
    switch(numeroCor) {
        case 1: // Vermelho
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
            break;
        case 2: // Verde
            SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
            break;
        case 3: // Vermelho
            SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
            break;
        case 4: // Verde
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            break;
        case 5: // Vermelho
            SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
            break;
        case 6: // Verde
            SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);
            break;
        case 7: // Verde
            SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
            break;
        case 8: // Vermelho
            SDL_SetRenderDrawColor(renderer, 50, 150, 150, 255);
            break;
        case 9: // Verde
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            break;
        //case 0:
            //fazer ele ficar mudando de cor
            //SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
            //break;
        // ... adicione mais cores
    }
}