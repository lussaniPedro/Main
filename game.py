import os
import msvcrt
import random
import time

player = {
    "personagem": "",
    "nome": "",
    "x": 0,
    "y": 0,
    "pontos": 0
}

moedas = [{"x": random.randint(0, 14), "y": random.randint(0, 9)} for _ in range(10)]
bombas = [{"x": random.randint(0, 14), "y": random.randint(0, 9)} for _ in range(5)]

def digitar_titulo(titulo):
    for char in titulo:
        print(char, end='', flush=True)
        time.sleep(0.1)
    print()

def mover_jogador(direcao):
    if direcao == "d" and player['x'] < 14:
        player['x'] += 1
    elif direcao == "a" and player['x'] > 0:
        player['x'] -= 1
    elif direcao == "s" and player['y'] < 9:
        player['y'] += 1
    elif direcao == "w" and player['y'] > 0:
        player['y'] -= 1

def andar():
    return msvcrt.getch().decode('utf-8').lower()

bombaCount = 0

def verificar_pontos():
    global moedas
    global bombas
    global bombaCount

    for moeda in moedas:
        if player['x'] == moeda['x'] and player['y'] == moeda['y']:
            player['pontos'] += 10
            moedas.remove(moeda)
            break

    for bomba in bombas:
        if player['x'] == bomba['x'] and player['y'] == bomba['y']:
            bombas.remove(bomba)
            player['personagem'] = "☠️"
            bombaCount = 1
            break

os.system('cls')
titulo = "    🐍Python Game🎮"
digitar_titulo(titulo)

player['nome'] = input("Digite o nome do personagem: ")

escolha = 0
while escolha <= 1 or escolha >= 5:
    print("\n🤠, 🤖, 👾, 👽, 👻")
    escolha = int(input("Escolha seu personagem: "))

    if escolha == 1:
        player['personagem'] = '🤠'
    elif escolha == 2: 
        player['personagem'] = '🤖'
    elif escolha == 3:
        player['personagem'] = '👾'
    elif escolha == 4:
        player['personagem'] = '👽'
    elif escolha == 5:
        player['personagem'] = '👻'
    else:
        print("Escolha invalida\n")

while True:
    os.system('cls')

    print(titulo)
    print(f"Jogador: {player['nome']} | Pontos: {player['pontos']}")
    print("-" * 30)

    for y in range(10):
        for x in range(15):
            if player['x'] == x and player['y'] == y:
                print(f"{player['personagem']}", end="")
            elif any(moeda['x'] == x and moeda['y'] == y for moeda in moedas):
                print("💰", end="")
            elif any(bomba['x'] == x and bomba['y'] == y for bomba in bombas):
                print("💣", end="")
            else:
                print("🏁", end="")
        print()

    if bombaCount == 1:
        print("\nFIM DE JOGO!")
        print("Pontuação final:", player['pontos'])
        exit(0)

    print("-" * 30)
    print("Controles: W (cima), A (esquerda), S (baixo), D (direita), E (sair)")

    if not moedas:
        print("\nParabéns! Você coletou todas as moedas! Pontuação final:", player['pontos'])
        break

    direcao = andar()

    if direcao in ['w', 'a', 's', 'd']:
        mover_jogador(direcao)
        verificar_pontos()
    elif direcao == 'e':
        os.system('cls')
        print("Obrigado por jogar! Pontuação final:", player['pontos'])
        break
    else:
        print("Tecla inválida! Use apenas W/A/S/D/E.")
        msvcrt.getch()