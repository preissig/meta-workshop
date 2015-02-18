DESCRIPTION = "Task to install workshop lab exercises to host"
LICENSE = "MIT"
PR = "r0"

# nativesdk must come before packagegroup in the inheritance
inherit nativesdk packagegroup

RDEPENDS_${PN} += "\
     nativesdk-lab04-solution-a \
     nativesdk-lab05-solution-a \
     nativesdk-lab05-solution-b \
     nativesdk-lab06-solution-a \
     nativesdk-lab06-solution-b \
     nativesdk-lab06-solution-c \
     nativesdk-lab07-solution-a \
     nativesdk-lab07-solution-b \
     nativesdk-lab07-solution-c \
     nativesdk-lab08-client-solution-a \
     nativesdk-lab08-server-solution-a \
     nativesdk-lab09-solution-a \
     nativesdk-lab09-solution-b \
     nativesdk-lab09-solution-c \
     " 
