# Projeto Calculadora C++

Este é um projeto simples de calculadora em C++ com as operações de soma, subtração e multiplicação.

## Estrutura de Pastas

- `src/` - Código fonte
- `include/` - Arquivos de cabeçalho
- `build/` - Arquivos de build
- `tests/` - Testes unitários (CTest)
- `libs/` - Bibliotecas externas (se necessário)
- `docs/` - Documentação

## Como compilar

1. Crie uma pasta `build` (já criada).
2. Execute os comandos:
   ```
   cd build
   cmake ..
   cmake --build .
   ```

## Como rodar os testes

Dentro da pasta `build`:

```
ctest -C Debug --output-on-failure
```

