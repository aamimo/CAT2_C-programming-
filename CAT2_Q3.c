//Cat 2
/* 
Name : Gilberto Amimo Otieno
Course: Bachelor Of Computer Science 
Reg no: CT101/G/26584/25
Description:Program reads, processes, and displays file data
*/

#include <stdio.h>

void write_input();
void process_data();
void show_files();

int main() {
    write_input();
    process_data();
    show_files();
    return 0;
}

void write_input() {
    FILE *f;
    int i, n;

    f = fopen("input.txt", "w");
    if (f == NULL) {
        printf("Error opening input.txt\n");
        return;
    }

    printf("Enter 10 integers:\n");
    for (i = 0; i < 10; i++) {
        printf("Number %d: ", i + 1);
        scanf("%d", &n);
        fprintf(f, "%d ", n);
    }

    fclose(f);
    printf("Numbers saved to input.txt\n\n");
}

void process_data() {
    FILE *in, *out;
    int n, count = 0;
    float sum = 0, avg;

    in = fopen("input.txt", "r");
    if (in == NULL) {
        printf("Error opening input.txt\n");
        return;
    }

    while (fscanf(in, "%d", &n) == 1) {
        sum += n;
        count++;
    }
    fclose(in);

    if (count == 0)
        avg = 0;
    else
        avg = sum / count;

    out = fopen("output.txt", "w");
    if (out == NULL) {
        printf("Error opening output.txt\n");
        return;
    }

    fprintf(out, "Sum = %.2f\n", sum);
    fprintf(out, "Average = %.2f\n", avg);
    fclose(out);

    printf("Sum and average saved to output.txt\n\n");
}

void show_files() {
    FILE *f;
    char c;

    printf("Contents of input.txt:\n");
    f = fopen("input.txt", "r");
    if (f == NULL) {
        printf("Error opening input.txt\n");
        return;
    }
    while ((c = fgetc(f)) != EOF)
        putchar(c);
    fclose(f);

    printf("\n\nContents of output.txt:\n");
    f = fopen("output.txt", "r");
    if (f == NULL) {
        printf("Error opening output.txt\n");
        return;
    }
    while ((c = fgetc(f)) != EOF)
        putchar(c);
    fclose(f);
    printf("\n");
}