DESCRIPTION = "Task to install workshop lab exercises to host"
LICENSE = "MIT"
PR = "r0"

# nativesdk must come before packagegroup in the inheritance
inherit native packagegroup

DEPENDS = "\
     lab03-solution-a-native \
     lab03-student-native \
     lab04-solution-a-native \
     lab04-student-native \
     lab05-solution-a-native \
     lab05-solution-b-native \
     lab05-student-native \
     lab06-solution-a-native \
     lab06-solution-b-native \
     lab06-solution-c-native \
     lab06-student-native \
     lab07-solution-a-native \
     lab07-solution-b-native \
     lab07-solution-c-native \
     lab07-student-native \
     lab08-client-solution-a-native \
     lab08-client-student-native \
     lab08-server-solution-a-native \
     lab08-server-student-native \
     lab09-solution-a-native \
     lab09-solution-b-native \
     lab09-solution-c-native \
     lab09-student-native \
     " 
