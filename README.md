# Transfer-Function

This project contains a C program that calculates and visualizes the Bode plot (magnitude and phase) of a specific electrical circuit transfer function. The program outputs the results to a CSV file, which can then be plotted using gnuplot.

## Overview

The C code (`test.c`) computes the transfer function $G(j\omega) = \frac{R_2}{R_1 + R_2 + j\omega R_1 R_2 C}$. 

The circuit parameters are hardcoded as follows:
*   **R1**: 1000.0 Ohms
*   **R2**: 2000.0 Ohms
*   **C**: 1e-6 Farads (1 µF)

The program calculates 500 logarithmically spaced frequency points ranging from 10 Hz to 1,000,000 Hz (1 MHz). It computes the magnitude in decibels (dB) and the phase in degrees, writing the results to `bode_output.csv`.

## Prerequisites

To build, run, and visualize this project, your environment needs the following tools:
*   **GCC**: The GNU Compiler Collection is used for compiling the C code.
*   **Make**: Used to run the provided Makefile commands.
*   **Gnuplot**: Required for rendering the plot (`gnuplot -p bode_plot.plt`).

## Usage

A `Makefile` is provided to automate the build, execution, and plotting process. 

You can use the following `make` targets from your terminal:

*   **`make all`**: The default command. It builds the executable, runs it to generate the CSV, and plots the results using gnuplot.
*   **`make build`**: Compiles `test.c` into the `transfer_function` executable using the `-O2 -Wall -lm` flags.
*   **`make run`**: Executes the compiled `transfer_function` binary and generates the `bode_output.csv` file.
*   **`make plot`**: Generates the CSV data (via `make run`) and opens the plot using `bode_plot.plt`. *(Note: It exports `QT_QPA_PLATFORM=xcb` for compatibility before running gnuplot).*
*   **`make clean`**: Removes the generated `transfer_function` binary and `bode_output.csv` file to clean up the workspace.

## Project Files

*   `test.c`: The main C source code containing the mathematical logic for the transfer function.
*   `Makefile`: Contains the rules, dependencies, and compiler flags to easily build and run the project.
*   `bode_plot.plt`: The gnuplot script called by the Makefile to visualize the generated CSV data.