PKG_NAME=relic
PKG_URL=https://github.com/relic-toolkit/relic.git
PKG_VERSION=0b0442a8218df8d309266923f2dd5b9ae3b318ce
PKG_LICENSE=LGPL-2.1

.PHONY: all

CFLAGS += -Wno-gnu-zero-variadic-macro-arguments -Wno-unused-function -Wno-newline-eof

TOOLCHAIN_FILE=$(PKG_BUILDDIR)/xcompile-toolchain.cmake

all: $(PKG_BUILDDIR)/Makefile
	$(MAKE) -C $(PKG_BUILDDIR) && \
	cp $(PKG_BUILDDIR)/lib/librelic_s.a $(BINDIR)/$(PKG_NAME).a

$(PKG_BUILDDIR)/Makefile: $(TOOLCHAIN_FILE)
	cd $(PKG_BUILDDIR) && \
	COMP="$(filter-out -Werror -Werror=old-style-definition -Werror=strict-prototypes -std=gnu99, $(CFLAGS) ) " \
	cmake -DCMAKE_TOOLCHAIN_FILE=$(TOOLCHAIN_FILE) \
		  -DCHECK=off -DTESTS=0 -DBENCH=0 -DSHLIB=off -Wno-dev $(RELIC_CONFIG_FLAGS) .

$(TOOLCHAIN_FILE): git-download
	$(RIOTTOOLS)/cmake/generate-xcompile-toolchain.sh > $(TOOLCHAIN_FILE)

clean::
	@rm -rf $(BINDIR)/$(PKG_NAME).a

include $(RIOTBASE)/pkg/pkg.mk
