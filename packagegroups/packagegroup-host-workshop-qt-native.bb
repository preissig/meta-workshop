DESCRIPTION = "Task to install workshop lab exercises to host"
LICENSE = "MIT"
PR = "r0"

# nativesdk must come before packagegroup in the inheritance
inherit native packagegroup

DEPENDS = "\
     lab10-solution-a-native \
     lab10-student-native \
     " 
