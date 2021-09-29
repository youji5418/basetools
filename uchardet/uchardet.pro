CONFIG -= qt

TEMPLATE = lib
DEFINES += UCHARDET_LIBRARY

INCLUDEPATH += include/


target.path = $$PWD/lib/

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/CharDistribution.cpp \
    src/JpCntx.cpp \
    src/LangBulgarianModel.cpp \
    src/LangCyrillicModel.cpp \
    src/LangCzechModel.cpp \
    src/LangFinnishModel.cpp \
    src/LangFrenchModel.cpp \
    src/LangGermanModel.cpp \
    src/LangGreekModel.cpp \
    src/LangHebrewModel.cpp \
    src/LangHungarianModel.cpp \
    src/LangPolishModel.cpp \
    src/LangSpanishModel.cpp \
    src/LangSwedishModel.cpp \
    src/LangThaiModel.cpp \
    src/LangTurkishModel.cpp \
    src/nsBig5Prober.cpp \
    src/nsCharSetProber.cpp \
    src/nsEUCJPProber.cpp \
    src/nsEUCKRProber.cpp \
    src/nsEUCTWProber.cpp \
    src/nsEscCharsetProber.cpp \
    src/nsEscSM.cpp \
    src/nsGB2312Prober.cpp \
    src/nsHebrewProber.cpp \
    src/nsLatin1Prober.cpp \
    src/nsMBCSGroupProber.cpp \
    src/nsMBCSSM.cpp \
    src/nsSBCSGroupProber.cpp \
    src/nsSBCharSetProber.cpp \
    src/nsSJISProber.cpp \
    src/nsUTF8Prober.cpp \
    src/nsUniversalDetector.cpp \
    src/ucdapi.cpp \
    uchardet.cpp

HEADERS += \
    include/libucd.h \
    src/CharDistribution.h \
    src/JpCntx.h \
    src/nsBig5Prober.h \
    src/nsCharSetProber.h \
    src/nsCodingStateMachine.h \
    src/nsDebug.h \
    src/nsEUCJPProber.h \
    src/nsEUCKRProber.h \
    src/nsEUCTWProber.h \
    src/nsEscCharsetProber.h \
    src/nsGB2312Prober.h \
    src/nsHebrewProber.h \
    src/nsLatin1Prober.h \
    src/nsMBCSGroupProber.h \
    src/nsPkgInt.h \
    src/nsSBCSGroupProber.h \
    src/nsSBCharSetProber.h \
    src/nsSJISProber.h \
    src/nsUTF8Prober.h \
    src/nsUniversalDetector.h \
    src/nscore.h \
    src/prmem.h \
    uchardet_global.h \
    uchardet.h

# Default rules for deployment.

!isEmpty(target.path): INSTALLS += target

message($$target.path)

DISTFILES += \
    src/Big5Freq.tab \
    src/EUCKRFreq.tab \
    src/EUCTWFreq.tab \
    src/GB2312Freq.tab \
    src/JISFreq.tab

message("uchardet combile")
message("PWD=")
message($$PWD)
message("OUT_PWD=")
message($$OUT_PWD)
message("_PRO_FILE_=")
message($$_PRO_FILE_)
message("_PRO_FILE_PWD_=")
message($$_PRO_FILE_PWD_)
