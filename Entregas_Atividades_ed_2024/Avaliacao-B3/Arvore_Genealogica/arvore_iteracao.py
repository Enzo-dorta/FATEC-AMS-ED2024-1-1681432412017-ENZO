import colorama
from colorama import Fore, Back, Style

colorama.init()

tam_familia = int(input("Digite o tamanho da sua familia: "))

familia = {}
familia_ordem={}

vermelho = '\033[31m'
verde = '\033[32m'
azul = '\033[34m'
pink ='\033[1;35m'

reset = '\033[0;0m'

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

            if diferenca > 15 and diferenca < 50:
                print( vermelho + nome_now + reset + " pode ser pai/mãe de " + nome_next )

            if diferenca < -15 and diferenca > -50:
                print( vermelho + nome_now + reset + " pode ser filho(a) de " + nome_next)

            if diferenca <= 15 and diferenca >= -15:
                print(pink + nome_now + reset + " e " + nome_next + " podem ser irmãos(ãs) ou casal")

            if diferenca <= -80:
                print(azul + nome_now + reset + " pode ser bisneto(a) de " + nome_next )
            
            if diferenca >= 80:
                print( azul + nome_now + reset + " pode ser bisavô/vó de " + nome_next)
            
            if diferenca < 80 and diferenca >= 50:
                print(verde + nome_now + reset + " pode ser avô/avó de " + nome_next)

            if diferenca <=-50 and diferenca > -80:
                print(verde + nome_now + reset + " pode ser neto(a) de " + nome_next)

            colorama.deinit()




# bisavo - bisneto > 0 -> 
