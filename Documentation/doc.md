# Documentação do Projeto
### Descrição 
Este projeto consiste no desenvolvimento de um
interpretados de comandos em linguagem C. O
interpretador será capaz de receber comandos
do usuário, executá-los e exibir os resultados
correspondentes. Utilizando a biblioteca C da 
GNU(libc6-dev) para invocar recursos POSIX.

### Funcionamento
#### Execução interativa: 
* O programa será 
iniciado sem argumentos de linha de comando.
* Será exibido um prompt para o usuário,
indicando que ele pode digitar os comandos.
    * `rush@shell:~$`
* O interpretador lerá os coamandos digitados
pelo usuário na entrada padrão (stdin).
* um novo prompt só será exibido após a 
conclusão do comando anterior.

#### Execução de Comandos
* Cada linha digitada poderá conter um ou
mais comandos a serem executados.
* Se houver mais de comando na linha
eles deverão ser encadeados por pipes ("|"),
permitindo que a saída de um coamando seja a 
entrada para outro comando.

### Fucionalidades Implementadas
* **Execução de comandos simples:**
O interpretador é capaz de executar comandos
simples, como programas internos do sistema
(ex:'ls').
* **Manipulação de Redirecionamento de E/S:**
O interpretador suporta o redirecionamento
de entrada e saída para arquivos, permitindo
que o usuário especifique o arquivo de entrada
ou saída para um comando.
* **Encadeamento de Comandos:** É possível encadear múltiplos comandos através
do uso do operador pipe ('|'), permitindo que
a saída seja redirecionada como entrada de 
outro comando.
### Requisitos do Sistema
Para compilar e executar o interpretador de 
comandos, o sistema deve atender aos seguintes
requisitos: 
* Sistema Operacional Unix/Linux.
* Compilador C compatível com a biblioteca GNU
libc6-dev.
* Acesso aos recursos POSIX.
### Estrutura do Código-Fonte
O código-fonte do interpretador está organizado
da seguinte maneira:
* **main.c:** Contém a função principal do 
programa, responsável por ler os comandos do 
usuário e iniciar a execução
* **views**
  * **messages**
    * **messages.view.c:** Contém a funcão que
    realiza a saída de mensagens, permitindo
    que o usuário visualize resultados dos programas.  
    `rush@shell:~$ ll`  
     `ll: No such file or directory`
* **services**
  * **allocation**
    * **allocation.service.c:** Contém todas
    as funções necessárias para manipulação de
    memória das linhas de comando.
  * **commandline**
    * **commandline.service.c:** Contém as
    funções que vão manipular as linhas de
    comando como validação de comando, 
    verificação de *exit* no início da linha e
    divisão da linha em múltiplos comandos
      (caso necessário).
    * **engine**
      * **engin.service.c**
      ---- Ainda a fazer----
* **io-exceptions**
  * **exceptions.c:** Responsável por salva
  as excessões de entrada e saída em um arquivo
  .log
  
### Compilação e Execução 
Siga as instruções abaixo para compilar e executar
o interpretador de comandos:
* Abra um terminal no diretório raiz do projeto.
* Execute o comando *make* para compilar o programa.
* Após a compilação, execute o comando 
./main para iniciar o interpretador.
* Digite os comandos desejados e pressione 
**Enter** para executá-los.
* Para sair do interpretador, digite o comando *exit*.


