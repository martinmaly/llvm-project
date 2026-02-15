#include "Propeller.h"

namespace clang {
namespace targets {

PropellerTargetInfo::PropellerTargetInfo(const llvm::Triple &Triple,
                                         const TargetOptions &)
    : TargetInfo(Triple) {
  resetDataLayout();
}

void PropellerTargetInfo::getTargetDefines(const LangOptions &Opts,
                                           MacroBuilder &Builder) const {}

llvm::SmallVector<Builtin::InfosShard>
PropellerTargetInfo::getTargetBuiltins() const {
  return {};
}

TargetInfo::BuiltinVaListKind
PropellerTargetInfo::getBuiltinVaListKind() const {
  return TargetInfo::VoidPtrBuiltinVaList;
}

bool PropellerTargetInfo::validateAsmConstraint(
    const char *&Name, TargetInfo::ConstraintInfo &info) const {
  return false; // TODO: Implement
}

std::string_view PropellerTargetInfo::getClobbers() const {
  return ""; // TODO: Implement
}

ArrayRef<const char *> PropellerTargetInfo::getGCCRegNames() const {
  return {}; // TODO: Implement
}
ArrayRef<TargetInfo::GCCRegAlias>
PropellerTargetInfo::getGCCRegAliases() const {
  return {}; // TODO: Implement
}

} // namespace targets
} // namespace clang