# Documentação do Projeto
### Descrição
Este projeto consiste no desenvolvimento de um
interpretador de comandos em linguagem C. O
interpretador será capaz de receber comandos
do usuário, executá-los e exibir os resultados
correspondentes. Utilizando a biblioteca C da
GNU(libc6-dev) para invocar recursos POSIX.

### Métodos Adotados
#### Pipes
Optamos pela criação de pipes infinitos, são criados de acordo
com a quantidade de comandos (número de comandos - 1).
Como consequência, temos uma maior flexibilidade e escalabilidade.
Contudo, possui uma maior latência e complexidade
no gerenciamento de recursos.

### Funcionamento
#### Execução interativa
* O programa será
  iniciado sem argumentos de linha de comando.
* Será exibido um prompt para o usuário,
  indicando que ele pode digitar os comandos.
* Serão interpretados os comandos digitados
  pelo usuário na entrada padrão (stdin).
* um novo prompt só será exibido após a
  conclusão do comando anterior.

#### Execução de Comandos
* Cada linha digitada poderá conter um ou
  mais comandos a serem executados.
* Se houver mais de comando na linha
  eles deverão ser encadeados por pipes ("|"),
  permitindo que a saída de um comando seja a
  entrada para outro comando.

### Fucionalidades Implementadas
* **Execução de comandos simples:**
  O interpretador é capaz de executar comandos
  simples, como programas internos do sistema
  (ex: ls).
* **Manipulação de Redirecionamento de E/S:**
  O interpretador suporta o redirecionamento
  de entrada e saída para arquivos, permitindo
  que o usuário especifique o arquivo de entrada
  ou saída para um comando. Redirecionadores implementados:
    *  `<`: Utilizado para leitura de arquivo
    *  `>`: Utilizado para gravar em um arquivo
    *  `>>`: Utilizado para adicionar em um arquivo
* **Encadeamento de Comandos:** É possível encadear múltiplos comandos através
  do uso do operador pipe ("|"), permitindo que
  a saída seja redirecionada como entrada de
  outro comando.
### Requisitos do Sistema
Para compilar e executar o interpretador de
comandos, o sistema deve atender aos seguintes
requisitos:
* Sistema Operacional Unix/Linux.
* Compilador C compatível com a biblioteca GNU
  libc6-dev.
* Make para automatizar compilação/execução do programa
* Acesso aos recursos POSIX.
### Estrutura do Código-Fonte
O código-fonte do interpretador está organizado
da seguinte maneira:
* **main.c:** Contém a função principal do
  programa, responsável por receber os comandos do
  usuário e iniciar a execução
* **views**
    * **messages**
        * **messages.view.c:** Contém a funcão que
          realiza a saída de mensagens:  
          `ll: No such file or directory` (em caso de erro)

          `rush@shell:~$` (saída padrão)
* **services**
    * **allocation**
        * **allocation.service.c:** Contém todas
          as funções necessárias para manipulação de
          memória das linhas de comando.
    * **commandline**
        * **commandline.service.c:** Contém as
          funções que vão manipular as linhas de
          comando como validação de comando,
          verificação de *exit* e
          divisão da linha em múltiplos comandos
          (caso necessário).
        * **engine**
            * **engine.service.c**
              Serviço motor do shell. Realiza a execução dos comandos,
              configuração dos pipes, redirecionadores.
        * **file**
            * **file.service.c**
              Responsável pela abertura e fechamento de arquivos.

# Compilação e Execução
Siga as instruções abaixo para compilar e executar
o interpretador de comandos:
* Abra um terminal no diretório raiz do projeto.
* Execute o comando *make* para compilar e executar o programa.
* Digite os comandos desejados e pressione
  **Enter** para executá-los.
* Para sair do interpretador, digite o comando *exit*.

# Configuração Inicial do Git

- Clonar o repositório:
```bash
git clone https://github.com/Akles-Camoleze/rush-shell.git
```
- Configurar seu usuário:
```bash
git config --global user.name <seu_nome_no_git>
git config --global user.email <seu_email_no_git>
```

### Realizar Push

Será necessário criar um token para logar no sua conta pelo terminal (ou IDE).

Para isso, deve-se seguir os passos:

- No menu superior, acesse o seu perfil e selecione `Configurações`.
- No menu lateral da tela de configurações, selecione `Configuração de Desenvolvedor`
- Escolha `Token(Classic)` em `Personal Acess Token`.
- Gere um `New Token(Classic)` em `Generate New Token`.
- Marque todas a opções e confirme.
- Após criado, salve-o em um arquivo, pois não será permitida a sua visualização novamente.
- Agora, ao realizar o push, basta inserir seu `user_name` e o `token` gerado no campo de `password`

# Desenvolvedores

- Akles Pires Camoleze
- João Felipe Lamounier
- Ricardo Alves Nascimento
