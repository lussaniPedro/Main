# Projeto: Liga Coruja de Futsal

## 📋 Descrição Geral

Programa para controle de **turmas**, **times** e **jogadores** da *Liga Coruja de Futsal*. Envolve:

- Alocação dinâmica
- `structs`
- Funções
- Operações com arquivos (salvar e recuperar dados)

## 📌 Menu Principal

```text
LIGA CORUJA DE FUTSAL

1. TURMA
2. TIME
3. SAIR
```

## 🏫 Menu TURMA

```text
1. INCLUIR  
2. ALTERAR  
3. EXCLUIR  
4. LISTAR  
5. VOLTAR
```

### Estrutura de uma TURMA

- **NOME DA TURMA**: `string`  
- **CURSO**: `enum {info, mec, mamb, tads, tga, csoc}`  
- **ANO**: `int` (positivo)

#### 🧾 Exemplo:

```text
NOME: INFO22  
CURSO: INFO  
ANO: 2022
```

### ⚙️ Regras

- **ALTERAR** e **EXCLUIR** devem solicitar confirmação.
- **LISTAR** mostra o menu:

```text
1. LISTAR TURMA  
2. LISTAR TODAS  
3. VOLTAR
```

## 🏆 Menu TIME

```text
1. INCLUIR  
2. ALTERAR  
3. EXCLUIR  
4. LISTAR  
5. VOLTAR
```

### Estrutura de um TIME

- **NOME**: `string`
- **TÉCNICO**: `string`
- **JOGADORES**: lista de até 10 jogadores
- **TURMAS**: até 2 turmas diferentes (nome da turma)

#### 🧾 Exemplo:

```text
NOME: Mec21  
TÉCNICO: Lauro Traíra  
TURMAS: MEC21, MAMB20  
```

## 🧍 Estrutura de um JOGADOR

- **NOME**: `string`  
- **MATRÍCULA**: `string`  
- **NÚMERO DA CAMISA**: `int` (positivo)  
- **POSIÇÕES**: `enum {goleiro, ala D, ala E, fixo, pivô}` (múltiplas possíveis)  
- **DATA DE NASCIMENTO**: `struct` com `dia`, `mês`, `ano`  
- **TURMA**: escolhida entre turmas cadastradas  

## ⚙️ Menu ATUALIZAR JOGADORES

```text
1. Incluir Novo Jogador  
2. Alterar Jogador  
3. Excluir Jogador  
4. Voltar
```

### Menu ALTERAR JOGADOR

```text
1. Nome do Jogador  
2. Matrícula  
3. Número da Camisa  
4. Posições  
5. Data de Nascimento  
6. Turma (não permite turma não cadastrada)  
7. Voltar
```

## 🔧 Menu ALTERAR TIME

```text
1. Nome do Time  
2. Nome do Técnico  
3. Jogadores  
4. Voltar
```

> ⚠️ A propriedade **turmas** é atualizada automaticamente ao incluir/alterar jogadores.

## 📌 Observações

- A `main()` deve apenas chamar outras funções.  
- Cada função deve cumprir **uma responsabilidade única**.  
- Salve os dados de **times** e **turmas** em arquivos **separados**.

## 🔗 Referência

📺 [Canal de apoio no YouTube](https://www.youtube.com/channel/UCy1Qj6-gEiLj-DPmoKvJZkA)

## 🕒 Entrega

- **Prazo final:** 30/11/2023  
- **Formato:** Trabalho em dupla