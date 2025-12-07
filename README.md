# 🎮 Projeto SDL - Fase 1 Completada

## 📋 Descrição
Projeto educativo para aprender fundamentos de SDL3 e criação de motor de jogo básico.

## 🎯 Objetivos Alcançados (Fase 1)
- [x] Criar janela com Game Loop básico
- [x] Processar input (teclado/mouse)
- [x] Desenhar formas primitivas com controle de cores RGB
- [x] Implementar Delta Time para movimento suave
- [x] Carregar e desenhar texturas (BMP)

## 🎮 Controles
- **WASD / Setas**: Mover quadrado
- **1-9**: Mudar cor do quadrado
- **0**: Modo textura (se disponível)
- **Clique Mouse**: Teletransportar (cooldown)
- **ESC**: Sair

## 🛠️ Como Compilar
```bash
g++ -o jogo main.cpp -lSDL3
📁 Estrutura
text
projeto/
├── main.cpp          # Código fonte principal
├── foto.bmp          # Textura do jogador (opcional)
└── README.md         # Esta documentação
```

## 🚀 Próximos Passos (Fase 2)
- Física básica (velocidade, aceleração)

- Gravidade e sistema de pulo

- Detecção de colisão (AABB)

- Sistema de estados (Menu, Jogo, Game Over)

## 📚 Aprendizados
- Loop principal de jogos

- Gerenciamento de tempo (Delta Time)

- Renderização 2D básica

- Processamento de entrada

- Gerenciamento de memória com SDL
