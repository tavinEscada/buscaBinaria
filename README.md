## Requisitos
- Compilador de arquivos em C como o GCC
- MinGW

## Compilação e execução
Abra o terminal no diretório do projeto.
Compile o programa com o comando de terminal:
mingw32-make

Execute o programa com:
./main

## Funcionamento
Inicialmente, escolha o exemplo de aplicação de busca binária digitando 1 (aplicação em livros) ou 2 (aplicação em pacotes).
No caso 1, digita-se o número de livros e deve-se inserir nas linhas seguintes o número que identifica o livro, um espaço e o nome do livro, *sem espaços no nome* (Exemplo: 12 ManifestoComunista), repetindo o processo para os livros restantes. Depois, digita-se o número que identifica o livro desejado e obtém-se a saída com a posição do livro no vetor e o nome de tal livro.
O caso 2 é semelhante, com exceção de que o pacote só é identificado pelo nome, e por isso a pesquisa é feita a partir do nome.
