#include "tinylang/Basic/Diagnostic.h"

using namespace tinylang;

namespace {
    const char *DiagnosticText[] = {
#define DIAG(ID, Level, Msg) Msg,
#include "tinylang/Basic/Diagnostic.def"
    };

    SourceMgr::DiagKind DiagnosticKind[] = {
#define DIAG(ID, Level, Msg) SourceMgr::DK_##Level,
#include "tinylang/Basic/Diagnostic.def"
    };
} // namespace

const char *DiagnosticEngine::getDiagnosticText(unsigned DiagID) {
    return DiagnosticText[DiagID];
}

SourceMgr::DiagKind DiagnosticEngine::getDiagnosticKind(unsigned DiagID) {
    return DiagnosticKind[DiagID];
}