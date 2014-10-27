INCBASENAME = "${@bb.data.getVar('PN',d,1).replace('nativesdk-','')}"

require ${INCBASENAME}_${PV}.inc

# override MYBASENAME from include file
MYBASENAME = "${INCBASENAME}"

PR="${INC_PR}.0"

# tell bitbake to build this for the x86 to be included in sdk
inherit nativesdk





