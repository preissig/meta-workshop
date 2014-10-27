TARGET := am335x-evm

OE-BUILD-DIR := ${PWD}/../../../../../../build


BITBAKE := cd $(OE-BUILD-DIR); source conf/setenv; MACHINE=$(TARGET) bitbake 

CLEAN := cd $(OE-BUILD-DIR); source conf/setenv; MACHINE=$(TARGET) bitbake -c cleansstate

TARGET_WORKDIR := $(OE-BUILD-DIR)/arago-tmp-external-linaro-toolchain/work/cortexa8hf-vfp-neon-3.8-oe-linux-gnueabi
HOST_SYSROOT := $(OE-BUILD-DIR)/arago-tmp-external-linaro-toolchain/sysroots/i686-linux

