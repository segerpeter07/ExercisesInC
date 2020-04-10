/*
Simple program that reads in a file and counts occurrances of words.
*/
#include <stdio.h>
#include <stdlib.h>
#include <glib.h>
#include <gio/gio.h>


GScanner* openFile(char* filename) {
    GScanner *gScanner = g_scanner_new(NULL);
    FILE * fp;
    gint file;

    fp = fopen (filename, "r+");
    file = fileno(fp);
    g_scanner_input_file(gScanner, file);

    return gScanner;
}

GHashTable* buildHash(GScanner* file_scanner) {
    GHashTable * hash = g_hash_table_new (g_str_hash, g_str_equal);

    while(!g_scanner_eof(file_scanner)){
        g_scanner_get_next_token(file_scanner);
        if(file_scanner->value.v_string){
            if(!g_hash_table_lookup(hash, file_scanner->value.v_string))
                g_hash_table_insert(hash, g_strdup(file_scanner->value.v_string), GINT_TO_POINTER(1));
            else
                g_hash_table_insert(hash, g_strdup(file_scanner->value.v_string), g_hash_table_lookup(hash, file_scanner->value.v_string)+1);
        }
    }

    return hash;
}

void printEntry(gpointer key, gpointer value, gpointer day){
    char *keyChar = key;
    printf("%s: %i\n", keyChar, GPOINTER_TO_INT(value));
}

int main(int argc, char** argv) {
    char* filename = "example_text.txt";
    GScanner* file_scanner = openFile(filename);
    GHashTable* hash_table = buildHash(file_scanner);

    g_hash_table_foreach(hash_table, printEntry, NULL);
    return 0;
}