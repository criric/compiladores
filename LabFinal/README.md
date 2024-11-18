# flexfrontend
INTEGRAÇÃO DO FLEX COM CÓDIGO DE ESTRUTURA DE UM COMPILADOR FRONT-END SIMPLES

> Copyright (c) 2024, Augusto Damasceno.  
> All rights reserved.   
> SPDX-License-Identifier: BSD-2-Clause  
>
> Contact  
> [augustodamasceno@protonmail.com](mailto:augustodamasceno@protonmail.com)


# Abstract

Este laboratório explora a integração do gerador de analisador léxico Flex com o gerador de 
código intermediário. O objetivo principal é adaptar o código 
do analisador léxico manual existente (implementado em lexer.h e lexer.cpp) para utilizar 
o analisador léxico gerado automaticamente pelo Flex.

A lógica de reconhecimento de tokens, anteriormente feita manualmente, será substituída pelo 
código gerado pelo Flex, otimizando o processo de análise léxica no front-end do compilador. 

Este repositório é uma adaptação de laboratórios do material do professor 
Judson Santiago ([JudsonSS](https://github.com/JudsonSS)), disponíveis em: 

* [Gerador de código intermediário](https://github.com/JudsonSS/Compiladores/tree/2e1b81ba859e18e938ea149d1cef2edea04dde36/Labs/Lab11)
* [Exemplos do Flex](https://github.com/JudsonSS/Compiladores/tree/2e1b81ba859e18e938ea149d1cef2edea04dde36/Labs/Lab14)

# Utilização

## Compile

```bash
make
```

# Run

```bash
./tradutor <ARQUIVO-CÓDIGO>
```

# Exemlos em Testes

```bash
./tradutor Testes/teste1.cpp  
./tradutor Testes/teste2.cpp  
./tradutor Testes/teste3.cpp  
./tradutor Testes/teste4.cpp  
```

## Apresentação

* https://youtu.be/PjTIesdU3Cw

# Licença

A licença do repositório base, fornecido pelo professor Judson Santiago, é a MIT License. 
Para este repositório modificado, foi adotada a licença BSD 2-Clause, que é compatível com a licença MIT. 
Essa compatibilidade permite o uso e a redistribuição do código original em projetos sob ambas as licenças, 
mantendo a liberdade para uso, modificação e redistribuição com algumas condições, 
principalmente em relação à atribuição e isenção de responsabilidade.
