#include <stdio.h>

int main(void)
{
    FILE *inp;              /* pointer to input file */
    FILE *outp;             /* pointer to output file */
    double item;
    int input_status;       /* status value return by fscanf */

    /* Prepare files for input or output */
    inp = fopen("indata.txt", "r");
    outp = fopen("outdata.txt", "w");

    /* Read each item, format it, and write it */
    /* fscanf�������ض���������ĸ���, ���߷���һ������(EOF), ��ʾ��⵽�ļ��ַ��Ľ�����־ */
    input_status = fscanf(inp, "%lf", &item);
    while(input_status == 1) {
        fprintf(outp, "%.2f\n", item);
        input_status = fscanf(inp, "%lf", &item);
    }
    /* Close the files */
    fclose(inp);
    fclose(outp);


    return 0;
}
