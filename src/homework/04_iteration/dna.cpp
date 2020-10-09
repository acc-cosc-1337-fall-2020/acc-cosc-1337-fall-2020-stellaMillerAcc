#include "dna.h"
/*
Write code for function get_gc_content that accepts
a const reference string parameter and returns a double.
Calculate GC content:
Iterate string count Gs and Cs, divide count by string length.
Return quotient.
*/
double get_gc_content(const string& dna) {
    int count = 0;

    for (unsigned int i = 0; i < dna.length(); i++) {
        if (dna[i] == 'C' || dna[i] == 'G') {
            count++;
        }
    }

    return (double)count/dna.length();
}
/*
Write code for function get_reverse_string that
accepts a string parameter and returns a string reversed.
*/
string get_reverse_string(string dna) {
    for (unsigned int i = 0; i < dna.length()/2; i++) {
        char temp;
        temp = dna[i];
        dna[i] = dna[dna.length()-i-1];
        dna[dna.length()-i-1] = temp;
    }

    return dna;
}
/*
Write prototype for function get_dna_complement that
accepts a string dna and returns a string.
Calculate dna complement:
a. call function get_reverse_string(dna), save results to a local string variable
b. iterate local string variable and
    replace A with T, T with A, C with G and G with C
c. return string
*/
string get_dna_complement(string dna) {
    string reverse = get_reverse_string(dna);

    for (unsigned int i = 0; i < reverse.length(); i++) {
        switch (reverse[i])
        {
        case 'A':
            reverse[i] = 'T';
            break;
        case 'T':
            reverse[i] = 'A';
            break;
        case 'G':
            reverse[i] = 'C';
            break;
        case 'C':
            reverse[i] = 'G';
            break;
        default:
            break;
        }
    }
    return reverse;
}

