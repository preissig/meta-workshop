DESCRIPTION = "Task to install workshop lab exercises to host"
LICENSE = "MIT"
PR = "r0"

# nativesdk must come before packagegroup in the inheritance
inherit nativesdk packagegroup

RDEPENDS_${PN} += "\
     nativesdk-lab10-solution-a \
     " 
