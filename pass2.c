#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Declare all variables and structures globally
char label[20], opcode[20], operand[20], T_opcode[10];
char prog_name[20], obj_code[20], text_record[100], temp_obj_code[20];
int start_addr, locctr, prog_len, text_len = 0, text_start_addr, op_addr, flag;

// File pointers for input and output files
FILE *intermed_fp, *symtab_fp, *optab_fp, *obj_fp, *len_fp;

// Structure for Symbol Table
struct SYMTAB {
    char label[20];
    int addr;
} ST[30];

// Structure for Opcode Table
struct OPTAB {
    char opcode[20];
    char hexcode[10];
} OT[30];

int sym_count = -1; // To count symbols in SYMTAB
int op_count = -1;  // To count opcodes in OPTAB

// Function to read the symbol table from file into the structure
void read_symtab() {
    while (1) {
        sym_count++;
        fscanf(symtab_fp, "%s%x", ST[sym_count].label, &ST[sym_count].addr);
        if (getc(symtab_fp) == EOF) break;
    }
}

// Function to read the opcode table from file into the structure
void read_optab() {
    while (1) {
        op_count++;
        fscanf(optab_fp, "%s%s", OT[op_count].opcode, OT[op_count].hexcode);
        if (getc(optab_fp) == EOF) break;
    }
}

int main() {
    int i;

    // Open all the necessary files
    intermed_fp = fopen("intermed.txt", "r");
    symtab_fp = fopen("symtab.txt", "r");
    optab_fp = fopen("optab.txt", "r");
    len_fp = fopen("length.txt", "r");
    obj_fp = fopen("object.txt", "w");

    // Read SYMTAB and OPTAB into their respective structures
    read_symtab();
    read_optab();

    // Read the program length from length.txt
    fscanf(len_fp, "%x", &prog_len);

    // Read the first line of the intermediate file (START directive)
    fscanf(intermed_fp, "%s%s%x", label, opcode, &start_addr);
    strcpy(prog_name, label); // Get the program name
    locctr = start_addr;

    // Write the Header record to the object file
    fprintf(obj_fp, "H^%-6s^%06X^%06X\n", prog_name, start_addr, prog_len);

    // Initialize the first Text record
    text_start_addr = locctr;
    strcpy(text_record, "");

    // Read the next line from the intermediate file
    fscanf(intermed_fp, "%x%s%s%s", &locctr, label, opcode, operand);

    // Process the file until the END directive is found
    while (strcmp(opcode, "END") != 0) {
        flag = 0;
        // Search OPTAB for the opcode
        for (i = 0; i <= op_count; i++) {
            if (strcmp(opcode, OT[i].opcode) == 0) {
                strcpy(T_opcode, OT[i].hexcode); // Get the hex code for the opcode
                flag = 1;
                break;
            }
        }

        if (flag) { // If opcode is found in OPTAB
            flag = 0;
            // Search SYMTAB for the operand
            for (i = 0; i <= sym_count; i++) {
                if (strcmp(operand, ST[i].label) == 0) {
                    op_addr = ST[i].addr; // Get the address of the symbol
                    flag = 1;
                    break;
                }
            }

            if (flag) {
                sprintf(obj_code, "%s%X", T_opcode, op_addr); // Form the object code
            } else {
                // Handle cases where the operand is not in SYMTAB (e.g., indexed addressing)
                // For simplicity, we assume an error or a default 0000 address
                if(strstr(operand, ",X") != NULL) {
                    char temp_operand[20];
                    strncpy(temp_operand, operand, strlen(operand) - 2);
                    temp_operand[strlen(operand) - 2] = '\0';
                     for (i = 0; i <= sym_count; i++) {
                        if (strcmp(temp_operand, ST[i].label) == 0) {
                           op_addr = ST[i].addr + 0x8000; // Add indexing bit
                           break;
                        }
                    }
                } else {
                     op_addr = 0; // Symbol not found, set address to 0000
                }
                sprintf(obj_code, "%s%04X", T_opcode, op_addr);
            }
        } else if (strcmp(opcode, "WORD") == 0) {
            // Handle WORD directive
            sprintf(obj_code, "%06X", atoi(operand));
        } else if (strcmp(opcode, "BYTE") == 0) {
            // Handle BYTE directive
            strcpy(obj_code, "");
            if (operand[0] == 'C') { // For character constants like C'EOF'
                for (i = 2; i < strlen(operand) - 1; i++) {
                    sprintf(temp_obj_code, "%02X", operand[i]);
                    strcat(obj_code, temp_obj_code);
                }
            } else if (operand[0] == 'X') { // For hex constants like X'F1'
                for (i = 2; i < strlen(operand) - 1; i++) {
                     sprintf(temp_obj_code, "%c", operand[i]);
                     strcat(obj_code, temp_obj_code);
                }
            }
        } else {
            // For RESW and RESB, no object code is generated
            strcpy(obj_code, "");
        }
        
        // Check if the new object code can fit into the current Text record
        if ((strlen(text_record) + strlen(obj_code)) > 60 || strcmp(obj_code, "") == 0) {
            if (strlen(text_record) > 0) {
                // Write the current Text record to the object file
                text_len = strlen(text_record) / 2;
                fprintf(obj_fp, "T^%06X^%02X^%s\n", text_start_addr, text_len, text_record);
            }
            // Start a new Text record for RESW/RESB or if the record is full
            if (strcmp(obj_code, "") != 0) {
                 strcpy(text_record, obj_code);
                 text_start_addr = locctr;
            } else {
                strcpy(text_record, "");
            }

        } else {
            strcat(text_record, obj_code);
        }

        // Read the next line from the intermediate file
        fscanf(intermed_fp, "%x%s%s%s", &locctr, label, opcode, operand);
    }

    // Write the last Text record if it's not empty
    if (strlen(text_record) > 0) {
        text_len = strlen(text_record) / 2;
        fprintf(obj_fp, "T^%06X^%02X^%s\n", text_start_addr, text_len, text_record);
    }

    // Find the address of the first executable instruction for the End record
    int first_exec_addr = 0;
    for(i=0; i<=sym_count; i++) {
        if(strcmp(operand, ST[i].label) == 0) {
            first_exec_addr = ST[i].addr;
            break;
        }
    }
    
    // Write the End record
    fprintf(obj_fp, "E^%06X\n", first_exec_addr);

    // Close all file pointers
    fclose(intermed_fp);
    fclose(symtab_fp);
    fclose(optab_fp);
    fclose(len_fp);
    fclose(obj_fp);
    
    printf("Object program 'object.txt' has been generated successfully.\n");

    return 0;
}
