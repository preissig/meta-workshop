DESCRIPTION = "Task to install workshop lab exercises to target"
LICENSE = "MIT"
PR = "r0"

inherit packagegroup

PACKAGE_ARCH = "${MACHINE_ARCH}"

RDEPENDS_${PN} = "\
     lab10-solution-a \
     lab10-student \
     " 
