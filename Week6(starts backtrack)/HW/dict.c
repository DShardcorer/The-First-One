#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 50
#define MAX_MEANING_LEN 100

typedef struct {
    char word[MAX_WORD_LEN];
    char meaning[MAX_MEANING_LEN];
} DictionaryEntry;

int main() {
    FILE *fp_in, *fp_out;
    char word[MAX_WORD_LEN], meaning[MAX_MEANING_LEN];
    DictionaryEntry entry;
    int begin, end, num_entries = 0;

    // Open input file
    fp_in = fopen("vnedict.txt", "r");
    if (fp_in == NULL) {
        printf("Failed to open input file.\n");
        return 1;
    }

    // Count number of entries in file
    while (fgets(word, MAX_WORD_LEN, fp_in) != NULL) {
        fgets(meaning, MAX_MEANING_LEN, fp_in);
        num_entries++;
    }
    rewind(fp_in);

    // Open output file and write number of entries
    fp_out = fopen("vnedict.dat", "wb");
    fwrite(&num_entries, sizeof(int), 1, fp_out);

    // Write entries to output file
    while (fgets(word, MAX_WORD_LEN, fp_in) != NULL) {
        fgets(meaning, MAX_MEANING_LEN, fp_in);

        // Remove newline characters from word and meaning
        word[strcspn(word, "\n")] = '\0';
        meaning[strcspn(meaning, "\n")] = '\0';

        // Copy word and meaning to entry and write to output file
        strcpy(entry.word, word);
        strcpy(entry.meaning, meaning);
        fwrite(&entry, sizeof(DictionaryEntry), 1, fp_out);
    }

    // Close input and output files
    fclose(fp_in);
    fclose(fp_out);

    // Ask user for range of words to display
    printf("Enter the range of words to display (begin end): ");
    scanf("%d %d", &begin, &end);

    // Open binary file and display words in specified range
    fp_in = fopen("vnedict.dat", "rb");
    if (fp_in == NULL) {
        printf("Failed to open input file.\n");
        return 1;
    }

    // Read number of entries and skip to first word in range
    fread(&num_entries, sizeof(int), 1, fp_in);
    fseek(fp_in, (begin - 1) * sizeof(DictionaryEntry), SEEK_CUR);

    // Display words in range
    for (int i = begin; i <= end && i <= num_entries; i++) {
        fread(&entry, sizeof(DictionaryEntry), 1, fp_in);
        printf("%s: %s\n", entry.word, entry.meaning);
    }

    // Close input file
    fclose(fp_in);

    return 0;
}
