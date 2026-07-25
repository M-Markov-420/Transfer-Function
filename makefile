# Compiler and flags
CC = gcc
CFLAGS = -O2 -Wall -lm

# Files
SRC = transfer-function.c
BIN = transfer_function
CSV = bode_output.csv
PLOT = bode_plot.plt

# Explicit "all": build, run, and plot everything
all: build run plot

# Build only
build: $(SRC)
	$(CC) $(CFLAGS) -o $(BIN) $(SRC)

# Run and generate CSV data
run: build
	./$(BIN)

# Plot using gnuplot
plot: run
	export QT_QPA_PLATFORM=xcb && gnuplot -p $(PLOT)

# Clean all generated files
clean:
	rm -f $(BIN) $(CSV)

.PHONY: all build run plot clean
