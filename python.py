import os

def menu():
    op = 1
    while(op != 0):
        os.system("cls")
        print("| Menu:              |")
        print("|                    |")
        print("| 1. Cadastrar Livro |")
        print("| 2. Listar livros   |")
        print("| 0. Sair            |\n")

        op = int(input("Digite a opção: "))

        match(op):
            case 0:
                os.system("cls")
                print("Saindo...")
                break
            case 1:
                os.system("cls")
                cadastrarLivro()
            case 2:
                os.system("cls")
                listarLivros()
            case __:
                print("Erro, opção inválida")
                os.system("pause")

def cadastrarLivro():
    
    global titulo
    global autor
    global data
    global dia, mes, ano

    titulo = input("Digite o titulo do livro: ")
    autor = input("Digite o nome do autor: ")
    data = input("Digite a data de publicação: ")

    dia, mes, ano = data.split()

    dia = int(dia)
    mes = int(mes)
    ano = int(ano)

def listarLivros():
    print(f"| Titulo do livro: {titulo}") 
    print(f"| Autor do livro: {autor}") 
    print(f"| Data de publicação: {dia}/{mes}/{ano}\n") 
    os.system("pause")           

menu()