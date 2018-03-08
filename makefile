CC = gcc
CFLAGS = -lm

SOURCEDIR = src
BUILDDIR = build

EXECUTABLE = manta-ray
SOURCES=$(wildcard $(SOURCEDIR)/*.c)

all: dir $(BUILDDIR)/$(EXECUTABLE)

dir:
	mkdir -p $(BUILDDIR)

$(BUILDDIR)/$(EXECUTABLE): $(SOURCES)
	$(CC) -o $(BUILDDIR)/$(EXECUTABLE) $^ $(CFLAGS) $(LIBS)

clean:
	rm -f $(BUILDDIR)/*.o $(BUILDDIR)/$(EXECUTABLE)