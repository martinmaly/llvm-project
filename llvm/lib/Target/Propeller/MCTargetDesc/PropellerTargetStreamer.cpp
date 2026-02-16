#include "PropellerTargetStreamer.h"

using namespace llvm;

PropellerTargetStreamer::PropellerTargetStreamer(MCStreamer &S)
    : MCTargetStreamer(S) {}

PropellerTargetAsmStreamer::PropellerTargetAsmStreamer(
    MCStreamer &S, formatted_raw_ostream &OS)
    : PropellerTargetStreamer(S), OS(OS) {}

PropellerTargetELFStreamer::PropellerTargetELFStreamer(
    MCStreamer &S, const MCSubtargetInfo &STI)
    : PropellerTargetStreamer(S) {}