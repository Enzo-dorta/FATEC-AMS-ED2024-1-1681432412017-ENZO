**<h1 align="center" style="font-family: Arial; font-size: 30px;">Permutação de Árvore Genealógica</h1>**

**<h3 style="font-family: Arial; font-size: 20px;">Sobre o Projeto:</h3>**
<p style="font-family: Arial; font-size: 15px;">O projeto tem como objetivo calcular as permutações de uma árvore genealógica usando iteração, onde só é permitido colocar
nome e idade de cada membro da família e, de acordo com os casos de negócio, o programa irá calcular todas
as possibilidades.</p>

**<h3 style="font-family: Arial; font-size: 20px;">O que é Iteração?</h3>**
<p style="font-family: Arial; font-size: 15px;">
A iteração é um conceito fundamental em programação e matemática que se refere ao processo de repetir uma sequência de instruções ou operações. Esse conceito é amplamente utilizado em loops e estruturas de repetição para realizar tarefas repetitivas de forma eficiente.
</p>

**<h3 style="font-family: Arial; font-size: 20px;">Casos de Uso:</h3>**
<p style="font-family: Arial; font-size: 15px;">
Para o programa ficar mais verídico criamos alguns casos de negócio.Claro, nem todas as famílias seguem esse padrão, mas foi nossa solução para que a árvore fique mais coesa e mais realista.
</p>

1. Uma pessoa mais nova não pode ser genitora de uma pessoa mais velha;
2. Se a diferença de idade entre duas pessoas for 15 anos ou menos, elas devem ser consideradas irmãs ou um casal;
3. Se a diferença de idade entre duas pessoas for mais de 15 anos e menos de 50, elas devem ser consideradas filho e pai;
4. Se a diferença de idade entre duas pessoas for mais de 50 anos e menos de 80, elas devem ser consideradas avô e neto;
5. Se a diferença de idade entre duas pessoas for mais de 80 anos, elas devem ser consideradas bisavô e bisneto.



**<h3 style="font-family: Arial; font-size: 20px;">Análise Sintática:</h3>**
<p style="font-family: Arial; font-size: 15px;">
A análise sintática envolve a decomposição do código em suas unidades fundamentais, como estruturas de controle, chamadas de função e atribuições.
</p>

**<h3 style="font-family: Arial; font-size: 15x;">Entrada do Usuário</h3>**

- **Cabeçalho**: Entrada do usuário com o `tamanho` de sua familia.</br>
Como a entrada é feita apenas uma vez é definida por `O(1)`.

```python
tam_familia = int(input("Digite o tamanho da sua familia: "))
```

**<h3 style="font-family: Arial; font-size: 15x;">Criação do Dicionário</h3>**

- **Cabeçalho**: Entrada do usuário com o `nome` e `idade` de sua familia de acordo com o tamanho dela.</br>
Como a entrada é feita **N** vezes é definida por `O(n)`, sendo N o `tam_familia`.

```python
for i in range(tam_familia):
    nome = str(input(f"digite o nome do {i+1}º integrante: "))
    idade = int(input("digite  idade dele: "))
    familia[f'{nome}'] = idade
```

**<h3 style="font-family: Arial; font-size: 15x;">Ordenação do Dicionário</h3>**

- **Cabeçalho**: A ordenação do dicionário utiliza o método `sorted`, que tem complexidade `O(n log n)`.</br>
O loop em si, que atribui valores ao dicionário `familia_ordem`, é **O(n)**.</br>
Logo, nesta parte a complexidade total é `O(n log n)`.

```python
for i in sorted(familia, key=familia.get, reverse=True):
    familia_ordem[f'{i}'] = familia[i]
```

**<h3 style="font-family: Arial; font-size: 15x;">Conversão para Lista</h3>**

- **Cabeçalho**: Aqui o dicionário é transformado em uma lista chamada `lista_familia`.</br>
A complexidade é `O(n)`, já que envolve iterar todos os itens do dicionário.

```python
lista_familia = list(familia_ordem.items())
```

**<h3 style="font-family: Arial; font-size: 15x;">Comparação das Idades</h3>**

- **Cabeçalho**: Nesta parte do código ele faz um loop para comparar as `idades` da lista.</br>
Como o loop intera **N** vezes e o loop interno também itera **N** vezes. O total resulta em `O(n²)`

```python
for i in range(len(lista_familia)):
    nome_now, idade_now = lista_familia[i]

    for j in range(len(lista_familia)):
        if i != j:
            nome_next, idade_next = lista_familia[j]
            diferenca = idade_now - idade_next
            ...
```

**<h3 style="font-family: Arial; font-size: 20px;">Complexidade de Tempo</h3>**

### O que é Complexidade de Tempo (Big O)?

A **complexidade de tempo** (Big O) nos diz como o tempo de execução de um algoritmo cresce à medida que a entrada aumenta. No seu caso, estamos falando de como o código responde conforme você adiciona mais pessoas (membros da família).

- **O(1)** significa que o tempo de execução é **constante**, ou seja, o tempo não muda independentemente do número de membros. 
- **O(n)** significa que o tempo de execução **cresce linearmente**, ou seja, o tempo aumenta proporcionalmente ao número de membros.
- **O(n log n)** significa que o tempo de execução do algoritimo **cresce linearmente** em relação ao tamanho da entrada **N**., multiplicado pelo logaritimo desse tamanho.
- **O(n²)** significa que o tempo de execução **cresce quadraticamente**, ou seja, se o número de membros dobra, o tempo de execução pode quadruplicar.


**<h3 style="font-family: Arial; font-size: 20px;">E no nosso programa qual é o BigO?</h3>**

<p style="font-family: Arial; font-size: 15px;">
No nosso caso a complexidade mais alta do nosso código é O(n²), denomidada pelo bloco que compara as idades
</p>

```python
for i in range(len(lista_familia)):
    nome_now, idade_now = lista_familia[i]

    for j in range(len(lista_familia)):
        if i != j:
            nome_next, idade_next = lista_familia[j]
            diferenca = idade_now - idade_next
            ...
```
