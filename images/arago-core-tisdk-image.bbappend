DEPENDS += " \
	packagegroup-host-workshop-native \
	packagegroup-host-workshop-qt-native \
	"

# Some devices do not support display and use a server image instead
TARGET_IMAGES_k2e-evm = "arago-base-tisdk-image tisdk-server-rootfs-image"
