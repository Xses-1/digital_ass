FROM ghcr.io/void-linux/void-musl
RUN xbps-install -Syu \
		cross-arm-none-eabi-gcc \
		cross-arm-none-eabi-binutils \
		cross-arm-none-eabi-libstdc++ \
		cross-arm-none-eabi-newlib \
	&& \
	:
WORKDIR /pwd

