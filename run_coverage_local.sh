#!/bin/bash
# Modo de rodar
# - chmod +x run_coverage_local.sh
# ./run_coverage_local.sh

set -e  # Encerra o script se algum comando falhar

echo "🧹 Limpando diretório de build..."
rm -rf build && mkdir build

echo "⚙️ Rodando CMake com cobertura ativada..."
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug -DCODE_COVERAGE=ON

echo "🔨 Compilando projeto..."
cmake --build build

echo "🧪 Executando testes com CTest..."
cd build
ctest --output-on-failure
cd ..

echo "📊 Gerando relatório de cobertura (target 'coverage')..."
cmake --build build --target coverage

echo "✅ Relatórios gerados com sucesso:"
echo "   - build/coverage.html"
echo "   - build/coverage.xml"
