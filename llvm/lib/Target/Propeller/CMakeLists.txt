add_llvm_component_group(Propeller)

set(LLVM_TARGET_DEFINITIONS Propeller.td)

tablegen(LLVM PropellerGenInstrInfo.inc -gen-instr-info)
tablegen(LLVM PropellerGenRegisterInfo.inc -gen-register-info)
tablegen(LLVM PropellerGenSubtargetInfo.inc -gen-subtarget)

add_public_tablegen_target(PropellerCommonTableGen)

add_llvm_target(PropellerCodeGen
  PropellerRegisterInfo.cpp
  PropellerSubtarget.cpp
  PropellerTargetMachine.cpp

  LINK_COMPONENTS
  CodeGen
  Core
  Target

  ADD_TO_COMPONENT
  Propeller
)

add_subdirectory(MCTargetDesc)
add_subdirectory(TargetInfo)