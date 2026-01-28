add_llvm_component_library(LLVMPropellerInfo
  PropellerTargetInfo.cpp

  LINK_COMPONENTS
  MC
  Support

  ADD_TO_COMPONENT
  Propeller
  )
