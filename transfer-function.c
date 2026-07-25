#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define constants
#define R1 1000.0     // Ohms
#define R2 2000.0     // Ohms
#define C  1e-6       // Farads
#define POINTS 500

int main() 
{
    FILE *fp = fopen("bode_output.csv", "w");
    if (!fp) {
        perror("File open failed");
        return 1;
    }

    fprintf(fp, "Frequency(Hz),Magnitude(dB),Phase(deg)\n");

    // Logarithmically spaced frequencies from 10 to 1,000,000 Hz
    double f_start = 10;
    double f_end = 1e6;

    for (int i = 0; i < POINTS; i++) {
        double frac = (double)i / (POINTS - 1);
        double freq = f_start * pow(f_end / f_start, frac);
        double omega = 2 * M_PI * freq;

        // Compute transfer function G(jw) = R2 / (R1 + R2 + j*w*R1*R2*C)
        double denom_re = R1 + R2;
        double denom_im = omega * R1 * R2 * C;

        double mag = R2 / sqrt(denom_re * denom_re + denom_im * denom_im);
        double phase = -atan2(denom_im, denom_re) * (180.0 / M_PI);

        double mag_db = 20 * log10(mag);

        fprintf(fp, "%.2f,%.2f,%.2f\n", freq, mag_db, phase);
    }

    fclose(fp);
    printf("Results written to bode_output.csv\n");
    return 0;
}
