#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// --- Data Structures ---
// To hold the Opcode Table (OPTAB) in memory for fast lookups.
typedef struct {
    char opcode[10];
    char hexcode[10];
} OptabLine;

// To hold the Symbol Table (SYMTAB) in memory for fast lookups.
typedef struct {
    char label[10];
    int addr;
} SymtabLine;

// --- Main Assembler Logic ---
int main() {
    // --- File Pointers & Data ---
    FILE *f_input, *f_optab, *f_inter, *f_symtab, *f_len;
    OptabLine OT[30];   // Array to store OPTAB
    SymtabLine ST[30];  // Array to store SYMTAB
    int locctr, start_addr, prog_len, o_count = 0, s_count = 0;
    char label[20], opcode[20], operand[20], line[100];

    // --- 1. Open all necessary files ---
    f_input = fopen("input.txt", "r");
    f_optab = fopen("optab.txt", "r");
    f_inter = fopen("intermediate.txt", "w");
    f_symtab = fopen("symtab.txt", "w");
    f_len = fopen("length.txt", "w");

    if (f_input == NULL || f_optab == NULL || f_inter == NULL || f_symtab == NULL || f_len == NULL) {
        printf("Error: Could not open one or more files. Exiting.\n");
        return 1;
    }

    // --- 2. Load OPTAB into memory for efficiency ---
    while (fscanf(f_optab, "%s %s", OT[o_count].opcode, OT[o_count].hexcode) != EOF) {
        o_count++;
    }
    fclose(f_optab); // Close after reading

    // --- 3. Handle START directive ---
    fgets(line, sizeof(line), f_input);
    sscanf(line, "%s %s %s", label, opcode, operand);

    if (strcmp(opcode, "START") == 0) {
        start_addr = (int)strtol(operand, NULL, 16); // Convert hex string to int
        locctr = start_addr;
        fprintf(f_inter, "\t%s\t%s\t%s\n", label, opcode, operand);
    } else {
        locctr = 0;
        start_addr = 0;
    }

    // --- 4. Process each line of the input file ---
    while (fgets(line, sizeof(line), f_input) != NULL) {
        // Default to no label, opcode, or operand
        strcpy(label, "**"); 
        strcpy(opcode, ""); 
        strcpy(operand, "");

        // Parse the line robustly
        int items_read = sscanf(line, "%s %s %s", label, opcode, operand);
        if (items_read == 1) { // e.g., RSUB
            strcpy(opcode, label);
            strcpy(label, "**");
        } else if (items_read == 2) { // e.g., LDA FIVE
            strcpy(operand, opcode);
            strcpy(opcode, label);
            strcpy(label, "**");
        }

        if (strcmp(opcode, "END") == 0) break; // Exit loop if END is found

        // --- A. If there is a symbol, process it ---
        if (strcmp(label, "**") != 0) {
            // Search SYMTAB for the label
            int found_in_symtab = 0;
            for (int i = 0; i < s_count; i++) {
                if (strcmp(ST[i].label, label) == 0) {
                    printf("Error: Duplicate symbol '%s' found.\n", label);
                    found_in_symtab = 1;
                    break;
                }
            }
            // If not found, add it to SYMTAB
            if (!found_in_symtab) {
                strcpy(ST[s_count].label, label);
                ST[s_count].addr = locctr;
                s_count++;
            }
        }

        // Write line to intermediate file before incrementing locctr
        fprintf(f_inter, "%X\t%s\t%s\t%s\n", locctr, label, opcode, operand);

        // --- B. Increment locctr based on opcode ---
        int found_in_optab = 0;
        for (int i = 0; i < o_count; i++) {
            if (strcmp(opcode, OT[i].opcode) == 0) {
                locctr += 3;
                found_in_optab = 1;
                break;
            }
        }

        if (!found_in_optab) {
            if (strcmp(opcode, "WORD") == 0) locctr += 3;
            else if (strcmp(opcode, "RESW") == 0) locctr += (3 * atoi(operand));
            else if (strcmp(opcode, "RESB") == 0) locctr += atoi(operand);
            else if (strcmp(opcode, "BYTE") == 0) {
                if (operand[0] == 'X') locctr += (strlen(operand) - 3) / 2;
                else if (operand[0] == 'C') locctr += strlen(operand) - 3;
            } else {
                printf("Error: Invalid opcode '%s'.\n", opcode);
            }
        }
    }

    // --- 5. Write final line and calculate program length ---
    fprintf(f_inter, "\t%s\t%s\t%s\n", label, opcode, operand);
    prog_len = locctr - start_addr;

    // --- 6. Write SYMTAB from memory to file ---
    for (int i = 0; i < s_count; i++) {
        fprintf(f_symtab, "%s\t%X\n", ST[i].label, ST[i].addr);
    }

    // --- 7. Write program length to file ---
    fprintf(f_len, "%X\n", prog_len);

    // --- 8. Close all files and print summary ---
    fclose(f_input);
    fclose(f_inter);
    fclose(f_symtab);
    fclose(f_len);

    printf("Pass 1 successful.\n");
    printf("Program length: %X\n", prog_len);

    return 0;
}

