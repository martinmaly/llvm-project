#include "Propeller.h"
#include "PropellerTargetMachine.h"
#include "llvm/CodeGen/SelectionDAGISel.h"
#include "llvm/Pass.h"

namespace {

class PropellerDAGToDAGISel : public llvm::SelectionDAGISel {
public:
  PropellerDAGToDAGISel() = delete;
  explicit PropellerDAGToDAGISel(llvm::PropellerTargetMachine &TM);

  void Select(llvm::SDNode *N) override;
};

class PropellerDAGToDAGISelLegacy : public llvm::SelectionDAGISelLegacy {
public:
  static char ID;
  explicit PropellerDAGToDAGISelLegacy(llvm::PropellerTargetMachine &TM);
};

} // namespace

PropellerDAGToDAGISel::PropellerDAGToDAGISel(llvm::PropellerTargetMachine &TM)
    : SelectionDAGISel(TM) {}

void PropellerDAGToDAGISel::Select(llvm::SDNode *N) {
  assert(false && "Not Implemented");
}

char PropellerDAGToDAGISelLegacy::ID = 0;

PropellerDAGToDAGISelLegacy::PropellerDAGToDAGISelLegacy(
    llvm::PropellerTargetMachine &TM)
    : SelectionDAGISelLegacy(ID, std::make_unique<PropellerDAGToDAGISel>(TM)) {}

llvm::FunctionPass *llvm::createPropellerISelDag(PropellerTargetMachine &TM) {
  return new PropellerDAGToDAGISelLegacy(TM);
}