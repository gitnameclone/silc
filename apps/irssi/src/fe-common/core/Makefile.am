noinst_LIBRARIES = libfe_common_core.a

include $(top_srcdir)/Makefile.defines.in

INCLUDES += \
	-I$(top_srcdir)/src -I$(top_srcdir)/src/core/ \
	$(GLIB_CFLAGS) \
	-DHELPDIR=\""$(silc_helpdir)"\" \
	-DTHEMESDIR=\""$(silc_etcdir)"\"

libfe_common_core_a_SOURCES = \
	chat-completion.c \
	command-history.c \
	completion.c \
	fe-channels.c \
	fe-common-core.c \
	fe-core-commands.c \
	fe-exec.c \
	fe-expandos.c \
	fe-help.c \
	fe-ignore.c \
	fe-ignore-messages.c \
	fe-log.c \
	fe-messages.c \
	fe-modules.c \
	fe-queries.c \
	fe-server.c \
	fe-settings.c \
	utf8.c \
	wcwidth.c \
	formats.c \
	hilight-text.c \
	keyboard.c \
	module-formats.c \
	printtext.c \
	fe-recode.c \
	themes.c \
	window-activity.c \
	window-commands.c \
	window-items.c \
	windows-layout.c \
	fe-windows.c

noinst_HEADERS = \
	command-history.h \
	chat-completion.h \
	completion.h \
	fe-channels.h \
	fe-common-core.h \
	fe-core-commands.h \
	fe-exec.h \
	fe-messages.h \
	fe-queries.h \
	formats.h \
	hilight-text.h \
	keyboard.h \
	module-formats.h \
	module.h \
	printtext.h \
	fe-recode.h \
	themes.h \
	window-activity.h \
	window-items.h \
	windows-layout.h \
	fe-windows.h \
	utf8.h
