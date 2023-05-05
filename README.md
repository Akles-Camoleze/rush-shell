### Configuração Inicial do Git

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
