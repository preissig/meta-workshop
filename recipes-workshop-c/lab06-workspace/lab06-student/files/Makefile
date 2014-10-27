include ../../../common.make

PROJECT := $(notdir $(shell cd ..;pwd))

# Build rule to invoke bitbake for package
# requires CCS project name to match package name for lab in oe build flow
.phony: all
all: target 

.phony: target
target: ${PROJECT}

SOURCES = $(wildcard usr/src/debug/${PROJECT}/1.0-r0.0/*.c) $(wildcard usr/src/debug/${PROJECT}/1.0-r0.0/*.cpp)
HEADERS = $(wildcard usr/src/debug/${PROJECT}/1.0-r0.0/*.h) $(wildcard usr/src/debug/${PROJECT}/1.0-r0.0/*.hpp)

${PROJECT}: ${SOURCES} ${HEADERS}
	$(CLEAN) $(PROJECT)
	$(BITBAKE) $(PROJECT)
	cp ${TARGET_WORKDIR}/${PROJECT}/1.0-r0.0/package/home/root/workshop/${PROJECT} ./${PROJECT}
	install -d ./.debug 
	cp ${TARGET_WORKDIR}/${PROJECT}/1.0-r0.0/package/home/root/workshop/.debug/${PROJECT} ./.debug/${PROJECT}

.phony: host
host: ${PROJECT}-x86

${PROJECT}-x86: ${SOURCES} ${HEADERS}
	$(CLEAN) $(PROJECT)-native
	$(BITBAKE) $(PROJECT)-native
	cp ${HOST_SYSROOT}/home/user/workshop/${PROJECT} ./${PROJECT}-x86

.phony: clean
clean: clean_target

.phony: clean_target
clean_target:
	$(CLEAN) $(PROJECT)
	rm -f ${PROJECT}
	rm -rf .debug

.phony: clean_host
clean_host:
	$(CLEAN) $(PROJECT)-native
	rm -f ${PROJECT}-x86

