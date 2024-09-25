import colorama
from colorama import Fore, Back, Style

colorama.init()

tam_familia = int(input("Digite o tamanho da sua familia: "))

familia = {}
familia_ordem={}

for i in range (tam_familia):
    nome = str(input(f"digite o nome do {i+1}º integrante: "))
    idade = int(input("digite  idade dele: "))
    familia[f'{nome}'] = idade

for i in sorted(familia, key = familia.get, reverse = True):
    familia_ordem[f'{i}'] = familia[i]
    
print(familia_ordem)

lista_familia = list(familia_ordem.items())

for i in range(len(lista_familia)):
    nome_now, idade_now = lista_familia[i]
    nomeM, idadeM = lista_familia[0]

    for j in range(len(lista_familia)):
        if i != j:
            nome_next, idade_next = lista_familia[j]

            diferenca = idade_now - idade_next

            if diferenca > 15 and diferenca <= 50:
                print(Fore.BLUE + nome_now + " e " + nome_next + f" podem ser pai/mãe e filho(a). diferença {diferenca}")

            if diferenca < -15 and diferenca >= -50:
                print(Fore.BLUE + nome_now + " e " + nome_next + f" podem ser pai/mãe e filho(a). diferença {diferenca}")

            if diferenca <= 15 and diferenca >= -15:
                print(Fore.YELLOW + nome_now + " e " + nome_next + f" podem ser irmãos(ãs) ou casal . diferença {diferenca}")

            if diferenca < -80 or diferenca > 80:
                print(Fore.GREEN + nome_now + " e " + nome_next + f" podem ser bisavô(vó) e bisaneto(a)")
            
            if diferenca < 80 and diferenca > 50:
                print(Fore.RED + nome_now + " e " + nome_next + f" podem ser avô(ó) e neto(a)")

            if diferenca < -50 and diferenca > -80:
                print(Fore.RED + nome_now + " e " + nome_next + f" podem ser avô(ó) e neto(a)")

            colorama.deinit()




# bisavo - bisneto > 0 -> 
