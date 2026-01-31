Propeller LLVM Target
=====================

LLVM Target for [Parallax Propeller 1 processor](https://www.parallax.com/download/propeller-1-documentation/).

To build:

```bash
mkdir llvm-project/build
cd llvm-project/build

cmake -G Ninja ../llvm \
  -DCMAKE_INSTALL_PREFIX=${HOME}/llvm/bin \
  -DLLVM_ENABLE_PROJECTS=clang \
  -DLLVM_EXPERIMENTAL_TARGETS_TO_BUILD=Propeller
cmake --build .

```