LIB        := libWSFitter.so
VERSION    := 1.2
DISTDIR    := WSFitter-$(VERSION)

SRCS       := WSFitter.h WSFitter.cxx DataPoint.h DataPoint.cxx
EXTRA      := mixing_fit_data.C rootlogon.C

OBJS       := $(patsubst %.cxx, %.o, $(filter %.cxx, $(SRCS) $(DICS)))

PLATFORM   := $(shell root-config --platform)
ROOTCFLAGS := $(shell root-config --cflags)
ROOTLIBS   := $(shell root-config --glibs) -lMinuit

CFLAGS      = -g -fPIC -Wall

ifeq ($(PLATFORM),linux)
SOFLAGS     = -shared
endif

ifeq ($(PLATFORM),macosx)
SOFLAGS     = -dynamiclib -single_module -undefined dynamic_lookup
endif

all: clean $(LIB)

$(LIB): $(LIB).$(VERSION)
	rm -f $@
	ln -sf $< $@

$(LIB).$(VERSION): $(OBJS)
	g++ -o $@ $(OBJS) $(ROOTLIBS) $(SOFLAGS)

%.o: %.cxx %.h
	g++ -o $@ -c $< $(ROOTCFLAGS) $(CFLAGS)

clean:
	@rm -f $(LIB) $(LIB).$(VERSION) $(OBJS) *_C.* *~

dist:
	if [ -d $(DISTDIR) ]; then rm -rf $(DISTDIR); fi
	mkdir $(DISTDIR)
	cp Makefile $(SRCS) $(EXTRA) $(DISTDIR)
	cp -r fitdata $(DISTDIR)
	tar cvfz $(DISTDIR)_`date +%F_%H-%M`.tgz $(DISTDIR)
	rm -rf $(DISTDIR)
