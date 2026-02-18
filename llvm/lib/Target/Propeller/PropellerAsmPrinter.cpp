#include "Propeller.h"
#include "TargetInfo/PropellerTargetInfo.h"
#include "llvm/CodeGen/AsmPrinter.h"
#include "llvm/MC/MCStreamer.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Pass.h"
#include "llvm/Support/Compiler.h"

using namespace llvm;

namespace {
class PropellerAsmPrinter : public AsmPrinter {

public:
  explicit PropellerAsmPrinter(TargetMachine &TM,
                               std::unique_ptr<MCStreamer> Streamer);

public:
  static char ID;
};

} // namespace

char PropellerAsmPrinter::ID = 0;

INITIALIZE_PASS(PropellerAsmPrinter, "propeller-asm-printer",
                "Propeller Assembly Printer", false, false)

PropellerAsmPrinter::PropellerAsmPrinter(TargetMachine &TM,
                                         std::unique_ptr<MCStreamer> Streamer)
    : AsmPrinter(TM, std::move(Streamer), ID) {}

extern "C" LLVM_ABI LLVM_EXTERNAL_VISIBILITY void
LLVMInitializePropellerAsmPrinter() {
  RegisterAsmPrinter<PropellerAsmPrinter> X(getThePropellerTarget());
}