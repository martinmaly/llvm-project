Propeller LLVM Target
=====================

LLVM Target for [Parallax Propeller 1 processor](https://www.parallax.com/download/propeller-1-documentation/).

To build:

```bash
mkdir llvm-project/build
cd llvm-project/build

cmake -G Ninja ../llvm \
  -DLLVM_USE_LINKER=lld \
  -DLLVM_OPTIMIZED_TABLEGEN=On \
  -DCMAKE_C_COMPILER:FILEPATH=/usr/bin/clang-21 \
  -DCMAKE_CXX_COMPILER:FILEPATH=/usr/bin/clang++-21 \
  -DCMAKE_LINKER:FILEPATH=/usr/bin/lld-21 \
  -DCMAKE_INSTALL_PREFIX=${HOME}/llvm/bin \
  -DLLVM_ENABLE_PROJECTS=clang \
  -DLLVM_EXPERIMENTAL_TARGETS_TO_BUILD=Propeller
cmake --build .

```

To build debug:

```bash
mkdir llvm-project/build-debug
cd llvm-project/build-debug

cmake -G Ninja ../llvm \
  -DCMAKE_BUILD_TYPE=Debug \
  -DLLVM_USE_LINKER=lld \
  -DLLVM_OPTIMIZED_TABLEGEN=On \
  -DCMAKE_C_COMPILER:FILEPATH=/usr/bin/clang-21 \
  -DCMAKE_CXX_COMPILER:FILEPATH=/usr/bin/clang++-21 \
  -DCMAKE_LINKER:FILEPATH=/usr/bin/lld-21 \
  -DCMAKE_INSTALL_PREFIX=${HOME}/llvm/bin \
  -DLLVM_ENABLE_PROJECTS=clang \
  -DLLVM_EXPERIMENTAL_TARGETS_TO_BUILD=Propeller
cmake --build .

```

Tablegen:

```bash

cd /home/martin/llvm-project/build/lib/Target/Propeller && \
/home/martin/llvm-project/build/NATIVE/bin/llvm-tblgen \
  -I/home/martin/llvm-project/llvm/lib/Target/Propeller \
  -I/home/martin/llvm-project/build/include \
  -I/home/martin/llvm-project/llvm/include \
  -I /home/martin/llvm-project/llvm/lib/Target \
  /home/martin/llvm-project/llvm/lib/Target/Propeller/Propeller.td \
  --write-if-changed \
  -o out.td

cd /home/martin/llvm-project/build/lib/Target/Sparc && \
/home/martin/llvm-project/build/NATIVE/bin/llvm-tblgen \
  -I/home/martin/llvm-project/llvm/lib/Target/Sparc \
  -I/home/martin/llvm-project/build/include \
  -I/home/martin/llvm-project/llvm/include \
  -I /home/martin/llvm-project/llvm/lib/Target \
  /home/martin/llvm-project/llvm/lib/Target/Sparc/Sparc.td \
  --write-if-changed \
  -o out.td
```
