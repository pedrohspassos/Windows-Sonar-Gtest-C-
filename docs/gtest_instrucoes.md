# Como rodar os testes com GoogleTest

1. Abra o Developer Command Prompt for VS.
2. Navegue até a pasta do projeto:
   ```cmd
   cd \Users\Pedro\Documents\Trabalho\Windows-Ctest1-C++
   ```
3. Crie a pasta de build (se necessário) e entre nela:
   ```cmd
   mkdir build
   cd build
   ```
4. Gere os arquivos de build e baixe o GoogleTest automaticamente:
   ```cmd
   cmake ..
   ```
5. Compile o projeto:
   ```cmd
   cmake --build .
   ```
6. Rode os testes:
   ```cmd
   ctest -C Debug --output-on-failure
   ```
   ou execute diretamente:
   ```cmd
   Debug\test_calculator.exe
   ```

O CMake irá baixar e configurar o GoogleTest automaticamente na primeira vez que rodar.
