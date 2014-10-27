DESCRIPTION = "Task to install workshop lab exercises to target"
LICENSE = "MIT"
PR = "r0"

inherit packagegroup

PACKAGE_ARCH = "${MACHINE_ARCH}"

RDEPENDS_${PN} = "\
     lab03-solution-a \
     lab03-student \
     lab04-solution-a \
     lab04-student \
     lab05-solution-a \
     lab05-solution-b \
     lab05-student \
     lab06-solution-a \
     lab06-solution-b \
     lab06-solution-c \
     lab06-student \
     lab07-solution-a \
     lab07-solution-b \
     lab07-solution-c \
     lab07-student \
     lab08-client-solution-a \
     lab08-client-student \
     lab08-server-solution-a \
     lab08-server-student \
     lab09-solution-a \
     lab09-solution-b \
     lab09-solution-c \
     lab09-student \
     " 
