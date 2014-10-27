INCBASENAME = "${@bb.data.getVar('PN',d,1).replace('nativesdk-','')}"

require ${INCBASENAME}_${PV}.inc

DEPENDS += "nativesdk-qt4-tools"
RDEPENDS_${PN} += "nativesdk-qt4-tools"

do_configure[depends] = "nativesdk-qt4-tools:do_mylibs"

# override MYBASENAME from include file
# have to include nativesdk to differentiate from native builds
MYBASENAME = "${INCBASENAME}"

PR="${INC_PR}.0"

# tell bitbake to build this for the x86 to be included in sdk
# have to use native and install manually because nativesdk for qt4 is not meant for building qt-based nativesdk applications it is meant for building qt to be inserted into the nativesdk
inherit nativesdk qmake2


